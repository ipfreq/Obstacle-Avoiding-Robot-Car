/**@file neck.c
*  @author Israel N. Gbati
*  @date 13 Sep 2016
*  @brief This file implements functions which intializes PWM control for the servo\n
*  motor.
*/

#include "TM4C123GH6PM.h"
#include "delay.h"
#define  LOAD_VALUE 320000        /**50hz(16MHz/320000)*/
#define  MIN_DUTY_CYCLE  319000   /**Value to rotate servo motor to leftmost point*/
#define  MAX_DUTY_CYCLE	 1000     /**Value to rotate servo motor to to rightmost point*/
#define  _50P_DUTY_CYCLE 160000   /**Value to rotate servo motor to to mid-point*/
void neck_init()
{

   int i =0;
    /* Enable Peripheral Clocks */ 
    SYSCTL->RCGCPWM |= 2;       /* enable clock to PWM1 */
    SYSCTL->RCGCGPIO |= 0x20;   /* enable clock to PORTF */
    SYSCTL->RCC &= ~0x00100000; /* no pre-divide for PWM clock */
    while(i<40){i++;}
    /* Enable port PF3 for PWM1 M1PWM7 */
    GPIOF->AFSEL = 8;           /* PF3 uses alternate function */
    GPIOF->PCTL &= ~0x0000F000; /* make PF3 PWM output pin */
    GPIOF->PCTL |= 0x00005000;
    GPIOF->DEN |= 8;            /* pin digital */
    
    PWM1->_3_CTL = 0;           /* stop counter */
    PWM1->_3_GENB = 0x0000008C; /* M1PWM7 output set when reload, */
                                /* clear when match PWMCMPA */
    PWM1->_3_LOAD = LOAD_VALUE;      
    PWM1->_3_CMPA = MIN_DUTY_CYCLE;       /* set duty cycle to 50% */
    PWM1->_3_CTL = 1;           /* start timer */
    PWM1->ENABLE = 0x80;        /* start PWM1 ch7 */
}
void neck_turn(uint32_t amount)
{
	PWM1->_3_CMPA = amount;
}



void check_left()
{   uint32_t i;
	PWM1->ENABLE |=0x80; 
	
	for(i=319000;i>=260000;i-=6400) 
	{
		
		PWM1->_3_CMPA= i;
	delayMs(1200);
		
	}
	
	PWM1->ENABLE &=~0x80;        /* start PWM1 ch7 */
}

void check_right()
{  uint32_t i;
	PWM1->ENABLE |=0x80; 
	
	for(i=260000;i<319000;i+=6400)
	{
		
		PWM1->_3_CMPA= i;
	delayMs(1000);
		
	}
	PWM1->ENABLE &=~0x80; 
}
