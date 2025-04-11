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

// Configuración del Modulo ADC
void ADC_Init() {
	ADMUX = (1 << REFS0); // Selecciona VCC como referencia de voltaje
	ADCSRA = (1 << ADEN)  // Habilita el ADC
	| (1 << ADIE)  // Habilita interrupción por ADC
	| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128
	ADMUX |= (adcChannel & 0x07); // Selecciona canal inicial (PC0)
	ADCSRA |= (1 << ADSC); // Inicia la primera conversión
}

// RUTINA DE INTERRUPCIÓN DEL ADC
ISR(ADC_vect) {
	switch (adcChannel) {
		case 0:
		potValue1 = ADC; // Guarda lectura del primer potenciómetro
		break;
		case 1:
		potValue2 = ADC; // Guarda lectura del segundo potenciómetro
		break;
		case 2:
		potValue3 = ADC; // Guarda lectura del tercer potenciómetro
		break;
		default:
		potValue1 = ADC; // Valor de respaldo
		break;
	}
	// Cambia al siguiente canal (0 ? 1 ? 2 ? 0 ...)
	adcChannel = (adcChannel + 1) % 3;
	ADMUX = (ADMUX & 0xF0) | (adcChannel & 0x07); // Actualiza canal sin afectar la referencia
	ADCSRA |= (1 << ADSC); // Inicia nueva conversión
}


int main(void) {
	PWM_Init();
	ADC_Init();
	
	while(1) {
		uint16_t adc_value = ADC_Read(0);  // Leer ADC0
		uint16_t pulse_width = ((adc_value * 1000UL) / 1023) + 1000;  // Escalar a 1000-2000
		PWM_SetDutyCycle(pulse_width);
	}
}