/*
 * pwm.h
 *
 * Created: 11/04/2025 01:35:17 p. m.
 *  Author: Admin
 */ 

// pwm.h
#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <stdint.h>

// Inicializa los temporizadores PWM (Timer1 para servos, Timer0 para LED)
void PWM_Init();

// Define la posición del servo 1 conectado a PB1
void setServo1(uint16_t pulseWidth); // pulseWidth en microsegundos (500–2500 us)

// Define la posición del servo 2 conectado a PB2
void setServo2(uint16_t pulseWidth);

// Ajusta el brillo del LED conectado a PD5
void setLED(uint8_t brightness); // 0 = apagado, 255 = brillo máximo

#endif /* PWM_H_ */