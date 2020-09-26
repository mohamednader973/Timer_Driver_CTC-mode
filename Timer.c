/*
 * Timer.c
 *
 * Created: 9/27/2020 12:29:13 AM
 *  Author: monad
 */ 
#include "Timer.h"
volatile unsigned short flag=0;
volatile unsigned char  arr[2]={10,200};
void Timer_Init(void)
{
	//OCR0 =arr[flag];
	TCNT_CMP_REG=arr[flag];
	//TCCR0 |=(1<<CS00)|(1<<CS02)|(1<<WGM01)|(1<<COM00);
	SetBIT(TCNT_Ctrl_REG,WaveGenbit_1);
	SetBIT(TCNT_Ctrl_REG,Prescl_0);
	SetBIT(TCNT_Ctrl_REG,Prescl_2);
	SetBIT(TCNT_Ctrl_REG,CMP_MATCH_OUT_0);
	//TIMSK |=(1<<OCIE0);
	SetBIT(TCNT_INTMSK,CMP_MATCH_OUT_INT);
	sei();
	
}
void Timer_CTC_PWM(void)
{
	flag++;
	if (flag==2)
	{
	  flag=0 ;
	}
	TCNT_CMP_REG=arr[flag];
}