/*
 * stm32f411re.h
 *
 *  Created on: Aug 10, 2026
 *      Author: Tony
 */

#ifndef INC_STM32F411RE_H_
#define INC_STM32F411RE_H_

#include<stdint.h>

#define __vo volatile
//-----------------------------------------------------------MEMORY ADDRESSES-----------------------------------------------------------
//Base memory general addresses
#define FLASH_BASEADDR						0x08000000U
#define SRAM1_BASEADDR						0x20000000U
#define ROM_BASEADDR						0x1FFF0000U
#define SRAM								SRAM1_BASEADDR

//Base memory buses addresses
#define PERIPHERAL_BASEADDR					0x40000000U
#define	BUS_APB1_BASEADDR					PERIPHERAL_BASEADDR
#define	BUS_APB2_BASEADDR					0x40010000U
#define	BUS_AHB1_BASEADDR					0x40020000U
#define	BUS_AHB2_BASEADDR					0x50000000U

//APB1 memory addresses
#define APB1_TIM2_BASEADDR					(BUS_APB1_BASEADDR + 0x0000)
#define APB1_TIM3_BASEADDR					(BUS_APB1_BASEADDR + 0x0400)
#define APB1_TIM4_BASEADDR					(BUS_APB1_BASEADDR + 0x0800)
#define APB1_TIM5_BASEADDR					(BUS_APB1_BASEADDR + 0x0C00)
#define APB1_RTC_BKP_BASEADDR				(BUS_APB1_BASEADDR + 0x2800)
#define APB1_WWDG_BASEADDR					(BUS_APB1_BASEADDR + 0x2C00)
#define APB1_IWDG_BASEADDR					(BUS_APB1_BASEADDR + 0x3000)
#define APB1_I2S2_EXT_BASEADDR				(BUS_APB1_BASEADDR + 0x3400)
#define APB1_SPI2_I2S2_BASEADDR				(BUS_APB1_BASEADDR + 0x3800)
#define APB1_SPI3_I2S3_BASEADDR				(BUS_APB1_BASEADDR + 0x3C00)
#define APB1_I2S3_EXT_BASEADDR				(BUS_APB1_BASEADDR + 0x4000)
#define APB1_USART2_BASEADDR				(BUS_APB1_BASEADDR + 0x4400)
#define APB1_I2C1_BASEADDR					(BUS_APB1_BASEADDR + 0x5400)
#define APB1_I2C2_BASEADDR					(BUS_APB1_BASEADDR + 0x5800)
#define APB1_I2C3_BASEADDR					(BUS_APB1_BASEADDR + 0x5C00)
#define APB1_PWR_BASEADDR					(BUS_APB1_BASEADDR + 0x7000)

//ABP2 memory addresses
#define APB2_TIM1_BASEADDR					(BUS_APB2_BASEADDR + 0x0000)
#define APB2_USART1_BASEADDR				(BUS_APB2_BASEADDR + 0x1000)
#define APB2_USART6_BASEADDR				(BUS_APB2_BASEADDR + 0x1400)
#define APB2_ADC1_BASEADDR					(BUS_APB2_BASEADDR + 0x2000)
#define APB2_SDIO_BASEADDR					(BUS_APB2_BASEADDR + 0x2C00)
#define APB2_SPI1_I2S1_BASEADDR				(BUS_APB2_BASEADDR + 0x3000)
#define APB2_SPI4_I2S4_BASEADDR				(BUS_APB2_BASEADDR + 0x3400)
#define APB2_SYSCFG_BASEADDR				(BUS_APB2_BASEADDR + 0x3800)
#define APB2_EXTI_BASEADDR					(BUS_APB2_BASEADDR + 0x3C00)
#define APB2_TIM9_BASEADDR					(BUS_APB2_BASEADDR + 0x4000)
#define APB2_TIM10_BASEADDR					(BUS_APB2_BASEADDR + 0x4400)
#define APB2_TIM11_BASEADDR					(BUS_APB2_BASEADDR + 0x4800)
#define APB2_SPI5_I2S5_BASEADDR				(BUS_APB2_BASEADDR + 0x5000)

//AHB1 memory addresses
#define AHB1_GPIOA_BASEADDR					(BUS_AHB1_BASEADDR + 0x0000)
#define AHB1_GPIOB_BASEADDR					(BUS_AHB1_BASEADDR + 0x0400)
#define AHB1_GPIOC_BASEADDR					(BUS_AHB1_BASEADDR + 0x0800)
#define AHB1_GPIOD_BASEADDR					(BUS_AHB1_BASEADDR + 0x0C00)
#define AHB1_GPIOE_BASEADDR					(BUS_AHB1_BASEADDR + 0x1000)
#define AHB1_GPIOH_BASEADDR					(BUS_AHB1_BASEADDR + 0x1C00)
#define AHB1_CRC_BASEADDR					(BUS_AHB1_BASEADDR + 0x3000)
#define AHB1_RCC_BASEADDR					(BUS_AHB1_BASEADDR + 0x3800)
#define AHB1_FLASH_INTERFACE_REG_BASEADDR	(BUS_AHB1_BASEADDR + 0x3C00)
#define AHB1_DMA1_BASEADDR					(BUS_AHB1_BASEADDR + 0x6000)
#define AHB1_DMA2_BASEADDR					(BUS_AHB1_BASEADDR + 0x6400)

//AHB2 memory addresses
#define AHB2_USB_OTG_FS_BASEADDR			(BUS_AHB2_BASEADDR + 0x0000)

//-----------------------------------------------------------DEFINITION STRUCTURES-----------------------------------------------------------

//Flash Interface Register
typedef struct
{
	__vo uint32_t ACR;						//Flash access control register
	__vo uint32_t KEYR;						//Flash key register
	__vo uint32_t OPTKEYR;					//Flash option key register
	__vo uint32_t SR;						//Flash status register
	__vo uint32_t CR;						//Flash control register
	__vo uint32_t OPTCR;					//Flash option control register
}Flash_Interace_Reg_t;

//CRC Register
typedef struct
{
	__vo uint32_t DR;						//Data register
	__vo uint32_t IDR;						//Independent data register
	__vo uint32_t CR;						//Control register
}CRC_Reg_t;

//PWR Register
typedef struct
{
	__vo uint32_t CR;						//PWR power control register
	__vo uint32_t CSR;						//PWR power control/status register
}PWR_Reg_t;

//RCC Register
typedef struct
{
	__vo uint32_t CR;						//RCC clock control register
	__vo uint32_t PLLCFGR;					//RCC PLL configuration register
	__vo uint32_t CFGR;						//RCC clock configuration register
	__vo uint32_t CIR;						//RCC clock interrupt register
	__vo uint32_t AHB1RSTR;					//RCC AHB1 peripheral reset register
	__vo uint32_t AHB2RSTR;					//RCC AHB2 peripheral reset register
	uint32_t Reserved1;
	uint32_t Reserved2;
	__vo uint32_t APB1RSTR;					//RCC APB1 peripheral reset register for
	__vo uint32_t APB2RSTR;					//RCC APB2 peripheral reset register
	uint32_t Reserved3;
	uint32_t Reserved4;
	__vo uint32_t AHB1ENR;					//RCC AHB1 peripheral clock enable register
	__vo uint32_t AHB2ENR;					//RCC AHB2 peripheral clock enable register
	uint32_t Reserved5;
	uint32_t Reserved6;
	__vo uint32_t APB1ENR;					//RCC APB1 peripheral clock enable register
	__vo uint32_t APB2ENR;					//RCC APB2 peripheral clock enable register
	uint32_t Reserved7;
	uint32_t Reserved8;
	__vo uint32_t AHB1LPENR;				//RCC AHB1 peripheral clock enable in low power mode register
	__vo uint32_t AHB2LPENR;				//RCC AHB2 peripheral clock enable in low power mode register
	uint32_t Reserved9;
	uint32_t Reserved10;
	__vo uint32_t APB1LPENR;				//RCC APB1 peripheral clock enable in low power mode register
	__vo uint32_t APB2LPENR;				//RCC APB2 peripheral clock enabled in low power mode register
	uint32_t Reserved11;
	uint32_t Reserved12;
	__vo uint32_t BDCR;						//RCC Backup domain control register
	__vo uint32_t CSR;						//RCC clock control & status register
	uint32_t Reserved13;
	uint32_t Reserved14;
	__vo uint32_t SSCGR;					//RCC spread spectrum clock generation register
	__vo uint32_t PLLI2SCFGR;				//RCC PLLI2S configuration register
	uint32_t Reserved15;
	__vo uint32_t DCKCFGR;					//RCC Dedicated Clocks Configuration Register
}RCC_Reg_t;

//SYSCFG Register
typedef struct
{
	__vo uint32_t MEMRMP;					//SYSCFG memory remap register
	__vo uint32_t PMC;						//SYSCFG peripheral mode configuration register
	__vo uint32_t EXTICR1;					//SYSCFG external interrupt configuration register 1
	__vo uint32_t EXTICR2;					//SYSCFG external interrupt configuration register 2
	__vo uint32_t EXTICR3;					//SYSCFG external interrupt configuration register 3
	__vo uint32_t EXTICR4;					//SYSCFG external interrupt configuration register 4
	__vo uint32_t CMPCR;					//Compensation cell control register
}SYSCFG_Reg_t;

//GPIOx Register
typedef struct
{
	__vo uint32_t MODER;					//GPIO port mode register
	__vo uint32_t OTYPER;					//GPIO port output type register
	__vo uint32_t OSPEEDR;					//GPIO port output speed register
	__vo uint32_t PUPDR;					//GPIO port pull-up/pull-down register
	__vo uint32_t IDR;						//GPIO port input data register
	__vo uint32_t ODR;						//GPIO port output data register
	__vo uint32_t BSRR;						//GPIO port bit set/reset register
	__vo uint32_t LCKR;						//GPIO port configuration lock register
	__vo uint32_t AFR[2];					//GPIO alternate function low register([0]), GPIO alternate function high register([1])
}GPIOx_Reg_t;

//DMA Register
typedef struct
{
	__vo uint32_t LISR;						//DMA low interrupt status register
	__vo uint32_t HISR;						//DMA high interrupt status register
	__vo uint32_t LIFCR;					//DMA low interrupt flag clear register
	__vo uint32_t HIFCR;					//DMA high interrupt flag clear register
	__vo uint32_t SxCR;						//DMA stream x configuration register
	__vo uint32_t SxNDTR;					//DMA stream x number of data register
	__vo uint32_t SxPAR;					//DMA stream x peripheral address register
	__vo uint32_t SxM0AR;					//DMA stream x memory 0 address register
	__vo uint32_t SxM1AR;					//DMA stream x memory 1 address register
	__vo uint32_t SxFCR;					//DMA stream x FIFO control register
}DMA_Reg_t;

//todo: fill the missing registers structs

//-----------------------------------------------------------Peripheral Definition-----------------------------------------------------------
//GPIO Peripheral definition
#define GPIOA								((GPIOx_Reg_t*) AHB1_GPIOA_BASEADDR)
#define GPIOB								((GPIOx_Reg_t*) AHB1_GPIOB_BASEADDR)
#define GPIOC								((GPIOx_Reg_t*) AHB1_GPIOC_BASEADDR)
#define GPIOD								((GPIOx_Reg_t*) AHB1_GPIOD_BASEADDR)
#define GPIOE								((GPIOx_Reg_t*) AHB1_GPIOE_BASEADDR)
#define GPIOH								((GPIOx_Reg_t*) AHB1_GPIOH_BASEADDR)

//RCC Peripheral definition
#define RCC 								((RCC_Reg_t*) AHB1_RCC_BASEADDR)

//todo: fill the missing peripheral definitions
//-----------------------------------------------------------Clock Enable Macros-----------------------------------------------------------

#define GPIOA_RCC_EN()						(RCC -> AHB1ENR |= (1 << 0))
#define GPIOB_RCC_EN()						(RCC -> AHB1ENR |= (1 << 1))
#define GPIOC_RCC_EN()						(RCC -> AHB1ENR |= (1 << 2))
#define GPIOD_RCC_EN()						(RCC -> AHB1ENR |= (1 << 3))
#define GPIOE_RCC_EN()						(RCC -> AHB1ENR |= (1 << 4))
#define GPIOH_RCC_EN()						(RCC -> AHB1ENR |= (1 << 7))

//todo: fill the missing clock enable macros
//-----------------------------------------------------------Clock Disable Macros-----------------------------------------------------------
#define GPIOA_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 0))
#define GPIOB_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 1))
#define GPIOC_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 2))
#define GPIOD_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 3))
#define GPIOE_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 4))
#define GPIOH_RCC_DI()						(RCC -> AHB1ENR &= ~(1 << 7))

//todo: fill the missing clock disable macros
//-----------------------------------------------------------Clock Reset Macros-----------------------------------------------------------
#define GPIOA_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 0)); (RCC -> AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 1)); (RCC -> AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 2)); (RCC -> AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 3)); (RCC -> AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 4)); (RCC -> AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOH_RCC_RESET()					do {(RCC -> AHB1RSTR |= (1 << 7)); (RCC -> AHB1RSTR &= ~(1 << 7)); } while(0)

//todo: fill the missing clock reset macros
//-----------------------------------------------------------Generic Macros-----------------------------------------------------------
#define HIGH								1
#define LOW									0
#define SET									HIGH
#define RESET								LOW
#define ENABLE								HIGH
#define DISABLE								LOW
#define GPIO_PIN_SET						HIGH
#define GPIO_PIN_RESET						LOW
#endif /* INC_STM32F411RE_H_ */
