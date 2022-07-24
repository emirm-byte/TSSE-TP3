#include "leds.h"

#define OFFSET             1
#define BIT_MASK           1
#define MIN_LEDS           1
#define MAX_LEDS           16
#define ALL_LEDS_ON        0xFFFF 
#define ALL_LEDS_OFF       0x0000
#define LED_ON             1
#define LED_OFF            0
#define MASK(X) BIT_MASK << (X - OFFSET)


static uint16_t * gpio_port;

uint16_t LedSetBit(uint8_t led){

    return MASK(led); 
}

void ledsInitPort(uint16_t * port){
	gpio_port = port;   
	LedAllOff();
}

void LedOn(uint8_t led){
   if(led>MAX_LEDS){
      *gpio_port |= LedSetBit(MAX_LEDS); 
   }
   else if(led<MIN_LEDS){
      *gpio_port |= LedSetBit(MIN_LEDS);
   }
   else{
      *gpio_port |= LedSetBit(led);
   }
     
}

void LedOff(uint8_t led){
   
   if(led>MAX_LEDS){
      *gpio_port &= ~LedSetBit(MAX_LEDS); 
   }
   else if(led<MIN_LEDS){
      *gpio_port &= ~LedSetBit(MIN_LEDS);
   }
   else{
       *gpio_port &= ~LedSetBit(led);
   }
 
}

void LedAllOn(void){
    *gpio_port |= ALL_LEDS_ON;
}

void LedAllOff(void){
    *gpio_port &= ALL_LEDS_OFF;
}

uint8_t LedStatus(uint8_t led){
    uint8_t status = (LedSetBit(led) & *gpio_port) >> (led - OFFSET);
    if(status){
        return LED_ON;
    }
    return LED_OFF;
}
