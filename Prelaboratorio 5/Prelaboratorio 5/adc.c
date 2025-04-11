/*
 * adc.c
 *
 * Created: 11/04/2025 01:37:04 p. m.
 *  Author: Admin
 */ 

// adc.c
#include "adc.h"

void ADC_Init() {
	ADMUX = (1 << REFS0);  // Voltaje de referencia AVcc
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);  // Habilitar ADC, prescaler 128
}

uint16_t ADC_Read(uint8_t channel) {
	ADMUX = (ADMUX & 0xF8) | (channel & 0x07);  // Seleccionar canal
	ADCSRA |= (1 << ADSC);  // Iniciar conversión
	while (ADCSRA & (1 << ADSC));  // Esperar fin de conversión
	return ADC;
}