/*
 * bme280.c
 *
 * Created: 16/12/2020 4:27:01 PM
 *  Author: user
 */ 

#include <bme280.h>
#include <spi.h>
#include <uart.h>

/*
 * This function verifies if sensor is initialized
 * Assumes that SPI has been initialized already
 */ 
int bme280_init(void) {
	// Check if read successfully from sensor ID
	uint8_t sensor_id = read8(BME280_REGISTER_CHIPID);
	if (sensor_id != 0x60) return BME_INIT_ERR;
	
	printf("Sensor ID: 0x%x\r\n", sensor_id);
	
	return BME_INIT_NO_ERR;
}

/*
 * This function reads 8 bits from sensor
 * With a given reg
 */ 
uint8_t read8(uint8_t reg) {
	spi_begin_txn(500000, MSBFIRST, SPI_MODE0);
	ioport_set_pin_low(SPI_HARDWARE_SS);			// SS set to low - select slave
	spixfer(reg | 0x80);							// read, bit 7 high
	uint8_t value = spixfer(0);
	ioport_set_pin_high(SPI_HARDWARE_SS);			// SS set to high - de-select slave
	//spi_end_txn();
	
	return value;
}

/*
 * This function transfers 8 bits via SPI
 */ 
uint8_t spixfer(uint8_t x) {
	// Hardware SPI transfer used
	// Write to MOSI pin and receive on MISO pin
	SPDR = x;
	
	// NOP to introduce delay to prevent wait
	// Loop form iterating when running at the maximum speed
	// This gives about 10% more speed,
	// even if it seems counter-intuitive at lower speeds it is unnoticed.
	asm volatile("nop");
	while (!(SPSR & _BV(SPIF))) ; // wait
	return SPDR;
}