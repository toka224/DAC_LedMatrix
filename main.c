/*
 * main.c
 *
 *  Created on: Sep 10, 2020
 *      Author: Toka
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"

#include "file.h"

volatile u8 SongVal = 0;
volatile u16 i=0;
volatile u8 count;
u8 u8Dance1[8]={0, 8, 203, 127, 203, 8, 0, 0};
u8 u8Dance2[8]={0, 8, 203, 127, 75, 88, 0, 0};
u8 u8Dance3[8]={0, 88, 75, 127, 203, 8, 0, 0};
u8 u8Dance4[8]={0, 88, 75, 127, 75, 88, 0, 0};

void BellyDance(u8 * Copy_u8Dance1 , u8 * Copy_u8Dance2 , u8 * Copy_u8Dance3 , u8 * Copy_u8Dance4)
{

		count =0;
		while (count!=15)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance1);
			count++;
		}
		count =0;
		while (count!=15)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance2);
			count++;
		}
		count =0;
		while (count!=15)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance3);
			count++;
		}
		count =0;
		while (count!=15)
		{
			HLEDMRX_VoidDisplay(Copy_u8Dance4);
			count++;
		}
}



void voidSetDAC(void)
{

	SongVal= Amaren_raw[i];

	GPIO_voidSetPortValueByRange(GPIOA,SongVal,0,7);

	i++;
	if (i == 37895)
	{
		i = 0;
	}

}

void main(void)
{
	RCC_voidInitSysClock(); //Choose Clock system to HSE 8MHZ
	RCC_voidEnableClock(RCC_APB2,2);   /* GPIOA Enable Clock */
	RCC_voidEnableClock(RCC_APB2, 3);  /* GPIOB Enable Clock */



	GPIO_voidSetPinDirection(GPIOA,0,0b0010);
	GPIO_voidSetPinDirection(GPIOA,1,0b0010);
	GPIO_voidSetPinDirection(GPIOA,2,0b0010);
	GPIO_voidSetPinDirection(GPIOA,3,0b0010);
	GPIO_voidSetPinDirection(GPIOA,4,0b0010);
	GPIO_voidSetPinDirection(GPIOA,5,0b0010);
	GPIO_voidSetPinDirection(GPIOA,6,0b0010);
	GPIO_voidSetPinDirection(GPIOA,7,0b0010);


	HLEDMRX_VoidInit();
	MSTK_voidInit();

	MSTK_voidSetIntervalPeriodic(125,voidSetDAC);

	while(1)
	{

		BellyDance(u8Dance1 , u8Dance2 , u8Dance3 , u8Dance4);
	}
}

