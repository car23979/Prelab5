/*
 * pwm_init.c
 *
 * Created: 24/04/2025 12:23:08 p. m.
 *  Author: Admin
 */ 

#include "LED_PWM.h"
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t contador_pwm = 0;
volatile uint8_t duty_pwm = 128; // Duty inicial 50%

void LED_PWM_Init(void) {
	DDRD |= (1 << PD5); // Pin PD5 como salida (LED)

	// Configurar Timer2 para overflow cada ~62.5us con prescaler de 64
	TCCR2A = 0x00;                  // Modo Normal
	TCCR2B = (1 << CS22);           // Prescaler 64
	TIMSK2 = (1 << TOIE2);          // Habilitar interrupción por overflow
}

void LED_Update_Duty(uint8_t dc) {
	duty_pwm = dc;
}

ISR(TIMER2_OVF_vect) {
	contador_pwm++;

	if (contador_pwm == 0) {
		PORTD |= (1 << PD5); // Encender LED al inicio del ciclo
	}

	if (contador_pwm >= duty_pwm) {
		PORTD &= ~(1 << PD5); // Apagar LED cuando se cumpla duty
	}
}
