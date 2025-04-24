/*
 * pwm_init.c
 *
 * Created: 24/04/2025 12:23:08 p. m.
 *  Author: Admin
 */ 

#include <avr/io.h>
#include "timer0_led.h"

void Timer0_LED_Init(void) {
	DDRD |= (1 << PIND5); // PD5 como salida
	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM
	TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64
}

void LED_set(uint8_t brillo) {
	OCR0B = brillo;
}
