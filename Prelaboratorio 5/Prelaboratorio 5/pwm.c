/*
 * pwm.c
 *
 * Created: 11/04/2025 01:35:52 p. m.
 *  Author: Admin
 */ 

// pwm.c
#include "pwm.h"

void PWM_Init() {
	// Configura Timer1 (16 bits) para controlar servos
	DDRB |= (1 << PINB1) | (1 << PINB2); // Define PB1 y PB2 como salidas

	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11); // Modo PWM Phase Correct, sin inversión
	TCCR1B = (1 << WGM13) | (1 << CS11); // Prescaler 8, modo PWM con TOP = ICR1
	ICR1 = 20000; // TOP ? 20,000 ciclos a 16 MHz/8 = 20 ms ? 50 Hz (frecuencia típica para servos)

	// Configura Timer0 (8 bits) en modo Fast PWM para el control de LED
	DDRD |= (1 << PIND5); // PD5 como salida
	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM no invertido
	TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64 ? ~976 Hz
}
