#include "TM4C123GH6PM.h" 
 #include <stdint.h>
 #include  "delay.h"
 #include  "play_around.h"
 #include  "limbs.h"
 #include  "head.h"
 #include  "lights.h"
 #include  "neck.h"                  
 
 
 void play(void)
 {
	  
	 GPIOF->DATA |=GREEN;
	 echoAndTimer0_Init();
	 no_way=headSensor_detect();
	 
	 //if(no_way <=7)
	 while(no_way<=7)
	 {
		 	 GPIOF->DATA =RED;

		 move = rand_lim(LIMIT);
		  switch(move)
			{
				case 1:
					turnAwayLeft();
				  no_way =10;
				  break;
				case 2:
          turnAwayLeft180();
				  no_way =10;
					break;
				case 3:
					turnAwayLeft360();
				  no_way =10;
  				break;
				case 5:
					turnAwayRight();
				  no_way =10;
				  break;
				case 7:
					turnAwayRight180();
				   no_way =10;
				  break;
				case 8:
					turnAwayRight360();
				   no_way =10;
				  break;
				default:
					turnAwayLeft();
				   no_way =10;
				  break; 
			}
		 
	 }
	 
		 walkForward(1);
	
 }
 void shy()
 {

	 walkForward(7000);
	 STOP();
	 check_left();
	 delayMs(2000);
	 turnAwayRight();
	 STOP();
	 check_right();
	 delayMs(2000);
	 walkForward(7000);
	 STOP();
	 check_left();
	 delayMs(2000);
	 turnAwayRight360();
	 STOP();
	 check_right();
	 delayMs(2000);
 }
 