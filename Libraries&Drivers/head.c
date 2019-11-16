
/**@file head.c
 * @author Cortex-M .com
 * @date 14 Nov 2017
 * @brief This file contains functions to intializes Timer0 in Edge-Capture\n
 * mode in order to be able detect the precise time the echoed signaled is detected.
 */

#include "TM4C123GH6PM.h"                  
#include <stdint.h>
#include "head.h"
#include "delay.h"


void echoAndTimer0_Init(void){
	SYSCTL->RCGCTIMER |=(1U<<0);
	SYSCTL->RCGCGPIO |=(1U<<1); 
	GPIOB->DIR &=~ECHO;
	GPIOB->DEN |=ECHO;
	GPIOB->AFSEL |=ECHO;
	GPIOB->PCTL &=~0x0F000000;
	GPIOB->PCTL |= 0x07000000;
	
	TIMER0->CTL &=~1;
	TIMER0->CFG =4;
	TIMER0->TAMR =0x17;
	TIMER0->CTL |=0x0C;
	TIMER0->CTL |=1;
}


uint32_t headSensor_detect(void){
		GPIOA->DATA &=~TRIGGER;
	  delay_Microsecond(12);
	  GPIOA->DATA |= TRIGGER;
	  delay_Microsecond(12);
		GPIOA->DATA &=~TRIGGER;
		/*Capture firstEdge i.e rising edge*/
	  TIMER0->ICR =4;
		while((TIMER0->RIS & 4)== 0){};
			highEdge = TIMER0->TAR;
		/*Capture secondEdge i.e falling edge*/
		TIMER0->ICR =4; //Clear timer capture flag
		while((TIMER0->RIS &4)==0){};
		lowEdge =TIMER0->TAR;
		ddistance = lowEdge -highEdge; 
		ddistance = _16MHZ_1clock*(double) MULTIPLIER *(double)ddistance;
			  
			return ddistance;	
}

