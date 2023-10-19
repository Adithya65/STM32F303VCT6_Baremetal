#include <stdint.h>
#include "/home/adithyam/Downloads/stm/SC.h"


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif
//void setbit(uint32_t *val,uint32_t pos);
//void setbit(uint32_t *val,uint32_t pos);
uint32_t *pb;
uint32_t *clk,RCC_APB1ENR,*PR_SC,*TIMx_DIER,*ARR,*NVIC_ISER1,*status;
uint32_t *led,*RCC_APB2RSTR,*SYSCFG_EXTICR1,*RCCAPB2ECR,*EXTI,*SYSCFG_EXTICR,*NVIC_ISER0,*NVIC_IPR,*EXTI_PR1,*RCC_APB2ENR,*TIM6_Base;

int main(void)
{
   pb=(uint32_t * )0x48000000;

   TIM6_Base=(uint32_t*)0x40001000;
   setbit(TIM6_Base,7);
   NVIC_ISER0=(uint32_t*)0xE000E100;
   clk=(uint32_t *)0x40021014;
   led=(uint32_t *)0x48001000;
   TIMx_DIER=(uint32_t)TIM6_Base+0x0c;
   RCC_APB2RSTR=(uint32_t *)0x40021018;
   RCC_APB2ENR=(uint32_t *)0x40021018;
   RCC_APB1ENR=(uint32_t*)0x4002101c;
   EXTI=(uint32_t *)0x40010400;
   SYSCFG_EXTICR=(uint32_t*)0x40010000;
   EXTI_PR1=(uint32_t)0x40010400+0x14;
   PR_SC=(uint32_t)TIM6_Base+0x28;
   PR_SC=133;
   ARR=(uint32_t)TIM6_Base+0x2c;
   ARR=60000;
   NVIC_ISER1=(uint32_t)NVIC_ISER0+0x004;
   setbit(NVIC_ISER1,22);


   setbit(RCC_APB1ENR,4);
   setbit(TIMx_DIER,0);
   setbit(NVIC_ISER0,6);

   NVIC_IPR=(uint32_t *)0xE000E400;
   clearbit(NVIC_IPR,20);
   clearbit(NVIC_IPR,21);
   clearbit(NVIC_IPR,22);
   clearbit(NVIC_IPR,23);

   //SYSCFG_EXTICR=SYSCFG_EXTICR&~(7<<0);
   setbit(EXTI,0);
   EXTI=(uint32_t)EXTI+0x08;
   setbit(EXTI,0);
   setbit(RCC_APB2ENR,0);
   setbit(clk,7);
   setbit(clk,21);
   setbit(led,30);
   led=(uint32_t)led+0x14;
   setbit(TIM6_Base,0);
   while(1);


   /*while(1)
   {
   setbit(led,15);
   }*/
}





/*void setbit(uint32_t *val,uint32_t pos)
{
	*val=*val|(1<<pos);

}
void clearbit(uint32_t *val,uint32_t pos)
{
	*val=*val&~(1<<pos);

}*/


/*void EXTI0_IRQHandler(void)
{

	//setbit(led,15);



	*led=*led^(1<<15);

	setbit(EXTI_PR1,0);

}*/
void TIM6_DACUNDER_IRQHandler(void)
{
	*led=*led^(1<<15);
	status=(uint32_t)TIM6_Base+0x10;

	clearbit(status,0);


}


