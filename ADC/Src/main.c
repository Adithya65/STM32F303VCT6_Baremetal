#include <stdint.h>
#include "SC.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
uint32_t *AHBENR,*ADC_BASE,*ADC_IER,*ADC_CR,*ADC_CFGR,*PB,*RCC_AHBENR,*ADC_SQR1,*ADC_DR,*ADC_CCR,*NVIC_ISER0,*led ;
int i;

int main(void)
{
	uint16_t adcval;

	AHBENR=(uint32_t *)0x40021014;
	led=(uint32_t *)0x48001000;

	setbit(AHBENR,28);
	setbit(AHBENR,17);
	setbit(AHBENR,21);
	ADC_SQR1=(uint32_t)ADC_BASE+0x30;
	setbit(led,30);
	ADC_BASE=(uint32_t *)0x50000000;
	ADC_IER=(uint32_t)ADC_BASE+0x04;
	ADC_CR=(uint32_t)ADC_BASE+0x08;
	ADC_CCR=(uint32_t *)0x50000308;
	ADC_DR=(uint32_t)ADC_BASE+0x40;
	ADC_SQR1=(uint32_t)ADC_BASE + 0x30;
	setbit(ADC_CCR,17);//m
	setbit(ADC_CR,0);
	PB=(uint32_t * )0x48000000;
	setbit(PB,0);
	setbit(PB,1);
	setbit(ADC_CR,31);
	setbit(ADC_IER,2);

	//setbit(ADC_IER,2);

	 NVIC_ISER0=(uint32_t*)0xE000E100;
	setbit(NVIC_ISER0,18);
	//clearbit(ADC,0);
	setbit(ADC_CR,31);
	clearbit(ADC_CR,28);
	clearbit(ADC_CR,29);

	setbit(ADC_CR,28);
	setbit(ADC_CR,31);
	clearbit(ADC_CR,29);
	setbit(ADC_SQR1,6);

	//setbit(ADC_IER,0);







	ADC_CFGR=(uint32_t)ADC_BASE+0x0c;
	setbit(ADC_CFGR,13);

	setbit(PB,1);
	RCC_AHBENR=(uint32_t*)0x40021014;

	setbit(ADC_CR,0);

	led=(uint32_t)led+0x14;
	setbit(ADC_CR,2);
	while(*ADC_BASE==0);



	while(1)
	{

		//clearbit(ADC_IER,2);
		//for(i=0;i<1000;i++);
		setbit(ADC_IER,2);
		 //setbit(ADC_CR,0);
		 setbit(ADC_CR,2);


		//while(!*ADC_BASE&(1U<<2));
		//clearbit(ADC_IER,2);
		//for(i=0;i<10000;i++);

		//




	}



}
void ADC1_2_IRQHandler (void )
{

	//for(i=0;i<100000000;i++);

	setbit(led,15);

	setbit(clearbit,15);

	//clearbit(ADC_BASE,2);
	//for(i=0;i<1000;i++);
	//clearbit(led,15);
	 //setbit(ADC_CR,2);
}

















