/**********************************************************/
/* Author    : Toka Medhat                                */
/* Date      : 31 August 2020                             */
/* Version   : V01                                        */
/**********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_config.h"
#include "LEDMRX_private.h"

void delay_ms(u32 ms)
{
	u32 i=0;
	for(i=0 ; i<(( SYSCLOCK/(12000) )*ms) ; i++)
	{
		__asm("NOP");
	}

}

void HLEDMRX_VoidInit(void)
{
	GPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,0b0010);

	GPIO_voidSetPinDirection(LEDMRX_COL0_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL1_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL2_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL3_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL4_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL5_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL6_PIN,0b0010);
	GPIO_voidSetPinDirection(LEDMRX_COL7_PIN,0b0010);

}

void HLEDMRX_VoidDisplay(u8 *Copy_u8Data)
{
	
	
	/* Enable all column 0 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[0]);
	GPIO_voidSetPinValue(LEDMRX_COL0_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 1 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[1]);
	GPIO_voidSetPinValue(LEDMRX_COL1_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 2 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[2]);
	GPIO_voidSetPinValue(LEDMRX_COL2_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 3 */
 	DiableAllCols();
	SetRowValue(Copy_u8Data[3]);
	GPIO_voidSetPinValue(LEDMRX_COL3_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 4 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[4]);
	GPIO_voidSetPinValue(LEDMRX_COL4_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	
	/* Enable all column 5 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[5]);
	GPIO_voidSetPinValue(LEDMRX_COL5_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 6 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[6]);
	GPIO_voidSetPinValue(LEDMRX_COL6_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC
	
	/* Enable all column 7 */
	DiableAllCols();
	SetRowValue(Copy_u8Data[7]);
	GPIO_voidSetPinValue(LEDMRX_COL7_PIN,LOW);
	delay_ms(2.5);//2.5 MSEC

	
}

static void DiableAllCols(void)
{

	GPIO_voidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	GPIO_voidSetPinValue(LEDMRX_COL7_PIN,HIGH);
}
	
static void SetRowValue(u8 Copy_u8Value)
{
	u8 Local_u8BIT;
	
	Local_u8BIT = GET_BIT(Copy_u8Value,0);
	GPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,1);
	GPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,2);
	GPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,3);
	GPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,4);
	GPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,5);
	GPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,6);
	GPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8BIT);
	
	Local_u8BIT = GET_BIT(Copy_u8Value,7);
	GPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8BIT);
	
}
