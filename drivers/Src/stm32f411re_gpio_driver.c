/*
 * stm32f411re_gpio_driver.c
 *
 *  Created on: Aug 12, 2026
 *      Author: Tony
 */


#include "stm32f411re_gpio_driver.h"


void GPIO_PeripheralClockControl(GPIOx_Reg_t *pGPIOx, uint8_t EnableOrDisable)
{
	if(EnableOrDisable == ENABLE)
	{
		switch((uint32_t)pGPIOx)
		{
		case(uint32_t)GPIOA: GPIOA_RCC_EN(); break;
		case(uint32_t)GPIOB: GPIOB_RCC_EN(); break;
		case(uint32_t)GPIOC: GPIOC_RCC_EN(); break;
		case(uint32_t)GPIOD: GPIOD_RCC_EN(); break;
		case(uint32_t)GPIOE: GPIOE_RCC_EN(); break;
		case(uint32_t)GPIOH: GPIOH_RCC_EN(); break;
		}
	}else
	{
		switch((uint32_t)pGPIOx)
		{
		case(uint32_t)GPIOA: GPIOA_RCC_DI(); break;
		case(uint32_t)GPIOB: GPIOB_RCC_DI(); break;
		case(uint32_t)GPIOC: GPIOC_RCC_DI(); break;
		case(uint32_t)GPIOD: GPIOD_RCC_DI(); break;
		case(uint32_t)GPIOE: GPIOE_RCC_DI(); break;
		case(uint32_t)GPIOH: GPIOH_RCC_DI(); break;
		}
	}
}


void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	uint32_t temp = 0;
	if(pGPIOHandle->GPIO_Pin_Config.GPIO_PinMode <= GPIO_PIN_MODE_ANA)
	{
		//GPIO Pin Mode
		temp = (pGPIOHandle->GPIO_Pin_Config.GPIO_PinMode << (2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
	}else
	{
		//todo: This is where the interrupts go
	}
	temp = 0;

	//GPIO Pin Speed
	temp = (pGPIOHandle->GPIO_Pin_Config.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR &= ~(0x3 <<(2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDR |= temp;

	temp = 0;
	//GPIO Output Type
	temp = (pGPIOHandle->GPIO_Pin_Config.GPIO_PinPUPD << (pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	temp = 0;
	//GPIO PUPD
	temp = (pGPIOHandle->GPIO_Pin_Config.GPIO_PinPUPD << (2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	temp = 0;
	//GPIO Pin Alt Function Mode
	if(pGPIOHandle->GPIO_Pin_Config.GPIO_PinMode == GPIO_PIN_MODE_ALT)
	{
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_Pin_Config.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<(4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_Pin_Config.GPIO_PinAltFuncMode << (4 * temp2));
	}
}
void GPIO_Deinit(GPIOx_Reg_t *gGPIOx)
{
	switch((uint32_t)gGPIOx)
	{
	case(uint32_t)GPIOA: GPIOA_RCC_RESET(); break;
	case(uint32_t)GPIOB: GPIOB_RCC_RESET(); break;
	case(uint32_t)GPIOC: GPIOC_RCC_RESET(); break;
	case(uint32_t)GPIOD: GPIOD_RCC_RESET(); break;
	case(uint32_t)GPIOE: GPIOE_RCC_RESET(); break;
	case(uint32_t)GPIOH: GPIOH_RCC_RESET(); break;
	}
}

uint8_t GPIO_ReadFromInputPin(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber)
{
	uint8_t value;
	value = (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x00000001);
	return value;
}

uint16_t GPIO_ReadFromInputPort(GPIOx_Reg_t *pGPIOx)
{
	uint16_t value;
	value = (uint16_t)pGPIOx->IDR;
	return value;
}
void GPIO_WriteToOutputPin(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIOx_Reg_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR |= Value;
}
void GPIO_ToggleOutputPort(GPIOx_Reg_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}
