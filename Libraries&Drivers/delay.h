#ifndef DELAY_H__
#define DELAY_H__
#include <stdint.h>
void delay_Microsecond(uint32_t time);
void delayMs(int n);
static const uint8_t LIMIT = 10;
int8_t rand_lim(int8_t limit);
void timer2A_init(void);
void timer3A_init(void);
void timer4A_init(void);
//static uint8_t distance;
#endif
