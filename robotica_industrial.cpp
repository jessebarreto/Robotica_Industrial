/*
 * robotica_industrial.cpp
 *
 *  Created on: Jun 2, 2016
 *      Author: jesseh
 */

#include <Arduino.h>
#include <motor_passo.h>

//Variaveis Globais
stepperMotor motor;

void setup()
{
	motor.setPins(10,11,12,13);
}

void loop()
{

}

int main()
{
	setup();

	for(;;)
		loop();
	return 0;
}
