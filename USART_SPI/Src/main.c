#include <stdint.h>
#include "SC.h"
#include"UART.h"
#include"SPI.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
uint32_t *SPI1_SR,*SPI1_DR,*GPIOE_ODR,*USART_TDR,*USART1_CR;
uint32_t X_L=0,X_H=0,i,count=0;

int main(void)
{

	GPIOE_ODR=(uint32_t*)0x48001014;
	SPI1_DR=(uint32_t*)0x4001300c;
	SPI1_SR=(uint32_t*)0x40013008;
	USART_TDR=(uint32_t*)0x40013828;
	SPIconfig();
   	UARTconfig();
   	while(1)
   	{
   	   clearbit(GPIOE_ODR,3);//CS low
	   while((*SPI1_SR & (1<<7))==1);//CHECK IF SPI IS BUSY
	   *SPI1_DR =(0B1010100011111111);//read &X_L
	   while((*SPI1_SR & (1<<1))==0); // CHECK IF TRANSMISSION COMPLETE
	   X_L = *SPI1_DR;
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













