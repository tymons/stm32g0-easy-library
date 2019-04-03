/*
 * gpio.c
 *
 *  Created on: 03.04.2019
 *      Author: Tymoteusz Cejrowski
 */
#include "gpio.h"

/**
 * @brief	Function that maps GPIO_port_e enum to specific GPIOTypeDEf structure.
 * 			It was mean to be more user-friendly to operate on well described enums rather than GPIO_Typedef structures.
 *
 * @param	port			- GPIO_port_e enum desciribing what port should be mapped
 * @return	GPIO_TypeDef*	- pointer to GPIO_TypDef structure which is valid for stm32g0 uC
 * 							  and can be then referenced along with specific registers
 */
static inline GPIO_TypeDef* _gpio_getStructureBasedOnPort(GPIO_port_e port)
{
	static GPIO_TypeDef* types[] = { GPIOA, GPIOB, GPIOC, GPIOD };
    return types[port];
}

/**
 * @brief 	GPIO constructor
 *
 * @param 	port	- GPIO_port_e describing what port will be used
 * @param	pin_no	- pin number of specific GPIO what will be used
 */
Gpio_t _Gpio_t(const GPIO_port_e port, const uint8_t pin_no)
{
	Gpio_t _gpio;

	_gpio.pin_number = pin_no;
	_gpio.port_register = _gpio_getStructureBasedOnPort(port);

	return _gpio;

}
