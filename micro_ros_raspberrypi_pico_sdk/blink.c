#include <stdio.h>
#include "pico/stdlib.h"
#include "pico_uart_transports.h"

const uint led_pin = 16;
int main()
{

	gpio_init(led_pin);
	gpio_set_function(led_pin, GPIO_OUT);
	while(true) {
		digitalWrite(led_pin, HIGH);
		delay(500);
		digitalWrite(led_pin, LOW);
		delay(500);
	}

}

