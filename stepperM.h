/***********************************************************************************************
 * Stepper Motor Control example/sample program                                       
 * main.c 
 * 2019, Tibor Rojko
 *
 * For driving stepper motor, use ULN2003 darlington transistors array!
 * This library, using the full drive mode
 *
 * connections:
 * MCU Board to ULN2003 module
 * PD4(D4) to IN1
 * PD5(D5) to IN2
 * PD6(D6) to IN3
 * PD7(D7) to IN4
 **********************************************************************************************/


#ifndef STEPPERM_H_
#define STEPPERM_H_

/*** Global variables & definitions ***/
#define IN1						PIND4
#define IN2						PIND5
#define IN3						PIND6
#define IN4						PIND7
#define STEPPER_PORT			PORTD
#define STEPPER_PORT_DIRECTION	DDRD

/*** functions ***/
void sM_CW_Turn(int deg, uint8_t period);	// turn the motor to specific angle - clockwise
void sM_BW_Turn(int deg, uint8_t period);	// turn the motor to specific angle - backward

#endif /* STEPPERM_H_ */