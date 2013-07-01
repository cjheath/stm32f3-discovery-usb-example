#include "stm32f30x.h"
#include "stm32f3_discovery.h"

/* Private variables ---------------------------------------------------------*/
RCC_ClocksTypeDef RCC_Clocks;
__IO uint32_t TimingDelay = 0;

/* Private function prototypes -----------------------------------------------*/
void TimingDelay_Decrement(void);
void Delay(__IO uint32_t nTime);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
  TimingDelay_Decrement();
}

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
  static const int clockwise[8] = { LED3, LED5, LED7, LED9, LED10, LED8, LED6, LED4 };
  int	i;

  /* SysTick end of count event each 20ms */
  RCC_GetClocksFreq(&RCC_Clocks);
  SysTick_Config(RCC_Clocks.HCLK_Frequency / 50);

  /* Initialize LEDs on STM32F3-Discovery board */
  for (i = 0; i < 8; i++)
    STM_EVAL_LEDInit(clockwise[i]);

  /* Infinite loop */
  for (i = 0; ; i++)
  {
    STM_EVAL_LEDOff(clockwise[(i+4)&0x7]);
    STM_EVAL_LEDOn(clockwise[i&0x7]);
    Delay(5); /*100ms*/
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  {
    TimingDelay--;
  }
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
