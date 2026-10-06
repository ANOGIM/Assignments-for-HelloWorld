#include "led_task.h"
#include "main.h"

void LedTask_Init(void)
{
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
}