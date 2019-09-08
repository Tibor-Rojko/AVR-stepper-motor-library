/*
 * main.c
 * Author : Tibor Rojko
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>
#include "stepperM.h"

int main(void)
{

    while (1) 
    {
	   	/*** TEST PROGRAM ***/
		// turn around the stepper - 360°
		sM_CW_Turn(45, 6);
		_delay_ms(3000);
		sM_CW_Turn(45, 6);
		_delay_ms(3000);
		sM_CW_Turn(90, 4);
		_delay_ms(3000);
		sM_CW_Turn(180, 2);

		_delay_ms(5000);

		// turn around the stepper, backward - 360°
		sM_BW_Turn(360, 2);

		_delay_ms(5000);
    }
}

