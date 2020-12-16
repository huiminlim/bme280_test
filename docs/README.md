# Interfacing BME280 sensor in C

This repo contains test code to verify porting of Arduino's SPI and Adafruit's BME280 C++ library to C.

Development was done in Atmel Studio 7.0 and tested on an Arduino Uno with ATmega328P microcontroller.

This is part of FYP project to use Bosch's BME280 sensor in C.

## Credits

Libraries are adapted from:

* [Arduino SPI library](https://github.com/arduino/ArduinoCore-avr/tree/master/libraries/SPI)

* [Adafruit's BME280 library](https://github.com/adafruit/Adafruit_BME280_Library)

Credits goes to them.

## BME280

Bosch's BME280 humidity sensor is used and the datasheet can be found [here](https://www.bosch-sensortec.com/products/environmental-sensors/humidity-sensors-bme280/).
