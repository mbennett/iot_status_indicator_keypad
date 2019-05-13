# iot_status_indicator_keypad
Keypad to change the status of the iot_status_indicator

# IOT Status Indicator Keypad
Complimentary keypad IoT device to the [IoT Status Indicator][LINK_IOT_STATUS_INDICATOR] written by Scott Linenberger.

## What You'll Need  
You'll need the [Arduino Code Editor][LINK_ARDUINO_IDE] or "IDE" (Integraged Development Environment). You'll also need an [Adafruit IO][LINK_IO] account and an Adafruit IO compatible WiFi board (I like the [Adafruit Feather Huzzah][LINK_PRODUCT_FEATHER_HUZZAH] or Huzzah Breakout with ESP8266). Lastly, you'll need a Membrane 3x4 Matrix Keypad (The basic usage example uses an [Adafruit Membrane 3x4 Matrix Keypad][LINK_PRODUCT_MATRIX_KEYPAD]).

This guide assumes you are using an [Adafruit Feather Huzzah][LINK_PRODUCT_FEATHER_HUZZAH] and a [Adafruit Membrane 3x4 Matrix Keypad][LINK_PRODUCT_MATRIX_KEYPAD]. Again, you don't _have_ to use these components, but these components have been thorougly tested with the IOT Status Indicator Keypad library.

### Adafruit IO  
You'll need an [Adafruit IO][LINK_IO] account. Please see [Scott's repository][LINK_IOT_STATUS_INDICATOR] for details.

## State Values  
The IOT Status Indicator uses numeric values to represent each state. Here are a list of the states you can use with an AdafruitIO feed for the IOT Status Indicator. 

|Numeric Value |LEDs                   |Keypad|
|--------------|-----------------------|------|
|1             |Solid Green            |1     |
|2             |Solid Yellow           |2     |
|3             |Solid Blue             |3     |
|4             |Solid Purple           |4     |
|5             |Solid Red              |5     |
|6             |Pulsing Green          |6     |
|7             |Pulsing Red            |7     |
|96            |Animation Fire         |8     |
|97            |Animation Police       |9     |
|98            |Animation Cycle Colors |*     |
|99            |Animation Party        |0     |

## Components  
Here is a complete list of the components used for the sample IOT Status Indicator example.

* [Adafruit Feather Huzzah][LINK_PRODUCT_FEATHER_HUZZAH] - [Learn About the Feather Huzzah][LINK_LEARN_FEATHER_HUZZAH]
* [Adafruit Membrane 3x4 Matrix Keypad][LINK_PRODUCT_MATRIX_KEYPAD]
* Breadboard - [Learn About Breadboards][LINK_LEARN_BREADBOARD]

## WIRING THE IOT STATUS INDICATOR KEYPAD
TODO 


## Additional Libraries  
TODO

## Using the IOT Status Indicator Keypad Library  
TODO

**Important:** make sure you have downloaded the additional libraries mentioned above! Without them, the IOT Status Indicator library will not compile.

Once you've added the library, you can open the usage example by using  
`File -> Examples -> iot_status_indicator_keypad-<version> -> basicUsage`  

In the example, set the values for the following variables  
```
#define IO_USERNAME ""
#define IO_KEY ""
#define WIFI_SSID ""
#define WIFI_PASS ""
```
`IO_USERNAME` and `IO_KEY` need to come from your AdafruitIO account and `WIFI_SSID` and `WIFI_PASS` are your WiFi credentials. To find your Adafruit IO click on the yellow text that says "View AIO Key" on the Adafruit IO main page after you've logged in.

![Viewing your IO Key](./images/io_view_aio_key.png)


[LINK_ARDUINO_IDE]: https://www.arduino.cc/en/Main/Software
[LINK_IO]: https://io.adafruit.com
[LINK_LEARN_IO]: https://learn.adafruit.com/adafruit-io/overview
[LINK_LEARN_NEOPIXELS]: https://learn.adafruit.com/adafruit-neopixel-uberguide/the-magic-of-neopixels?gclid=CjwKCAjwkYDbBRB6EiwAR0T_-mV0nic2zRmePrLDyuMCpvNuCJgbRTAAsS1rv5KyqeieUQSczDapPxoCP04QAvD_BwE
[LINK_LEARN_BREADBOARD]: https://learn.adafruit.com/breadboards-for-beginners?view=all
[LINK_PRODUCT_FEATHER_HUZZAH]: https://www.adafruit.com/product/2821
[LINK_PRODUCT_LEVEL_SHIFTER]: https://www.adafruit.com/product/1875
[LINK_PRODUCT_NEOPIXEL_STICK]: https://www.adafruit.com/product/1426
[LINK_LEARN_FEATHER_HUZZAH]: https://learn.adafruit.com/adafruit-feather-huzzah-esp8266?view=all
[LIBRARY_ADAFRUIT_NEOPIXEL]: https://github.com/adafruit/Adafruit_NeoPixel
[LIBRARY_ADAFRUIT_IO]: https://github.com/adafruit/Adafruit_IO_Arduino
[LIBRARY_ADAFRUIT_MQTT]: https://github.com/adafruit/Adafruit_MQTT_Library
[LIBRARY_ARDUINO_HTTP_CLIENT]: https://github.com/arduino-libraries/ArduinoHttpClient

[LINK_IOT_STATUS_INDICATOR]: https://github.com/scott-linenberger/iot_status_indicator
[LINK_PRODUCT_MATRIX_KEYPAD]: https://www.adafruit.com/product/419