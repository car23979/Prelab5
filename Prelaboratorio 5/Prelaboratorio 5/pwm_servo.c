/*
 * pwm_servo.c
 *
 * Created: 11/04/2025 12:35:35 p. m.
 *  Author: Admin
 */ 

#include "pwm_servo.h"
#include <avr/io.h>

void PWM_Init() {
	DDRB |= (1 << DDB1);                        // Pin OC1A (PB1 / D9) como salida
	TCCR1A = (1 << COM1A1) | (1 << WGM11);      // Modo Fast PWM, no invertido
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler = 8
	ICR1 = 39999;                               // TOP para 50 Hz (20 ms)
	OCR1A = 3000;                               // Posición neutra (1.5 ms)
}

void PWM_SetPulseWidth(uint16_t pulseWidth) {
	if (pulseWidth < 2000) pulseWidth = 2000;
	if (pulseWidth > 4000) pulseWidth = 4000;
	OCR1A = pulseWidth;
}
