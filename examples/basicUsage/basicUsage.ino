#include <AdafruitIO_WiFi.h>
#include <Keypad.h>

/* set your WiFi and Adafruit IO information in this file */
#include "config.h"

#define PIN_ONBOARD_LED 2

/* init Adafruit IO */
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/* setup the feed */
AdafruitIO_Feed *status = io.feed("status");

const byte ROWS = 4;
const byte COLS = 3;
char keys[ROWS][COLS] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'},
    {'*','0','#'}
};

byte rowPins[ROWS] = {14, 12, 13, 16}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 5, 4}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
    /* start Serial */
    Serial.begin(9600);

    /* setup the blue LED */
    pinMode(PIN_ONBOARD_LED, OUTPUT);

    /* connect to Adafruit IO */
    connectToIO();

    /* setup the keypad */
    keypad.addEventListener(keypadEvent);
}

void loop() {
    /* keep our connection up */
    if (io.status() < AIO_CONNECTED) {
        connectToIO();
    }

    /* call run on IO and the statusIndicator */
    io.run();

    char key = keypad.getKey();

    if (key) {
        Serial.println("key is " + key);
    }
}

void connectToIO() {
    Serial.println("Connecting to Adafruit IO...");
    
    // Set the WiFi to station mode
    WiFi.mode(WIFI_STA);
    
    io.connect();

    // set a flag for toggling the LED
    boolean isOn = true;

    // wait for the connection
    while (io.status() < AIO_CONNECTED) {
        Serial.print(".");
        isOn = !isOn;
        digitalWrite(PIN_ONBOARD_LED, isOn);
        delay(500);
    }

    // connected!
    Serial.println("Connected to Adafruit IO!");
    Serial.println(io.statusText());

    // keep the blue LED on
    digitalWrite(PIN_ONBOARD_LED, LOW);
}

void keypadEvent(KeypadEvent key) {

    switch (keypad.getState()) {
        case PRESSED:
            {
                int statusValue = 1;
                switch (key) {
                    case '1':
                        statusValue = 1;
                        break;
                    case '2':
                        statusValue = 2;
                        break;
                    case '3':
                        statusValue = 3;
                        break;
                    case '4':
                        statusValue = 4;
                        break;
                    case '5':
                        statusValue = 5;
                        break;
                    case '6':
                        statusValue = 6;
                        break;
                    case '7':
                        statusValue = 7;
                        break;
                    case '8':
                        statusValue = 99;
                        break;
                    case '9':
                        statusValue = 97;
                        break;
                    case '*':
                        statusValue = 98;
                        break;
                    case '0':
                        statusValue = 96;
                        break;
                    case '#':
                        // There are only 11 statuses so just make this one 96 as well.
                        statusValue = 96;
                        break;
                    default:
                        statusValue = 1;
                        break;
                }
                status->save(statusValue);
            }
            break;
        case RELEASED:
            break;
        case HOLD:
            break;
    }
}
