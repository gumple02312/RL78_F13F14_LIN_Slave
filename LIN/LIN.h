#ifndef _LIN_H_
#define _LIN_H_

typedef struct
{
    uint8_t Bit_error = ;    // 位错误
    uint8_t Checksum_error;  // 校验和错误
    uint8_t timeout_error;   // 帧超时错误/响应超时错误
    uint8_t SyncFiled_error; // 同步字段错误
    uint8_t IDParity_error;  // ID奇偶校验错误
    uint8_t Framing_error;   // 帧误差
    uint8_t ResPrep_error;   // 响应准备错误
} st_LIn_Slave_Error_Type;

void Clean_Register(uint16_t Register_adr);
uint8_t Get_ErrorType(void);
void Slave_ID_Switch(uint8_t PID, uint8_t head_flag, uint8_t response_flag)

#endif