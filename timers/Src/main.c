
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


unsigned int *newadd,*ptr,*clk2;
unsigned int *timer_add,*mul;
unsigned int *flag,*pb;
unsigned int GPIO_clock=0x40021014,val=1000,i=0;


void setbit(unsigned  int *val,unsigned int pos);



int main(void)
{

	clk2=(unsigned int *)GPIO_clock;
	setbit(clk2,17);
	setbit(clk2,21);
	clk2=(unsigned int *)0x4002101c;
	setbit(clk2,4);
	ptr=(unsigned int)0x48001000;
	setbit(ptr,26);
	*ptr=*ptr & ~(1<<31);
	ptr=(unsigned int )ptr+0x14;
	timer_add=(int *)0x40001000;
	setbit(timer_add,7);
	newadd=(unsigned int )timer_add+0x28;
    *newadd = 0;
    mul=(unsigned int)0x4000102C;
    *mul = 100;
    flag=(unsigned int )timer_add+0x10;
    setbit(timer_add,0);
    pb=(int *)0x48000000;
	*pb=*pb&~(1<<0);
	*pb=*pb&~(1<<1);
	pb=(int)pb +0x04;
	pb=(int *)0x48000000;
	pb=(int )pb+0x10;

    while(1)
    {
       for(i=0;i<1000;i++);
    	if(*pb&1==1)
    	{



    	    *flag = *flag&~(1<<0);
    		*mul = 10+val;
    	    while((*flag & (1<<0)) ==0);
    	    *ptr=*ptr&~(1<<13);

			*flag = *flag&~(1<<0);
			*mul=990-val;
			while((*flag & (1<<0)) ==0);

			*ptr =*ptr|(1<<13);
			val=val+100;
    	}
    	else
    	{
    		*ptr=*ptr&~(1<<13);

    	}




    }

}
void setbit(unsigned  int *val,unsigned int pos)
{
	*val=*val|(1<<pos);
}
