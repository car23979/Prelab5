/*
 * pwm.c
 *
 * Created: 11/04/2025 01:35:52 p. m.
 *  Author: Admin
 */ 

// pwm.c
#include "pwm.h"

void PWM_Init() {
	// Configura Timer1 (16 bits) para servo1
	DDRB |= (1 << PINB1); // Define PB1 como salida
	TCCR1A = (1 << COM1A1) | (1 << WGM11); // Modo PWM Phase Correct, sin inversión
	TCCR1B = (1 << WGM13) | (1 << CS11); // Prescaler 8, modo PWM con TOP = ICR1
	ICR1 = 20000; // TOP ? 20,000 ciclos a 16 MHz/8 = 20 ms ? 50 Hz (frecuencia típica para servos)
	
	// Configura Timer2 (8 bits) para servo2
	DDRD |= (1 << PIND3); // Define PD3 como salida
	TCCR2A = (1 << COM2B1) | (1 << WGM20);
	TCCR2B = (1 << WGM22) | (1 << CS22) | (1 << CS21) | (1 << CS20);  // Prescaler 1024
	OCR2A = 155; 
	OCR2B = 155 - ((1500 + 64) / 128);
	
	
	
	
	// Configura Timer0 (8 bits) en modo Fast PWM para el control de LED
	DDRD |= (1 << PIND5); // PD5 como salida
	TCCR0A = (1 << COM0B1) | (1 << WGM01) | (1 << WGM00); // Fast PWM no invertido
	TCCR0B = (1 << CS01) | (1 << CS00); // Prescaler 64 ? ~976 Hz
}

void setServo1(uint16_t pulseWidth) {
	OCR1A = pulseWidth; // Aplica pulso al canal A (PB1)
}

void setServo2(uint16_t pulseWidth) {
	OCR2B = 155 - ((pulseWidth + 64) / 128); // Aplica pulso al canal B (PB2)
}

void setLED(uint8_t brightness) {
	OCR0B = brightness; // Ajusta el duty cycle del LED (PD5)
}
