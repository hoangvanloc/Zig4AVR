#ifndef _SENSOR_H_
#define _SENSOR_H_
#include <stdint.h>
#include <avr/io.h>
#define SENSOR_NUMBER 4
#define bit_is_clear(sfr,bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
#define bit_is_set(sfr,bit)   (_SFR_BYTE(sfr) & _BV(bit))
#define SENSOR1_IN 5
#define SENSOR2_IN 6
#define SENSOR3_IN 4
#define SENSOR4_IN 3

#define SENSOR1_PORT_IN PINB
#define SENSOR2_PORT_IN PINB
#define SENSOR3_PORT_IN PINB
#define SENSOR4_PORT_IN PINB

uint8_t count = 0;
uint8_t Read_Sensor(uint8_t *data_out);
#endif