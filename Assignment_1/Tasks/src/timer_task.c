#include "timer_task.h"
#include "tim.h"
#include "iwdg.h"

volatile uint32_t tick = 0;

void TimerTask_Init(void)
{
    __HAL_TIM_CLEAR_FLAG(&htim2, TIM_FLAG_UPDATE);

    if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
    {
        Error_Handler();
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
    {
        tick++;
        HAL_IWDG_Refresh(&hiwdg);
    }
}