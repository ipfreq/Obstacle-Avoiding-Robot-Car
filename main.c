/**@file  main.c
 * @author Israel N. Gbati
 * @date 13 Sep 2016
 * @brief This file contains the main application source code for the VeXin robot
 */
 

#include "TM4C123GH6PM.h"                    
#include "neck.h"
#include "head.h"
#include "tail.h"
#include "limbs.h"
#include "lights.h"
#include "delay.h"
#include "play_around.h"




/**@brief This function intializes the various modules of the robot\n 
 and runs the assigned robot behavior in an infinite loop
*/
int main()
	
{
/*!
* 
*    TAIL_Init()    : Initialization of TAIL module i.e. IR Sensor\n
*	   HEAD_Init()    : Initialization of HEAD module i.e. Ultrasonic Sensor\n
*	   LIGHTS_Init()  : Initialization of LIGHTS module\n 
*	   neck_init()    : Initialization of NECK module i.e. Servo motor\n
*	   timer2A_init() : Initialization of TIMER2A for interrupt 
*	   __enable_irq() : Global enable Interrupts
*/
	 
   TAIL_Init();    /*Initialization of IR sensor.*/
	 HEAD_Init();    /*Initialization of ultrasonics sensor.*/
	 LIGHTS_Init();  /*Initialization of RGB LEDS*/
	 LIMBS_Init();   /*Initialization of DC motors*/
	 neck_init();    /*Initialization of servo motor*/
	 timer2A_init(); /*Initialization of TIMER2A for interrupt */
	
    __enable_irq(); /* global enable IRQs */
	
	while(1)
	{


		//shy();   /** shy()	: Assigned robot behavior*/
 play();
	 }
}


