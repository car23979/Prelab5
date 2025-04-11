/*
 * adc.h
 *
 * Created: 11/04/2025 01:36:39 p. m.
 *  Author: Admin
 */ 

// adc.h
#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void ADC_Init();
uint16_t ADC_Read(uint8_t channel);

#endif