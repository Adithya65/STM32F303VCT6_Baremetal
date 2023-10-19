#include <stdint.h>

#include "SC.h"



#if !defined(__SOFT_FP__) && defined(__ARM_FP)

  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."

#endif

uint32_t *RCC_AHBENR,*GPIO_MODER,*GPIO_AFRL,*APB1ENR,*I2C_CR1,*I2C_CR2,*I2C_TIMINGR,*I2C_ISR,*I2C_TXD,*CLICK_CFG_A,CTRL_REG1_A;

int32_t i,ptr;

uint16_t RData = 0;

uint8_t *I2C_RXDR;

int main(void)

{

	RCC_AHBENR=(uint32_t*)0x40021014;

	GPIO_MODER=(uint32_t*)0x48000400;

	GPIO_AFRL=(uint32_t*)0x48000420;

	APB1ENR=(uint32_t*)0x4002101c;

	I2C_CR1=(uint32_t*)0x40005400;

	I2C_CR2=(uint32_t*)	0x40005404;

	I2C_TIMINGR=(uint32_t*)0x40005410;

	I2C_ISR=(uint32_t*)0x40005418;

	I2C_TXD=(uint32_t*)0x40005428;

	I2C_RXDR =(uint8_t*)0x40005424;

	CLICK_CFG_A=(uint32_t*)0x38;

	//CTRL_REG1_A= (uint32_t*)0x20;





	setbit(APB1ENR,21);

	setbit(RCC_AHBENR,18);

	setbit(GPIO_MODER,13);

	clearbit(GPIO_MODER,12);

	setbit(GPIO_MODER,15);

	clearbit(GPIO_MODER,14);

	setbit(GPIO_AFRL,26);

	setbit(GPIO_AFRL,30);



	setbit(I2C_TIMINGR,0);

	setbit(I2C_TIMINGR,1);

	setbit(I2C_TIMINGR,4);

	setbit(I2C_TIMINGR,8);

	setbit(I2C_TIMINGR,9);

	setbit(I2C_TIMINGR,10);

	setbit(I2C_TIMINGR,11);

	setbit(I2C_TIMINGR,17);

	setbit(I2C_TIMINGR,22);

	setbit(I2C_TIMINGR,28);

	setbit(I2C_CR2,1);

	setbit(I2C_CR2,4);

	setbit(I2C_CR2,5);

	setbit(I2C_CR2,13);

	setbit(I2C_CR1,0);



	//NBytes to 2

	clearbit(I2C_CR2,16);

	setbit(I2C_CR2,17);



	//setbit(I2C_CR2,16);

		//setbit(I2C_CR2,18);

	//ptr=*WHO_AM_I_A;

	//setbit(CTRL_REG1_A,4);

	//setbit(CTRL_REG1_A,6);







	//enable last

	//setbit(I2C_CR2,0);









		//setbit(I2C_CR2,17);

		//setbit(I2C_TXD,4);

		//setbit(I2C_TXD,6);

		setbit(I2C_CR2,1);

		setbit(I2C_CR2,4);

		setbit(I2C_CR2,5);



		setbit(I2C_CR2,13); //Start



		while((*I2C_CR2)& (1<<13) == 1); //Wait for Start To Complete



		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		//*I2C_TXD=0x28;

		*I2C_TXD=0x20;
		while(*I2C_TXD!=0x20);

		while((*I2C_ISR)& (1<<0) == 0); //Wait for Data Transfer to compltete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		*I2C_TXD=0x57;
		while(*I2C_TXD==0x57);

		while((*I2C_ISR)& (1<<0) == 0); //Wait for Data Transfer to compltete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		setbit(I2C_CR2,14);



		//setbit(I2C_CR2,14);

		//setbit(I2C_CR2,10);

		//setbit(I2C_CR2,13);

		//while(*I2C_ISR&(1<<2)==0);

		//for(i=0;i<1000;i++);





//slave address

	while(1)

	{

		//Read X_L



		setbit(I2C_CR2,1);

		setbit(I2C_CR2,4);

		setbit(I2C_CR2,5);



		clearbit(I2C_CR2,17);

		setbit(I2C_CR2,16);



		setbit(I2C_CR2,13); //Start





		while((*I2C_CR2)& (1<<13) == 1); //Wait for Start To Complete



		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		*I2C_TXD=0x28;
		while(*I2C_TXD==0x28);

		while((*I2C_ISR)& (1<<0) == 0); //Wait for Data Transfer to compltete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		setbit(I2C_CR2,10); //Set for Read

		setbit(I2C_CR2,13); //Start

		while((*I2C_CR2)& (1<<13) == 1); //Wait for Start To Complete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		RData = *I2C_RXDR;

		setbit(I2C_CR2,14);



		for(i=0;i<65534;i++);
		for(i=0;i<65534;i++);
		for(i=0;i<65534;i++);
		for(i=0;i<65534;i++);
		for(i=0;i<65534;i++);
		for(i=0;i<65534;i++);

		//Read X_H



		setbit(I2C_CR2,1);

		setbit(I2C_CR2,4);

		setbit(I2C_CR2,5);





		setbit(I2C_CR2,13); //Start





		while((*I2C_CR2)& (1<<13) == 1); //Wait for Start To Complete



		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		*I2C_TXD=0x28;

		while((*I2C_ISR)& (1<<0) == 0); //Wait for Data Transfer to compltete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		setbit(I2C_CR2,10); //Set for Read

		setbit(I2C_CR2,13); //Start

		while((*I2C_CR2)& (1<<13) == 1); //Wait for Start To Complete

		while((*I2C_ISR)& (1<<4) == 1); //Check for the NACK



		RData = ((RData&0x00FF) | (*I2C_RXDR <<8));



		setbit(I2C_CR2,14);



		for(i=0;i<65534;i++);

		for(i=0;i<65534;i++);

		for(i=0;i<65534;i++);





	}



}
