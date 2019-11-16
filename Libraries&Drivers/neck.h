/**@file  neck.h
*  @brief Interface file for servo motor initialization and operation
*/
#ifndef	NECK_H__
#define NECK_H__


/**@brief Function for initializing servo motor with PWM control*/
void neck_init();
/**@brief Function for rotsting servo motor to a particular angle
 * @param[in] amount amount to rotate
 */
void neck_turn(uint32_t amount);

/**@brief Function to rotate servo motor to the leftmost point*/
void check_left();
/**@brief Function to rotate servo motor to the rightmost point*/
void check_right();

#endif