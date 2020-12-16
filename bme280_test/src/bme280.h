/*
 * bme280.h
 *
 * Created: 16/12/2020 4:27:09 PM
 *  Author: user
 */ 

#include <stdint.h>

#define BME_INIT_NO_ERR 1
#define BME_INIT_ERR 0

/*!
 *  @brief Register addresses
 */
enum {
  BME280_REGISTER_CHIPID = 0xD0,
  BME280_REGISTER_VERSION = 0xD1,
  BME280_REGISTER_SOFTRESET = 0xE0,
};

int bme280_init(void);
uint8_t read8(uint8_t reg);
uint8_t spixfer(uint8_t x);