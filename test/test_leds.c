#include "unity.h"
#include "leds.h"
#include "mock_errores.h"

static uint16_t ledsVirtuales;

void setUp(void){
    ledsInitPort(&ledsVirtuales);
}

void tearDown(void){


}

void test_LedsOffAfterCreate(void){
    uint16_t ledsVirtuales=0xFFFF;    
    ledsInitPort(&ledsVirtuales);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales);

}

void test_TurnOnOneLed(void){
    LedOn(5);
    TEST_ASSERT_EQUAL_HEX16(1 << 4,ledsVirtuales); 

}

void test_TurnOffOneLed(void){
    LedOn(3);
    LedOff(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000,ledsVirtuales); 

}

void test_TurnOnAndOffManyLed(void){
    LedOn(5);
    LedOn(11);
    LedOff(3);
    LedOff(11);
    TEST_ASSERT_EQUAL_HEX16(1<<4,ledsVirtuales); 

}

void test_LedAllTurnOn(void){
    LedAllOn();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, ledsVirtuales);
}

void test_LedAllTurnOff(void){
    LedAllOn();
    LedAllOff();  
    TEST_ASSERT_EQUAL_HEX16(0x0000, ledsVirtuales);
}

void test_LedStateOn(void){
    LedOn(8);
    uint8_t status = LedStatus(8);
    TEST_ASSERT_EQUAL_HEX16(1, status);
}

void test_LedStateOff(void){
    LedOff(8);
    uint8_t status = LedStatus(8);
    TEST_ASSERT_EQUAL_HEX16(0, status);
}

void test_InvalidUpperLimitTurnOnLed(void){
    RegistrarMensaje_Expect(ALERTA, "LedOn",0 ,"Led Invalido");
    RegistrarMensaje_Ignore();
    LedOn(18);
}
