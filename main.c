/*
 * Timer_Driver.c
 *
 * Created: 9/26/2020 10:30:30 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "Timer.h"
int main(void)
{
	DDRC |=(1<<2)|(1<<7);
	DDRB |=(1<<3);
	Timer_Init();
    /* Replace with your application code */
    while (1) 
    {
    }
}
ISR (TIMER0_OVF_vect)
{
	
}
ISR(TIMER0_COMP_vect)
{
	Timer_CTC_PWM();
}
