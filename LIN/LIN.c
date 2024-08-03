#include "RLIN_macrodriver.h"
#include "RLIN_driver.h"
#include "LIN.h"

uint8_t Slave_RxData1[8];              /*reception data store array*/
uint8_t Slave_RxData2[8];              /*reception data store array*/
uint8_t Slave_RxData3[8];              /*reception data store array*/
uint8_t Slave_TxData[] = {0x55, 0xC0}; /*Transmission data store array*/

/****************************************************************
 * Name:   Slave_ID_Switch
 * Brief:  根据PID进行不同操作(从机)
 * Input:  PID, head_flag, response_flag
 * Return: None
 ***************************************************************/
void Slave_ID_Switch(uint8_t PID, uint8_t head_flag, uint8_t response_flag)
{
    if (head_flag) /* Header successful receive*/
    {
        /* LIE0&=0xF7; */ /*Disable header interrupt*/ /*revision 1.01*/
        LST0 &= 0X7F;                                  /*clear successful header reception flag*/

        switch (PID)
        {
        case 0x08:
            RLIN_Slave_Receive(3);
            break;
        case 0x49:
            RLIN_Slave_Receive(3);
            break;
        case 0xCA:
            RLIN_Slave_Receive(3);
            break;
        case 0x8B:
            RLIN_Slave_Transmit(Slave_TxData, 2);
            P6 = Slave_TxData[1]; // light P66,P67
            break;
        default:
            RLIN_Slave_NoResponse();
            break;
        }
        /*LIE0 |= 0x80; */ /*enable header reception interrupt*/ /*revision 1.01*/
    }

    if (response_flag)
    {
        /*LIE0 &= 0xFD; */ /* disable response reception interrupt*/ /*revision 1.01*/
        LST0 &= 0xFD;                                                /* clear response reception successful flag*/

        switch (PID)
        {
        case 0x08:
            P6 = Get_response_RxData(Slave_RxData1);
            break;
        case 0x49:
            P6 = Get_response_RxData(Slave_RxData2);
            break;
        case 0xCA:
            P6 = Get_response_RxData(Slave_RxData3);
            break;
        default:
            break;
        }

        /*LIE0|=0x02; */ /*enable reception interrupt*/ /*revision 1.01*/
    }
    LTRC0 = 0x01; /*enabled header reception interrupt*/
}

/****************************************************************
 * Name:   Read_LIN_MSG
 * Brief:  读出报文数据段某字节
 * Input:  *DataArray, DataIdx
 * Return: uint8_t data
 ***************************************************************/
uint8_t Read_LIN_MSG(uint8_t *DataArray, uint8_t DataIdx)
{
    uint8_t data;

    if (DataIdx > 8u)
    {
        return;
    }

    data = DataArray[DataIdx];
    return data;
}

/****************************************************************
 * Name:   Clean_DataBuffer
 * Brief:  清除8位寄存器
 * Input:  uint16_t Register_adr
 * Return: None
 ***************************************************************/
void Clean_Register(uint16_t Register_adr)
{
    uint8_t i;
    uint16_t logical_address;
    logical_address = Register_adr;
    for (i = 0u; i < 8u; i++)
    {
        *((uint8_t *)(logical_address + i)) = 0U;
    }
}

void LIN_Msg_Analysis(uint8_t (*Msg_Byte)(uint8_t *DataArray, uint8_t DataIdx))
{
    ; // 等甲方要求
}

uint8_t Get_ErrorType(void)
{
    uint8_t bit;
    uint8_t Error_Status_Data;
    uint8_t basis = 0x01;

    Error_Status_Data = LEST0;
    for (bit = 0u; bit < 8u; bit++)
    {
        /*左移0x01，逐位相与，判断不为假则返回位数*/
        if (Error_Status_Data & (basis << bit)) 
        {
            return bit;
        }
        else
        {
            ;
        }
    }
}