/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "app_threadx.h"
#include "eth.h"
#include "gpio.h"
#include "rtc.h"
#include "sdio.h"
#include "spi.h"
#include "tim.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// объявление списка дескрипторов прм
uint32_t RXDL[4];

// объявление буфера прм
uint8_t RX_BUF[1532];
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void eth_init(void);
/* USER CODE END PFP */

/* Private user code
   ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void) {

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick.
   */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_RTC_Init();
  MX_TIM8_Init();
  MX_TIM7_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM6_Init();
  MX_SPI1_Init();
  MX_TIM1_Init();
  MX_TIM4_Init();
  // MX_ETH_Init();
  // MX_SDIO_SD_Init();
  /* USER CODE BEGIN 2 */
  // eth_init();
  /* USER CODE END 2 */

  MX_ThreadX_Init();

  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1) {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType =
      RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK |
                                RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void eth_init(void) {
  // настройка езернет
  // разраешение портов пинов езернет
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN |
                  RCC_AHB1ENR_GPIOCEN | RCC_AHB1ENR_GPIODEN |
                  RCC_AHB1ENR_GPIOEEN;

  // разрешение sescfg
  RCC->APB2ENR |= RCC_APB2ENR_SYSCFGEN;

  // установка режима RMII
  SYSCFG->PMC = SYSCFG_PMC_MII_RMII_SEL;

  // настройка пинов как AF и езернет
  GPIOA->MODER |=
      GPIO_MODER_MODER7_1 | GPIO_MODER_MODER2_1 | GPIO_MODER_MODER1_1;
  GPIOB->MODER |=
      GPIO_MODER_MODER13_1 | GPIO_MODER_MODER12_1 | GPIO_MODER_MODER11_1;
  GPIOC->MODER |=
      GPIO_MODER_MODER5_1 | GPIO_MODER_MODER4_1 | GPIO_MODER_MODER1_1;
  GPIOD->MODER |= GPIO_MODER_MODER8_0;  // pin 8-0utput
  GPIOE->MODER |= GPIO_MODER_MODER12_0; // pin 12-0utput

  GPIOA->OSPEEDR |=
      GPIO_OSPEEDER_OSPEEDR7 | GPIO_OSPEEDER_OSPEEDR2 | GPIO_OSPEEDER_OSPEEDR1;
  GPIOB->OSPEEDR |= GPIO_OSPEEDER_OSPEEDR14 | GPIO_OSPEEDER_OSPEEDR13 |
                    GPIO_OSPEEDER_OSPEEDR12 | GPIO_OSPEEDER_OSPEEDR11;
  GPIOC->OSPEEDR |=
      GPIO_OSPEEDER_OSPEEDR5 | GPIO_OSPEEDER_OSPEEDR4 | GPIO_OSPEEDER_OSPEEDR1;

  GPIOA->AFR[0] |= 0xB0000BB0; // mac
  GPIOB->AFR[1] |= 0x00BBB000; // mac
  GPIOC->AFR[0] |= 0x00BB00B0; // mac

  // разраешение тактирования МАС, МАС прд, МАС прм
  RCC->AHB1ENR |=
      RCC_AHB1ENR_ETHMACRXEN | RCC_AHB1ENR_ETHMACTXEN | RCC_AHB1ENR_ETHMACEN;

  // сброс езернет
  RCC->AHB1RSTR |= RCC_AHB1RSTR_ETHMACRST;
  RCC->AHB1RSTR &= ~RCC_AHB1RSTR_ETHMACRST;

  // программный сброс
  ETH->DMABMR |= ETH_DMABMR_SR;
  while (ETH->DMABMR & ETH_DMABMR_SR)
    ;

  // сброс phy
  GPIOE->ODR = GPIO_ODR_ODR_12; // rst=1
  ETH->MACMIIDR = 0x00008000;   // soft restort
  ETH->MACMIIAR = 0x00000803;   // adr=1, reg=0,write
  while (ETH->MACMIIAR & 0x00000001)
    ;

  ETH->MACMIIAR = 0x00000801; // adr=1, reg=0,read
  while (ETH->MACMIIAR & 0x00000001)
    ;
  while ((ETH->MACMIIDR & 0x00008000) == 0x00008000) // risit is done?
  {                                                  // no
    ETH->MACMIIAR = 0x00000801;                      // adr=1, reg=0,read
    while (ETH->MACMIIAR & 0x00000001)
      ;
  }

  // проверка link статуса phy

  ETH->MACMIIAR = 0x00000841; // adr=1, reg=1,read
  while (ETH->MACMIIAR & 0x00000001)
    ;
  while ((ETH->MACMIIDR & 0x00000004) != 0x00000004) // link is up?
  {                                                  // no
    ETH->MACMIIAR = 0x00000841;                      // adr=1, reg=1,read
    while (ETH->MACMIIAR & 0x00000001)
      ;
  }

  // установка автосогласования в phy
  ETH->MACMIIDR = 0x00001000; // outo-negotiation
  ETH->MACMIIAR = 0x00000803; // adr=1, reg=0,write
  while (ETH->MACMIIAR & 0x00000001)
    ;

  // чтение результата автосогласования
  for (uint32_t i = 0; i < 50000; i++) {
    ETH->MACMIIAR = 0x00000fc1; // adr=1, reg=31,read
    while (ETH->MACMIIAR & 0x00000001)
      ;
    while (!(ETH->MACMIIDR & 0x00001000)) // outo-neg done?
    {                                     // no
      ETH->MACMIIAR = 0x00000fc1;         // adr=1, reg=31,read
      while (ETH->MACMIIAR & 0x00000001)
        ;
    }
  }

  // настройка регистра MACCR
  ETH->MACCR = 0x02008000 | ETH_MACCR_APCS; //
  switch (ETH->MACMIIDR) {
  case 0x00001044:
    ETH->MACCR |= 0x00008000; // 10,h
    break;
  case 0x00001054:
    ETH->MACCR |= 0x00008800; // 10,f
    break;
  case 0x00001048:
    ETH->MACCR |= 0x0000c000; // 100,h
    break;
  case 0x00001058:
    ETH->MACCR |= 0x0000c800; // 100,f
    break;
  default:;
    break;
  }

  // настройка регистра MACFFR
  ETH->MACFFR =
      ETH_MACFFR_RA | ETH_MACFFR_PAM | ETH_MACFFR_PM; // all frames receive

  // настройка регистра DMAOMR
  ETH->DMAOMR = ETH_DMAOMR_RSF | ETH_DMAOMR_TSF;

  // настройка регистра DMABMR
  ETH->DMABMR = ETH_DMABMR_FB | ETH_DMABMR_AAB;

  // инициализация списка дескрипторов прм и регистра DMARDLAR
  ETH->DMARDLAR = (uint32_t)(&RXDL[0]);
  RXDL[0] = 0x80000000; // own=1
  RXDL[1] = 0x000045fc; // rch=1, размер RX_BUF=1532
  RXDL[2] = (uint32_t)(&RX_BUF[0]);
  RXDL[3] = (uint32_t)(&RXDL[0]);

  // разрешение МАС приема и ДМА приема
  ETH->MACCR |= ETH_MACCR_RE;
  ETH->DMAOMR |= ETH_DMAOMR_SR;

  // проверка приема фрейма в буфер (дескриптор слово 0, own и ls биты)
  while ((RXDL[0] & 0x80000100) != 0x00000100)
    ;
}
/* USER CODE END 4 */

/**
 * @brief  Period elapsed callback in non blocking mode
 * @note   This function is called  when TIM14 interrupt took place, inside
 * HAL_TIM_IRQHandler(). It makes a direct call to HAL_IncTick() to increment
 * a global variable "uwTick" used as application time base.
 * @param  htim : TIM handle
 * @retval None
 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  /* USER CODE BEGIN Callback 0 */

  /* USER CODE END Callback 0 */
  if (htim->Instance == TIM14) {
    HAL_IncTick();
  }
  /* USER CODE BEGIN Callback 1 */

  /* USER CODE END Callback 1 */
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void) {
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1) {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line) {
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line
     number, ex: printf("Wrong parameters value: file %s on line %d\r\n", file,
     line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
