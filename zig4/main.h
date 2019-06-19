#ifndef _MAIN_H_
#define _MAIN_H_

//Define for process
#define NAP_OPEN_PIN           PINA6 //I28
#define NAP_OPEN_PORT_IN       PINA
#define XI_LANH_PIN            PIND3 //I18
#define XI_LANH_PORT_IN        PIND  
#define VALVE_PIN              PD0   //O21
#define VALVE_PORT_OUT         PORTD  
//#define SCREW_DONE_PIN         PINL1 //I48 Busy->1
//#define SCREW_DONE_PORT_IN     PINL
#define SCREW_OK_PIN           PINL1 //I48 OK 
#define SCREW_OK_PORT_IN       PINL
#define SCREW_NOT_COMPLETE_PORT_IN PINC //I30
#define SCREW_NOT_COMPLETE_PIN     PINC7
#define SCREW_ERROR_PIN        PINL0 //I49 ->7
#define SCREW_ERROR_PORT_IN    PINL
#define SPEAKER_PIN            PL5   //O44
#define SPEAKER_PORT_OUT       PORTL
#define PRESSURE_ERROR_PIN     PINC3 //I34
#define PRESSURE_ERROR_PORT_IN PINC
#define SCREW_CONTROL_PIN      PB7   //O13
#define SCREW_CONTROL_PORT     PORTB
#define BUTTON_NEXT_PIN        PINC5  //I32
#define BUTTON_NEXT_PORT_IN    PINC
#endif