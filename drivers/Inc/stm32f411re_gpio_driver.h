/*
 * stm32f411re_gpio_driver.h
 *
 *  Created on: Aug 11, 2026
 *      Author: Tony
 */

#ifndef INC_STM32F411RE_GPIO_DRIVER_H_
#define INC_STM32F411RE_GPIO_DRIVER_H_

#include "stm32f411re.h"


//-----------------------------------------------------------Pin Configuration-----------------------------------------------------------

//Pin Configuration Structure
typedef struct
{
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinOutputType;
	uint8_t GPIO_PinPUPD;
	uint8_t GPIO_PinAltFuncMode;
}GPIO_Pin_Config_t;

//This is used to handle the pin with the correct GPIOx and config
typedef struct
{
	GPIOx_Reg_t *pGPIOx;
	GPIO_Pin_Config_t GPIO_Pin_Config;
}GPIO_Handle_t;

//GPIOx Pin Numbers
#define GPIO_PIN_NUMBER_0							0
#define GPIO_PIN_NUMBER_1							1
#define GPIO_PIN_NUMBER_2							2
#define GPIO_PIN_NUMBER_3							3
#define GPIO_PIN_NUMBER_4							4
#define GPIO_PIN_NUMBER_5							5
#define GPIO_PIN_NUMBER_6							6
#define GPIO_PIN_NUMBER_7							7
#define GPIO_PIN_NUMBER_8							8
#define GPIO_PIN_NUMBER_9							9
#define GPIO_PIN_NUMBER_10							10
#define GPIO_PIN_NUMBER_11							11
#define GPIO_PIN_NUMBER_12							12
#define GPIO_PIN_NUMBER_13							13
#define GPIO_PIN_NUMBER_14							14
#define GPIO_PIN_NUMBER_15							15

//GPIO Pin Modes
#define GPIO_PIN_MODE_INPUT							0
#define GPIO_PIN_MODE_OUTPUT						1
#define GPIO_PIN_MODE_ALT							2
#define GPIO_PIN_MODE_ANA							3
#define GPIO_PIN_MODE_IT_FT							4
#define GPIO_PIN_MODE_IT_RT							5
#define GPIO_PIN_MODE_IT_RFT						6

//GPIO Pin Speed
#define GPIO_PIN_OUTPUT_SPEED_LW					0
#define GPIO_PIN_OUTPUT_SPEED_MD					1
#define GPIO_PIN_OUTPUT_SPEED_FS					2
#define GPIO_PIN_OUTPUT_SPEED_HG					3

//GPIO Output Type
#define GPIO_PIN_OUTPUT_TYPE_PP						0
#define GPIO_PIN_OUTPUT_TYPE_OD						1

//GPIO PUPD controll
#define GPIO_PIN_OUTPUT_PUPD_NOPUPD					0
#define GPIO_PIN_OUTPUT_PUPD_PU						0
#define GPIO_PIN_OUTPUT_PUPD_PD						0


//-----------------------------------------------------------API Prototypes-----------------------------------------------------------
//RCC controll function
void GPIO_PeripheralClockControl(GPIOx_Reg_t *pGPIOx, uint8_t EnableOrDisable);

//Setup
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_Deinit(GPIOx_Reg_t *gGPIOx);

//Data Read and Write
uint8_t GPIO_ReadFromInputPin(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIOx_Reg_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIOx_Reg_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPort(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber);
#endif /* INC_STM32F411RE_GPIO_DRIVER_H_ */
