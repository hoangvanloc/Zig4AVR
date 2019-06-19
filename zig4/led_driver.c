#include "led_driver.h"

#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
void LED_Init(void)
{
	DDRH |=(1<<LED1_G);
	DDRG |= (1<<LED3_G);
	DDRE |=((1<<LED1_R)|(1<<LED2_G)|(1<<LED2_R));
	DDRF |=((1<<LED3_R)|(1<<LED4_G)|(1<<LED4_R));
}
void Turn_LED_Off(uint8_t LED_num,uint8_t LED_color)
{
	if(LED_num == 1)
	{
		if(LED_color == RED) clr_bit(LED1_PORT_R,LED1_R); else	clr_bit(LED1_PORT_G,LED1_G);
	}
	if(LED_num ==2)
	{
		if(LED_color == RED) clr_bit(LED2_PORT_R,LED2_R); else clr_bit(LED2_PORT_G,LED2_G);
	}
	if(LED_num == 3)
	{
		if(LED_color == RED)clr_bit(LED3_PORT_R,LED3_R);else clr_bit(LED3_PORT_G,LED3_G);
	}
	if(LED_num == 4)
	{
		if(LED_color == RED)	clr_bit(LED4_PORT_R,LED4_R); else	clr_bit(LED4_PORT_G,LED4_G);
	}
}
//Turn LED_num ex: 1,2.. LED_color:RED Or GREEN
void Turn_LED_On(volatile uint8_t LED_num,uint8_t LED_color)
{
	if(LED_num == 1)
	{
			if(LED_color == RED)
			{
				set_bit(LED1_PORT_R,LED1_R);
				
			}else
			{
				set_bit(LED1_PORT_G,LED1_G);
			}
	}
	if(LED_num == 2)
		{
			if(LED_color == RED)
			{
				set_bit(LED2_PORT_R,LED2_R);
			}else
			{
				set_bit(LED2_PORT_G,LED2_G);
			}
		}
if(LED_num == 3)
		{
			if(LED_color == RED)
			{
				set_bit(LED3_PORT_R,LED3_R);
			}else
			{
				set_bit(LED3_PORT_G,LED3_G);
			}
		}
if(LED_num == 4)
		{
			if(LED_color == RED)
			{
				set_bit(LED4_PORT_R,LED4_R);
			}else
			{
				set_bit(LED4_PORT_G,LED4_G);
			}
		}
}
//Turn on any LED 
void Turn_LED_Input(volatile uint8_t* data_in,uint8_t led_type)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	if(led_type == RED) Turn_LED_On(data_in[i],RED); else Turn_LED_On(data_in[i],GREEN);
}
void Turn_LED_Input_Off(volatile uint8_t* data_in,uint8_t led_type)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	if(led_type == RED) Turn_LED_Off(data_in[i],RED); else Turn_LED_Off(data_in[i],GREEN);
}
void Turn_All_LED_On(uint8_t LED_color)
{
	for(uint8_t i = 1; i<= LED_NUMBER;i++)
	{
		Turn_LED_On(i,LED_color);
	}
}
void Turn_All_LED_Off(uint8_t LED_color)
{
	for(uint8_t i = 1; i<= LED_NUMBER;i++)
	{
		Turn_LED_Off(i,LED_color);
	}
}
void Turn_All_Led_On_Delay(volatile uint8_t* led_in,uint8_t led_color)
{
	for(uint8_t i = 0; i< LED_NUMBER;i++)
	{
		Turn_LED_On(led_in[i],led_color);
		_delay_ms(500);
	}
}