
#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

#include "stepperM.h"

static void my_delay_ms(uint8_t period)
{
	while(period--)
	{
		_delay_ms(1);
	}
}

void sM_CW_Turn(int deg, uint8_t period)
{
	float turnValue = deg / 0.703125;

	if(period < 2)
	{
		period = 2;
	}
	
	for(int i = 0; i < turnValue; i++)
	{
		// Full drive, full speed
		STEPPER_PORT |= (1 << IN1);		// IN1 to HIGH
		STEPPER_PORT |= (1 << IN2);		// IN2 to HIGH
		STEPPER_PORT &= ~(1 << IN3);
		STEPPER_PORT &= ~(1 << IN4);
		my_delay_ms(period);			// wait 2 ms
		
		STEPPER_PORT &= ~(1 << IN1);
		STEPPER_PORT |= (1 << IN2);		// IN2 to HIGH
		STEPPER_PORT |= (1 << IN3);		// IN3 to HIGH
		STEPPER_PORT &= ~(1 << IN4);
		my_delay_ms(period);			// wait 2 ms
		
		STEPPER_PORT &= ~(1 << IN1);
		STEPPER_PORT &= ~(1 << IN2);
		STEPPER_PORT |= (1 << IN3);		// IN3 to HIGH
		STEPPER_PORT |= (1 << IN4);		// IN4 to HIGH
		my_delay_ms(period);			// wait 2 ms
		
		STEPPER_PORT |= (1 << IN1);		// IN1 to HIGH
		STEPPER_PORT &= ~(1 << IN2);
		STEPPER_PORT &= ~(1 << IN3);
		STEPPER_PORT |= (1 << IN4);		// IN4 to HIGH
		my_delay_ms(period);			// wait 2 ms
	}
}

void sM_BW_Turn(int deg, uint8_t period)
{
	float turnValue = deg / 0.703125;

	if(period < 2)
	{
		period = 2;
	}

	for(int i = 0; i < turnValue; i++)
	{
		// Full drive, full speed
		STEPPER_PORT |= (1 << IN1);		// IN1 to HIGH
		STEPPER_PORT &= ~(1 << IN2);
		STEPPER_PORT &= ~(1 << IN3);
		STEPPER_PORT |= (1 << IN4);		// IN4 to HIGH
		my_delay_ms(period);			// wait 2 ms
		
		STEPPER_PORT &= ~(1 << IN1);
		STEPPER_PORT &= ~(1 << IN2);
		STEPPER_PORT |= (1 << IN3);		// IN3 to HIGH
		STEPPER_PORT |= (1 << IN4);		// IN4 to HIGH
		my_delay_ms(period);			// wait 2 ms
		
		STEPPER_PORT &= ~(1 << IN1);
		STEPPER_PORT |= (1 << IN2);		// IN2 to HIGH
		STEPPER_PORT |= (1 << IN3);		// IN3 to HIGH
		STEPPER_PORT &= ~(1 << IN4);
		my_delay_ms(period);			// wait 2 ms

		STEPPER_PORT |= (1 << IN1);		// IN1 to HIGH
		STEPPER_PORT |= (1 << IN2);		// IN2 to HIGH
		STEPPER_PORT &= ~(1 << IN3);
		STEPPER_PORT &= ~(1 << IN4);
		my_delay_ms(period);			// wait 2 ms
	}	
}