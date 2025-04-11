/*
 * Prelaboratorio 5.c
 *
 * Created: 11/04/2025 08:01:38 a. m.
 * Author : David Carranza
 */ 

#include "pwm.h"
#include "adc.h"

int main(void) {
	PWM_Init();
	ADC_Init();
	
	while(1) {
		uint16_t adc_value = ADC_Read(0);  // Leer ADC0
		uint16_t pulse_width = ((adc_value * 1000UL) / 1023) + 1000;  // Escalar a 1000-2000
		PWM_SetDutyCycle(pulse_width);
	}
}