#ifndef __USR_HALLEFFECT_LIB_H
#define __USR_HALLEFFECT_LIB_H

#include "usr_arch.h"

#ifdef STM32_L051R8
    #include "main.h"
    #include "gpio.h"
#endif

#define _BATTERY_COVER_HALL_POWER(x)   (x ? (BATTERY_COVER_HALL_SWITCH_POWER_GPIO_Port->BSRR = BATTERY_COVER_HALL_SWITCH_POWER_Pin) : (BATTERY_COVER_HALL_SWITCH_POWER_GPIO_Port->BRR = BATTERY_COVER_HALL_SWITCH_POWER_Pin))
#define _TOP_COVER_HALL_POWER(x)       (x ? (TOP_COVER_HALL_SWITCH_POWER_GPIO_Port->BSRR = TOP_COVER_HALL_SWITCH_POWER_Pin) : (TOP_COVER_HALL_SWITCH_POWER_GPIO_Port->BRR = TOP_COVER_HALL_SWITCH_POWER_Pin))

#define _BATTERY_COVER_HALL_READ_PIN() BATTERY_COVER_HALL_SWITCH_OUT_INT_GPIO_Port->IDR & BATTERY_COVER_HALL_SWITCH_OUT_INT_Pin
#define _TOP_COVER_HALL_READ_PIN()     TOP_COVER_HALL_SWITCH_OUT_INT_GPIO_Port->IDR & TOP_COVER_HALL_SWITCH_OUT_INT_Pin 

typedef enum
{
    disableHalleffect,
    enableHalleffect,
}EHalleffectControl;

typedef struct S_HALLEFFECT_PARAMETERS_TAG
{
    GPIO_TypeDef *tophalleffectpowerport;
    GPIO_TypeDef *tophalleffectinterruptport;

    GPIO_TypeDef *batteryhalleffectpowerport;
    GPIO_TypeDef *batteryhalleffectinterruptport;

    int tophalleffectpowerpin;
    int tophalleffectinterruptpin;

    int batteryhalleffectpowerpin;
    int batteryhalleffectinterruptpin;

    uint8_t batteryhalleffectstatus;
    uint8_t tophalleffectStatus;

    EHalleffectControl ehalleffectmode;
}S_HALLEFFECT_PARAMETERS;


void UL_HalleffectPeripheral(S_HALLEFFECT_PARAMETERS *f_pParameter ,EHalleffectControl f_eControl);
bool UL_HalleffectInitial(S_HALLEFFECT_PARAMETERS *f_pParameter);

#endif
