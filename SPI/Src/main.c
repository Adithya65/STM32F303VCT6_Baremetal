
#include <stdint.h>

#include "SC.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

uint32_t *RCC_AHBENR,*GPIOA_MODER,*GPIOE_MODER,*GPIOA_AFRL,*GPIOE_AFRL,*SPI1_CR1,*SPI1_CR2,*RCC_APB2ENR,*SPI1_SR,*SPI1_DR,*GPIOE_ODR;
uint32_t X_L=0,X_H=0,Y_L=0,Y_H=0,Z_L=0,Z_H=0,i;

uint32_t *USART1_CR1,*USART1_CR2,*RCC_APB2ENR,*USART_TDR,*USART_ISR,*USART_BRR,*GPIO_C,*RCC_AHBENR,*GPIO_AFR,*GPIO_AFRL,*GPIO_MODER,* GPIOx_ODR,*USART_RDR;
uint32_t *FLASH_CR,*FLASH_KEYR,*FLASH_SR,*FLASH_AR;
uint16_t test __attribute__((section(".custom_flash")));
uint16_t *ptr,count=0;
int main(void)
{
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
   SPI1_DR=(uint32_t*)0x4001300c;

   setbit(RCC_APB2ENR,12);//clock for SPI1
   setbit(RCC_AHBENR,17); //clock for GPIOA
   setbit(RCC_AHBENR,21); //clock for GPIOE
   setbit(GPIOE_MODER,6);//output mode for GPIOE
   setbit(GPIOE_MODER,30);//output mode for GPIOE
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
      FLASH_CR=(uint32_t*)0x40022010;
      FLASH_KEYR=(uint32_t*)0x40022004;
      FLASH_SR=(uint32_t*)0x4002200c;
      FLASH_AR=(uint32_t*)0x40022014;
      ptr=(uint16_t*)0x08010000;
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
      *FLASH_KEYR=0x45670123;
      *FLASH_KEYR=0xCDEF89AB;
      while(*FLASH_SR & (1<<0));
      setbit(FLASH_CR,1);
      *FLASH_AR = 0x08010000;
      setbit(FLASH_CR,6);
      while(*FLASH_SR & (1<<0));
      clearbit(FLASH_SR,5);
      clearbit(FLASH_CR,1);
      *FLASH_KEYR=0x45670123;
      *FLASH_KEYR=0xCDEF89AB;
       while(((*FLASH_SR)&(1<<0))==1);
       setbit(FLASH_CR,0);
       *FLASH_AR = 0x08010000;

   clearbit(GPIOE_ODR,3);//CS low
   while((*SPI1_SR & (1<<7))==1);// check busy
   *SPI1_DR=0B0010000000111111;//
   for(i=0;i<64000;i++);
   setbit(GPIOE_ODR,3);//cs high
   while(*SPI1_SR&(1<<1)==0);

    while(1)
   {
	   clearbit(GPIOE_ODR,3);//CS low
	   while((*SPI1_SR & (1<<7))==1);//CHECK IF SPI IS BUSY
	   *SPI1_DR =(0B1010100011111111);//read &X_L
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   X_L = *SPI1_DR;
	   *USART_TDR=0;

	   if(X_L<127)
	   {
		   if(X_L<127)
		   	   {
			   setbit(GPIOE_ODR,15);
			   *USART_TDR='0'+count;
			   count=count+1;
			   for(i=0;i<60000;i++);
		   	   }
	   }
	   clearbit(GPIOE_ODR,15);
	   setbit(GPIOE_ODR,3);
	   for(i=0;i<64000;i++);
	   clearbit(GPIOE_ODR,3);
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE
	   *SPI1_DR =(0B1010101011111111);//read &X_H
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   X_H = *SPI1_DR;
	   setbit(GPIOE_ODR,3);
	   for(i=0;i<64000;i++);
	   clearbit(GPIOE_ODR,3);
   }
}
	   /*
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE
	   *SPI1_DR =(0B10101010);//read &Y_L
	   while((*SPI1_SR & (1<<1))==0);
	   setbit(GPIOE_ODR,3);
	   // CHECK IF TRANSMISSION COMPLETE
	   Y_L = *SPI1_DR;
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE
	   *SPI1_DR =(0B10101011);//read &Y_H
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   Y_H = *SPI1_DR;
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE
	   *SPI1_DR =(0B10101100);//read &Z_L
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   Z_L = *SPI1_DR;
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE
	   *SPI1_DR =(0B10101101);//read &Z_H
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   Z_H = *SPI1_DR;
	   while((*SPI1_SR & (1<<0))==0); // CHECK IF RECIEPTION COMPLETE*/










