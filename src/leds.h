#ifndef _LEDS_H
#define _LEDS_H

#include <stdint.h>

void ledsInitPort(uint16_t * port);
uint16_t LedSetBit(uint8_t led);
void LedOn(uint8_t led);
void LedOff(uint8_t led);
void LedAllOn(void);
void LedAllOff(void);
uint8_t LedStatus(uint8_t led);

#endif
