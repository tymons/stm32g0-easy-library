/*
 * gpio.h
 *
 *  Created on: 03.04.2019
 *      Author: Tymoteusz Cejrowski
 */

#ifndef PERIPH_GPIO_H_
#define PERIPH_GPIO_H_

#include <stdbool.h>
#include "stm32g070xx.h"

typedef enum gpio_type { GPIO_TYPE_IN, GPIO_TYPE_OUT, GPIO_TYPE_AF } GPIO_type_e;
typedef enum gpio_port {
	GPIO_PORT_A,
	GPIO_PORT_B,
	GPIO_PORT_C,
	GPIO_PORT_D
} GPIO_port_e;

typedef struct Gpio_t Gpio_t;
struct Gpio_t {

	const GPIO_type_e 	type;			// Type of GPIO

	uint8_t				pin_number;		// Pin number of GPIO
	GPIO_TypeDef* 		port_register;

	void(*initialize)(GPIO_type_e type);
	void(*set_output_level)(Gpio_t* gpio, bool state);
	bool(*get_input_level)(Gpio_t* gpio);
};

// Constructor
Gpio_t _Gpio(GPIO_port_e port, uint8_t pin_no);

#endif /* PERIPH_GPIO_H_ */
