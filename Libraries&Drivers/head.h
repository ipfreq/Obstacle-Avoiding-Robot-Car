/**@file head.h
 * @brief interface file for ultrasonic sensor initialization and operation
 */
#ifndef HEAD_H__
#define HEAD_H__
#include <stdint.h>

/**@brief Function for initialization Timer0*/
void echoAndTimer0_Init(void);
/**@brief Function for detecting and calculating distance*/
uint32_t headSensor_detect(void);
/**@brief Functionn for initializing the Trigger pin of the the\n
 * ultrasonic sensor. Implementation is done in assembly
 */
void HEAD_Init(void);


static const double _16MHZ_1clock = 62.5e-9; /*value of 1clock cycle in nanoseconds*/
static const uint32_t MULTIPLIER = 5882; /*Constant derived from the speed of sound*/

#define ECHO (1U<<6)
#define TRIGGER (1U<<4)

static uint32_t highEdge; /** Variable to hold time-stamp of high-edge detection*/
static uint32_t lowEdge;  /** Variable to hold time-stamp of low-edge detection */
static uint32_t ddistance;/** Variable to hold calculated distance*/


#endif
