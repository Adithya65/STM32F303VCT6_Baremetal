#include <stdint.h>
#include "/home/adithyam/Downloads/stm/SC.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


uint32_t *USART1_CR1,*USART1_CR2,*RCC_APB2ENR,*USART_TDR,*USART_ISR,*USART_BRR,*GPIO_C,*RCC_AHBENR,*GPIO_AFR,*GPIO_AFRL,*GPIO_MODER,* GPIOx_ODR,*USART_RDR;
int main(void)
{
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

  /* setbit(GPIO_AFRL,17);
   setbit(GPIO_AFRL,18);  setbit(RCC_AHBENR,21);
   setbit(GPIO_AFRL,16);
   setbit(GPIO_AFRL,21);
   setbit(GPIO_AFRL,22);
   setbit(GPIO_AFRL,20);*/







   //setbit(USART1_CR1,10);
   //setbit(USART1_CR2,20);

   //setbit(USART1_CR2,11);
   setbit(USART1_CR1,0);

     //setbit(USART1_CR1,1);
     setbit(USART1_CR1,2);
     setbit(USART1_CR1,3);
     while(1){
    // setbit(USART_TDR,0);
     *USART_TDR=*USART_RDR;;
      //setbit(USART_TDR,1);
      //setbit(USART_TDR,2);
   while(!(*USART_ISR&(1<<5)));

   setbit(GPIOx_ODR,15);

   }


}
