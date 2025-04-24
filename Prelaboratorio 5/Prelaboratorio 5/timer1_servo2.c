/*
 * pwm2.c
 *
 * Created: 11/04/2025 05:37:03 p. m.
 *  Author: David Carranza
 */ 

#include "pwm2.h"

void PWM2_Init() {
	// Configura Timer1 (16 bits) para servo1
	DDRB |= (1 << PINB2); // Define PB1 como salida
	TCCR1A = (1 << COM1B1) | (1 << WGM11); // Modo PWM Phase Correct, sin inversión
	TCCR1B = (1 << WGM13) | (1 << CS11);
	ICR1 = 40000;
	OCR1B = 3000; // TOP ? 20,000 ciclos a 16 MHz/8 = 20 ms ? 50 Hz (frecuencia típica para servos)	
}

void setServo2(uint16_t pulseWidth) {
	OCR1B = (uint16_t)(pulseWidth * 2); // Aplica pulso al canal B (PB2)
}