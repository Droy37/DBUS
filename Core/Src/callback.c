#include "usart.h"

extern uint8_t buffer[18];
extern uint8_t data[18];
extern struct RC_Ctl_t RC_CtrlData;
void dataProcess(const uint8_t pData[18]);

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size) {
    if (huart == &huart1) {
        HAL_UARTEx_ReceiveToIdle_DMA(&huart1, buffer, sizeof(buffer));
        for(int i = 0; i < 18; i++) {
            data[i] = buffer[i];
        }

        dataProcess(data);
    }
}
