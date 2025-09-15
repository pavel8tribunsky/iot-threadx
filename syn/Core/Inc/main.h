/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define TMR_Pin GPIO_PIN_2
#define TMR_GPIO_Port GPIOE
#define RC_Pin GPIO_PIN_3
#define RC_GPIO_Port GPIOE
#define ALM_Pin GPIO_PIN_4
#define ALM_GPIO_Port GPIOE
#define PSO_Pin GPIO_PIN_5
#define PSO_GPIO_Port GPIOE
#define RF_EN_Pin GPIO_PIN_13
#define RF_EN_GPIO_Port GPIOC
#define TX_MOD_Pin GPIO_PIN_8
#define TX_MOD_GPIO_Port GPIOE
#define MW_ID0_Pin GPIO_PIN_11
#define MW_ID0_GPIO_Port GPIOE
#define RS485_NRE_Pin GPIO_PIN_13
#define RS485_NRE_GPIO_Port GPIOE
#define RS485_DE_Pin GPIO_PIN_14
#define RS485_DE_GPIO_Port GPIOE
#define MW_ID1_Pin GPIO_PIN_15
#define MW_ID1_GPIO_Port GPIOE
#define SPI2_NSS_Pin GPIO_PIN_12
#define SPI2_NSS_GPIO_Port GPIOB
#define LED_BLU_Pin GPIO_PIN_8
#define LED_BLU_GPIO_Port GPIOD
#define LED_RED_Pin GPIO_PIN_9
#define LED_RED_GPIO_Port GPIOD
#define PLL_TDT_Pin GPIO_PIN_10
#define PLL_TDT_GPIO_Port GPIOD
#define LED_GRN_Pin GPIO_PIN_11
#define LED_GRN_GPIO_Port GPIOD
#define CVR_Pin GPIO_PIN_15
#define CVR_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
