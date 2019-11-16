#include "TM4C123GH6PM.h"                   
#include <stdint.h>
#include "delay.h"
#include "head.h"
#include "limbs.h"
#include "play_around.h"
#include "tail.h"
#include <stdlib.h>
/*!
\param a an integer argument.
\param s a constant character pointer.
\return The test results
\sa QTstyle_Test(), ~QTstyle_Test(), testMeToo() and publicVar()
*/


void delay_Microsecond(uint32_t time)
{
	int i;
	SYSCTL->RCGCTIMER |=(1U<<1);
	TIMER1->CTL =0;
	TIMER1->CFG =0x04;
	TIMER1->TAMR = 0x02;
	TIMER1->TAILR = 16-1;
	TIMER1->ICR = 0x1;
	TIMER1->CTL |=0x01;
	
	for(i=0;i<time;i++){
	  while((TIMER1->RIS&0x1)== 0){
		TIMER1->ICR = 0x1;
		}
   }
	}

	void delayMs(int n)
{
    int i, j;
    for(i = 0 ; i < n; i++)
        for(j = 0; j < 3180; j++)
            {}  /* do nothing for 1 ms */
}

/**
* a normal member taking two arguments and returning an integer value.
* @param a an integer argument.
* @param s a constant character pointer.
* @see Javadoc_Test()
* @see ~Javadoc_Test()
* @see testMeToo()
* @see publicVar()
* @return The test results
*/

int8_t rand_lim(int8_t limit) {
/* return a random number between 0 and limit inclusive.
 */

    int divisor = RAND_MAX/(limit+1);
    int retval;

    do { 
        retval = rand() / divisor;
    } while (retval > limit);

    return retval;
}
void timer2A_init(void)
{
    SYSCTL->RCGCTIMER |= 4;     /* enable clock to Timer Block 2   */
    TIMER2->CTL = 0;            /* disable Timer2 before initialization */
    TIMER2->CFG = 0x04;         /* 16-bit option */
    TIMER2->TAMR = 0x02;        /* periodic mode and down-counter */
    TIMER2->TAPR = 250;         /* 16000000 Hz / 250 = 64000 Hz  */
	
     TIMER2->TAILR = 64000;       /*64000 Hz / 64000 = 1 Hz */
    TIMER2->ICR = 0x1;          /* clear the Timer2A timeout flag */
    TIMER2->IMR |= 0x01;        /* enable Timer2A timeout interrupt */
    TIMER2->CTL |= 0x01;        /* enable Timer2A after initialization */
    NVIC->ISER[0] |= 0x00800000;  /* enable IRQ23 (D23 of ISER[0]) */
}

void TIMER2A_Handler(void)
{
	
	volatile int readback;
	if(TIMER2->MIS & 0x1)  /*Timer2A timeout flag */
	{

		 echoAndTimer0_Init();
      no_way=headSensor_detect();
		if ((TAIL_sense()!=IR_PIN)&&(no_way <7))  /*Both Sensors detect obstacles*/
		{
			STOP();
		}
		else if((TAIL_sense()== IR_PIN)&&(no_way<7)) /*Only head sensor detects obstacle*/
		{
			 GPIOF->DATA |=0x4;
			 runToHide();
		}
		else if((TAIL_sense() !=IR_PIN)&&(no_way>7))	/*Only tail sensor detects obstacle*/
		{
				GPIOF->DATA |=0x0E;
			  seeWhoAndRun();
		}

		TIMER2->ICR = 0x1;  /*clear the Timer timeout flag*/
	  readback =TIMER2->ICR;
	}
	else
    {   /* should not get here, but if we do */
        TIMER2->ICR = TIMER2->MIS;  /* clear all flags */
        readback = TIMER2->ICR;      /* a read to force clearing of interrupt flag */
    }

}
