/*
 * Prelaboratorio 5.c
 *
 * Created: 11/04/2025 08:01:38 a. m.
 * Author : David Carranza
 */ 

// Encabezado
#include "pwm.h"
#include <avr/io.h>
#include <avr/interrupt.h>

// Variables globales 
volatile uint16_t potvalue1, potvalue2, potvalue3; // Variables para leer valores de los potenciometros
volatile uint8_t adcChannel = 0;	// Canal actual de ADC


int main(void) {
	PWM_Init();
	ADC_Init();
	
	while(1) {
		uint16_t adc_value = ADC_Read(0);  // Leer ADC0
		uint16_t pulse_width = ((adc_value * 1000UL) / 1023) + 1000;  // Escalar a 1000-2000
		PWM_SetDutyCycle(pulse_width);
	}
}