/*
  ******************************************************************************
  * @file    stm32f4xx_hal.h
  * @author  MCD Application Team
  * @brief   This file contains all the functions prototypes for the HAL 
  *          module driver.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */ 

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_HAL_H
#define __STM32F4xx_HAL_H


//Data type aliases
typedef unsigned int uint32_t;
typedef unsigned short int uint16_t;

#define PWR_REGULATOR_VOLTAGE_SCALE3 0x0F
#define FLASH_LATENCY_0 0x0000EEFF
#define GPIO_PIN_5 0x0020
#define LED_Pin GPIO_PIN_5
#define GPIOA ((GPIO_TypeDef *)0xFF942300)

/** @defgroup RCC_Oscillator_Type Oscillator Type
  * @{
  */
#define RCC_OSCILLATORTYPE_HSI             0x00000002U
/** @defgroup RCC_HSI_Config HSI Config
  * @{
  */
#define RCC_HSI_OFF                      ((unsigned char)0x00)
#define RCC_HSI_ON                       ((unsigned char)0x01)
#define RCC_HSICALIBRATION_DEFAULT       0x10U         /* Default HSI calibration trimming value */

#define RCC_PLL_NONE                      ((unsigned char)0x00)

/** @defgroup RCC_System_Clock_Type System Clock Type
  * @{
  */
#define RCC_CLOCKTYPE_SYSCLK             0x00000001U
#define RCC_CLOCKTYPE_HCLK               0x00000002U
#define RCC_CLOCKTYPE_PCLK1              0x00000004U
#define RCC_CLOCKTYPE_PCLK2              0x00000008U

/** @defgroup RCC_System_Clock_Source System Clock Source
  * @note     The RCC_SYSCLKSOURCE_PLLRCLK parameter is available only for
  *           STM32F446xx devices.
  * @{
  */
#define RCC_CFGR_SW_HSI                  0x00000000U
#define RCC_SYSCLKSOURCE_HSI             RCC_CFGR_SW_HSI

/** @defgroup RCC_AHB_Clock_Source AHB Clock Source
  * @{
  */
#define RCC_SYSCLK_DIV1                  0x00000000U
#define RCC_HCLK_DIV1                    0x00000000U


#define  GPIO_MODE_OUTPUT_PP             0x1UL
#define  GPIO_NOPULL                     0x00000000U   /*!< No Pull-up or Pull-down activation  */
#define  GPIO_SPEED_FREQ_LOW             0x00000000U  /*!< IO works at 2 MHz, please refer to the product datasheet */


#define __HAL_RCC_PWR_CLK_ENABLE()	(1)
#define __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3)	(PWR_REGULATOR_VOLTAGE_SCALE3)
#define __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3)	(PWR_REGULATOR_VOLTAGE_SCALE3)
#define __HAL_RCC_GPIOA_CLK_ENABLE()	(1)
#define __disable_irq() (1)


/**
  * @brief  RCC PLL configuration structure definition
  */
typedef struct
{
  uint32_t PLLState;   /*!< The new state of the PLL.
                            This parameter can be a value of @ref RCC_PLL_Config                      */

  uint32_t PLLSource;  /*!< RCC_PLLSource: PLL entry clock source.
                            This parameter must be a value of @ref RCC_PLL_Clock_Source               */

  uint32_t PLLM;       /*!< PLLM: Division factor for PLL VCO input clock.
                            This parameter must be a number between Min_Data = 0 and Max_Data = 63    */

  uint32_t PLLN;       /*!< PLLN: Multiplication factor for PLL VCO output clock.
                            This parameter must be a number between Min_Data = 50 and Max_Data = 432 
                            except for STM32F411xE devices where the Min_Data = 192 */

  uint32_t PLLP;       /*!< PLLP: Division factor for main system clock (SYSCLK).
                            This parameter must be a value of @ref RCC_PLLP_Clock_Divider             */

  uint32_t PLLQ;       /*!< PLLQ: Division factor for OTG FS, SDIO and RNG clocks.
                            This parameter must be a number between Min_Data = 2 and Max_Data = 15    */
}RCC_PLLInitTypeDef;


/**
  * @brief  RCC Internal/External Oscillator (HSE, HSI, LSE and LSI) configuration structure definition
  */
typedef struct
{
  uint32_t OscillatorType;       /*!< The oscillators to be configured.
                                      This parameter can be a value of @ref RCC_Oscillator_Type                   */

  uint32_t HSEState;             /*!< The new state of the HSE.
                                      This parameter can be a value of @ref RCC_HSE_Config                        */

  uint32_t LSEState;             /*!< The new state of the LSE.
                                      This parameter can be a value of @ref RCC_LSE_Config                        */

  uint32_t HSIState;             /*!< The new state of the HSI.
                                      This parameter can be a value of @ref RCC_HSI_Config                        */

  uint32_t HSICalibrationValue;  /*!< The HSI calibration trimming value (default is RCC_HSICALIBRATION_DEFAULT).
                                       This parameter must be a number between Min_Data = 0x00 and Max_Data = 0x1F */

  uint32_t LSIState;             /*!< The new state of the LSI.
                                      This parameter can be a value of @ref RCC_LSI_Config                        */

  RCC_PLLInitTypeDef PLL;        /*!< PLL structure parameters                                                    */
}RCC_OscInitTypeDef;


/**
  * @brief  RCC System, AHB and APB busses clock configuration structure definition
  */
typedef struct
{
  uint32_t ClockType;             /*!< The clock to be configured.
                                       This parameter can be a value of @ref RCC_System_Clock_Type      */

  uint32_t SYSCLKSource;          /*!< The clock source (SYSCLKS) used as system clock.
                                       This parameter can be a value of @ref RCC_System_Clock_Source    */

  uint32_t AHBCLKDivider;         /*!< The AHB clock (HCLK) divider. This clock is derived from the system clock (SYSCLK).
                                       This parameter can be a value of @ref RCC_AHB_Clock_Source       */

  uint32_t APB1CLKDivider;        /*!< The APB1 clock (PCLK1) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

  uint32_t APB2CLKDivider;        /*!< The APB2 clock (PCLK2) divider. This clock is derived from the AHB clock (HCLK).
                                       This parameter can be a value of @ref RCC_APB1_APB2_Clock_Source */

}RCC_ClkInitTypeDef;


/** 
  * @brief GPIO Init structure definition  
  */ 
typedef struct
{
  uint32_t Pin;       /*!< Specifies the GPIO pins to be configured.
                           This parameter can be any value of @ref GPIO_pins_define */

  uint32_t Mode;      /*!< Specifies the operating mode for the selected pins.
                           This parameter can be a value of @ref GPIO_mode_define */

  uint32_t Pull;      /*!< Specifies the Pull-up or Pull-Down activation for the selected pins.
                           This parameter can be a value of @ref GPIO_pull_define */

  uint32_t Speed;     /*!< Specifies the speed for the selected pins.
                           This parameter can be a value of @ref GPIO_speed_define */

  uint32_t Alternate;  /*!< Peripheral to be connected to the selected pins. 
                            This parameter can be a value of @ref GPIO_Alternate_function_selection */
}GPIO_InitTypeDef;

/** 
  * @brief General Purpose I/O
  */

typedef struct
{
  uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
  uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
  uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
  uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
  uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
  uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
  uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
  uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
  uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

/** 
  * @brief  GPIO Bit SET and Bit RESET enumeration 
  */
typedef enum
{
  GPIO_PIN_RESET = 0,
  GPIO_PIN_SET
}GPIO_PinState;

/** 
  * @brief  HAL Status structures definition  
  */  
typedef enum 
{
  HAL_OK       = 0x00U,
  HAL_ERROR    = 0x01U,
  HAL_BUSY     = 0x02U,
  HAL_TIMEOUT  = 0x03U
} HAL_StatusTypeDef;


void HAL_Init();
HAL_StatusTypeDef HAL_RCC_OscConfig(RCC_OscInitTypeDef *RCC_OscInitStruct);
void HAL_GPIO_TogglePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);
HAL_StatusTypeDef HAL_RCC_ClockConfig(RCC_ClkInitTypeDef  *RCC_ClkInitStruct, uint32_t FLatency);
void HAL_GPIO_WritePin(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, GPIO_PinState PinState);
void HAL_GPIO_Init(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Init);


#endif
