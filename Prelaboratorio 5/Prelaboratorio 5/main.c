/*
 * Prelaboratorio 5.c
 *
 * Created: 11/04/2025 08:01:38 a. m.
 * Author : David Carranza
 */ 

// Encabezado
#include <avr/io.h>
#include <avr/interrupt.h>
#include "LED_PWM.h"
#include "timer1_config.h"
#include "timer1_servo1.h"
#include "timer1_servo2.h"

// Variables globales 
volatile uint16_t POTE1, POTE2, POTE3;
volatile uint8_t CANAL_ADC = 0;

// Configuración del Modulo ADC
void ADC_Init() {
	ADMUX = (1 << REFS0); // Selecciona VCC como referencia de voltaje
	ADCSRA = (1 << ADEN)  // Habilita el ADC
	| (1 << ADIE)  // Habilita interrupción por ADC
	| (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Prescaler 128
	ADMUX |= (CANAL_ADC & 0x07); // Selecciona canal inicial (PC0)
	ADCSRA |= (1 << ADSC); // Inicia la primera conversión
}

// RUTINA DE INTERRUPCIÓN DEL ADC
ISR(ADC_vect) {
	switch (CANAL_ADC) {
		case 0: POTE1 = ADC; break;
		case 1: POTE2 = ADC; break;
		case 2: POTE3 = ADC; break;
	}
	// Cambia al siguiente canal (0 ? 1 ? 2 ? 0 ...)
	CANAL_ADC = (CANAL_ADC + 1) % 3;
	ADMUX = (ADMUX & 0xF0) | (CANAL_ADC & 0x07); // Actualiza canal sin afectar la referencia
	ADCSRA |= (1 << ADSC); // Inicia nueva conversión
}

// Programa Principal
int main(void) {
	ADC_Init();
	Timer1_Config_Init();
    Timer1_Servo1_Init();
    Timer1_Servo2_Init();
    Timer0_LED_Init();
	sei(); // Habilita interrupciones globales

	while (1) {
		// El valor del potenciómetro va de 0 a 1023 (10 bits), se escala a un pulso entre 500 y 2500 (?s)
		// 500 + ((0-1023) * 2000 / 1023) ? [500, 2500]
		SERVO1_set(500 + (POTE1 * 2000UL / 1023)); // Controla el servo 1
		SERVO2_set(500 + (POTE2 * 2000UL / 1023)); // Controla el servo 2
		LED_set(POTE3 >> 2); // Controla el brillo del LED (1023 >> 2 = 255 máximo)
	}
}
