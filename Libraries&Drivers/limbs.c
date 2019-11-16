/**@file limbs.c
*  @author Israel N. Gbati
*  @date  13 Sep 2016
*  @brief This file contains functions that intialize and controls the DC motors and  
*/
#include <stdint.h>
#include "limbs.h" 
#include "delay.h"
 
void WALK_away(uint16_t distance)
 {
	 TURN_Left();
	 delayMs(6000);
	 FORWARD();
	 delayMs(10000+distance);
	 
 }
 void TURN_away(void)
 {
	 TURN_Right();
	 delayMs(6000);
 }
 void turnAwayRight(void)
 {
	 TURN_Right();
	 delayMs(6000);
 }
 void turnAwayRight180(void)
 {
	 TURN_Right();
	  delayMs(8000);
	 
 }
 void turnAwayRight360(void)
 {
	 TURN_Right();
	  delayMs(12000);
	
 }
 void turnAwayLeft180(void)
 {
	 TURN_Left();
	  delayMs(8000);
	
	}
 void turnAwayLeft360(void)
 {
	 TURN_Left();
	  delayMs(12000);
	 
 }

void turnAwayLeft(void)
{
	TURN_Left();
	delayMs(6000);
}
void walkForward(uint16_t distance)
{
	FORWARD();
	delayMs(1+distance);
}
void runToHide()
{
	STOP();
	delayMs(1000);
	turnAwayLeft360();
	walkForward(20000);
	STOP();
	
}
void seeWhoAndRun()
{
	STOP();
	delayMs(500);
	turnAwayRight360();
	STOP();
	delayMs(1000);
	turnAwayLeft360();
	walkForward(20000);
}