/*
 * pwm2.c
 *
 * Created: 11/04/2025 05:37:03 p. m.
 *  Author: David Carranza
 */ 

#include "pwm2.h"

void PWM2_Init() {
	// Configura Timer2 (8 bits) para servo2
	DDRD |= (1 << PIND3); // Define PD3 como salida
	TCCR2A = (1 << COM2B1) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20);  // Prescaler 1024
	OCR2A = 155;
	
	OCR2B = 23;	
}

void setServo2(uint16_t pulseWidth) {
	OCR2B = (uint8_t)((pulseWidth + 64) / 128); // Aplica pulso al canal B (PB2)
}