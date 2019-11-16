/**@file limbs.h
 * @brief Interface file for DC motor initialization and control
 */

#ifndef 	LIMBS_H__
#define		LIMBS_H__

/**@brief Function for initializing DC motors\n
*  implementation is done in assembly 
*/
void LIMBS_Init(void);
/**@brief Function to switch off right motor in order to\n
*  initiate differential  left turn. Implementation is done in assembly
*/
void TURN_Left(void);
/**@brief Function to switch off left motor in order to\n
 * initiate differential right turn. Implementation is done in assembly.
*/
void TURN_Right(void);
/**@breif Function to turn robot about 90 degrees
*/
void TURN_away();
/**@breif Function to turn robot left and drive forward\n
*  @param[in] forward_distance
*/
void WALK_away(uint16_t distance);
/**@breif Function to turn robot left
*/
void turnAwayLeft(void);
/**@breif Function to turn robot right
*/
void turnAwayRight(void);
/**@brief Function to turn robot 180 degrees left
*/
void turnAwayLeft180(void);
/**@breif Function to turn robot 360 degrees left
*/
void turnAwayLeft360(void);
/**@brief Function to turn robot 180 degrees right
*/
void turnAwayRight180(void);
/**@brief Function to turn robot 360 degrees right
*/
void turnAwayRight360(void);
/**@brief Function to drive robot forward
*  @param[in] distance to drive forward
*/
void walkForward(uint16_t distance);
/**@brief Function to switch on both DC motors to initiate\n 
*  forward movement. Implementation is done in assembly
*/
void FORWARD(void);
/**@brief Function to swtich off both DC notors to initiate\n
*  robot STOP. Implementation is done in assembly.
*/
void STOP(void);
/**@brief Function to call a set of functions for a particular\n
* pattern of movements for the robot.
*/
void runToHide(void);
/**@brief Function to call a set of functions for a particular\n
* pattern of movements for the robot.
*/
void seeWhoAndRun(void);

#endif