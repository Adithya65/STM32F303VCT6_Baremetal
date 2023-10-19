/*
 * SPI.c
 *
 *  Created on: Oct 19, 2023
 *      Author: adithyam
 */

#include"SPI.h"
#include"SC.h"
#include"stdint.h"


void SPIconfig()

{
	uint32_t *RCC_AHBENR,*GPIOA_MODER,*GPIOE_MODER,*GPIOA_AFRL,*GPIOE_AFRL,*SPI1_CR1,*SPI1_CR2,*RCC_APB2ENR,*SPI1_SR,*SPI1_DR,*GPIOE_ODR;
	int i;
	RCC_AHBENR=(uint32_t*)0x40021014;
	GPIOA_MODER=(uint32_t*)0x48000000;
	GPIOE_MODER=(uint32_t*)0x48001000;
	GPIOA_AFRL=(uint32_t*)0x48000020;
	GPIOE_AFRL=(uint32_t*)0x48001020;
	SPI1_CR1=(uint32_t*)0x40013000;
	SPI1_CR2=(uint32_t*)0x40013004;
	RCC_APB2ENR=(uint32_t*)0x40021018;
	SPI1_SR=(uint32_t*)0x40013008;
	SPI1_DR=(uint32_t*)0x4001300c;
	GPIOE_ODR=(uint32_t*)0x48001014;


	setbit(RCC_APB2ENR,12);//clock for SPI1
	setbit(RCC_AHBENR,17); //clock for GPIOA
	setbit(RCC_AHBENR,21); //clock for GPIOE
	setbit(GPIOE_MODER,6); //output mode for GPIOE
	setbit(GPIOA_MODER,11); //set mode-AF 5
	setbit(GPIOA_MODER,13); //set mode-AF 6
	setbit(GPIOA_MODER,15); //set mode-AF 7
	setbit(GPIOA_AFRL,20); //AFRL 5 for GPIOA
	setbit(GPIOA_AFRL,22); //AFRL 5 for GPIOA
	setbit(GPIOA_AFRL,24); //AFRL 5 for GPIOA
	setbit(GPIOA_AFRL,26); //AFRL 5 for GPIOA
	setbit(GPIOA_AFRL,28); //AFRL 5 for GPIOA
	setbit(GPIOA_AFRL,30); //AFRL 5 for GPIOA
	setbit(GPIOE_ODR,3);   //CS high
	setbit(SPI1_CR1,2); // master selection
	setbit(SPI1_CR2,2); //ssout
	setbit(SPI1_CR2,8); //Data length
	setbit(SPI1_CR2,9);//Data length
	setbit(SPI1_CR2,10);//Data length
	setbit(SPI1_CR2,11);//Data length
	setbit(SPI1_CR1,6); // SPI enable
	clearbit(GPIOE_ODR,3);//CS low
	while((*SPI1_SR & (1<<7))==1);// check busy
	*SPI1_DR=0B0010000000111111;//
	for(i=0;i<64000;i++);
	setbit(GPIOE_ODR,3);//cs high
	while(*SPI1_SR&(1<<1)==0);


}


