#ifndef _LIN_COMMUNICATION_MATRIX_H_
#define _LIN_COMMUNICATION_MATRIX_H_

#include "RLIN_macrodriver.h"
#include "LIN.h"

typedef struct 
{
    uint8_t ID_xxx_XXX [8];
    // other ID 
}st_ID_xxx_msg;

#define ID_XX_xx_msg_Count ID_xxx_msg.ID_xxx_XXX

uint8_t Get_ID_XXX_XXX_XXX_XXX_(void)
{
    return ((( uint8_t )(( uint8_t )LIN_MSG_Read(IID_XX_xx_msg_Count, 0U) >> 3U) & 0x01U));
}

