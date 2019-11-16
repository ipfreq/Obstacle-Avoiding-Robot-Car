#ifndef	TAIL_H__
#define TAIL_H__
#include <stdint.h>

void TAIL_Init(void);
uint32_t TAIL_sense(void);
#define IR_PIN   (1U<<5)//PA5 (INPUT);
#endif