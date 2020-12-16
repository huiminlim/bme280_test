#include <asf.h>
#include <spi.h>
#include <uart.h>
#include <bme280.h>

#define MY_LED    IOPORT_CREATE_PIN(PORTB, 5)

int main (void)
{
	/* Insert system clock initialization code here (sysclk_init()). */
	board_init();

	ioport_init();
	uart_init();
	
	// Sensors initialization
	spi_init();
	int ret = bme280_init();
	
	if (ret == BME_INIT_NO_ERR) printf("Sensor Initialized\r\n");
	else {
		printf("Sensor initialization failed!\r\n");
		while(1);
	}
		
	while (1) {
		//ioport_toggle_pin_level(SPI_HARDWARE_SS);
		//ioport_set_pin_low(MY_LED);
		printf("Continue\r\n");
		delay_ms(5000);
	}
}
