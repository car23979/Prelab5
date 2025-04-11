/*
 * pwm.c
 *
 * Created: 11/04/2025 01:35:52 p. m.
 *  Author: Admin
 */ 

// pwm.c
#include "pwm.h"

void PWM_Init() {
	DDRB |= (1 << DDB1);  // Configura OC1A (PB1) como salida
	
	// Modo PWM Fase-Frecuencia Correcta con ICR1 como TOP
	TCCR1A = (1 << COM1A1);          // Modo no-invertido
	TCCR1B = (1 << WGM13) | (1 << CS11);  // Modo 8, prescaler 8
	
	ICR1 = 20000;  // Periodo de 20ms (50Hz)
}

void PWM_SetDutyCycle(uint16_t duty) {
	OCR1A = duty;  // Establece el ciclo de trabajo
}