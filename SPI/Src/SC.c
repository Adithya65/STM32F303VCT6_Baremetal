/*
 * SC.c
 *
 *  Created on: Oct 17, 2023
 *      Author: adithyam
 */

#include "SC.h"
#include "stdint.h"
void setbit(uint32_t *val,uint32_t pos)
{
	*val=*val|(1<<pos);

}
void clearbit(uint32_t *val,uint32_t pos)
{
	*val=*val&~(1<<pos);

}
void togglebit(uint32_t *val,uint32_t pos)
{
	*val=*val^(1<<pos);
}
