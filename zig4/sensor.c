#include "sensor.h"
#include "led_driver.h"

uint8_t check_repeat(uint8_t data_new, uint8_t *data_old)
{
	for(uint8_t i = 0; i< SENSOR_NUMBER;i++) if(data_old[i] == data_new)  return 0;
	return 1;
}

uint8_t Read_Sensor(uint8_t *data_out)
{
	uint8_t sensor = 0;
	uint8_t sen_num = 0;
	if(bit_is_set(SENSOR1_PORT_IN,SENSOR1_IN))
	{
		sensor = 1;
		sen_num = 1;
		if(check_repeat(sen_num,data_out))
		{
			 data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
	}
	if(bit_is_set(SENSOR2_PORT_IN,SENSOR2_IN))
	{
		sen_num = 2;
		if(check_repeat(sen_num,data_out))
		{
			 data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;

	}
	if(bit_is_set(SENSOR3_PORT_IN,SENSOR3_IN))
	{
		sen_num = 3;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;

	}
	if(bit_is_set(SENSOR4_PORT_IN,SENSOR4_IN))
	{
		sen_num = 4;
		if(check_repeat(sen_num,data_out)) 
		{
			data_out[count] = sen_num;
			if(count < SENSOR_NUMBER) count ++;else count = 0;
		}
		sensor = 1;
	}
	return sensor;
}
uint8_t Read_Current_Sensor(void)
{
	uint8_t sen = 0;
	if(bit_is_set(SENSOR1_PORT_IN,SENSOR1_IN)) sen = 1;
	if(bit_is_set(SENSOR2_PORT_IN,SENSOR2_IN)) sen = 2;
	if(bit_is_set(SENSOR3_PORT_IN,SENSOR3_IN)) sen = 3;
	if(bit_is_set(SENSOR4_PORT_IN,SENSOR4_IN)) sen = 4;
  return sen;
}
void reset_sen_num(void)
{
	count = 0;
}
