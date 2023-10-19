/*
 * UART.c
 *
 *  Created on: Oct 19, 2023
 *      Author: adithyam
 */


#include"stdint.h"
#include"UART.h"
#include"SC.h"

void UARTconfig()
{
	uint32_t *USART1_CR1,*USART1_CR2,*RCC_APB2ENR,*USART_TDR,*USART_ISR,*USART_BRR,*GPIO_C,*RCC_AHBENR,*GPIO_AFR,*GPIO_AFRL,*GPIO_MODER,* GPIOx_ODR,*USART_RDR;
	USART1_CR1=(uint32_t *)0x40013800;
	USART1_CR2=(uint32_t *)0x40013804;
	RCC_APB2ENR=(uint32_t*)0x40021018;
	USART_TDR=(uint32_t*)0x40013828;
   USART_ISR=(uint32_t*)0x4001381c;
   USART_BRR=(uint32_t *)0x4001380c;
   RCC_AHBENR=(uint32_t*)0x40021014;
   GPIO_MODER=(uint32_t*)0x48001000;
   GPIOx_ODR=(uint32_t*)0x48001014;
   USART_RDR=(uint32_t*)0x40013824;
   setbit(RCC_AHBENR,19);
   setbit(RCC_APB2ENR,14);
   *USART_BRR=0x341;
   GPIO_C=(uint32_t*)0x48000800;
   setbit(GPIO_C,11);
   setbit(GPIO_C,9);
   setbit(RCC_AHBENR,21);
   GPIO_AFRL=(uint32_t*)0x48000820;
   *GPIO_AFRL =*GPIO_AFRL| (7<<16);
   *GPIO_AFRL =*GPIO_AFRL| (7<<20);
   setbit(GPIO_MODER,30);
   setbit(USART1_CR1,0);
   setbit(USART1_CR1,2);
   setbit(USART1_CR1,3);


}
