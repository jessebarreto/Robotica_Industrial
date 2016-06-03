/*
 * motor_passo.h
 *
 *  Created on: Jun 2, 2016
 *      Authors: Dark Matter
 *      		 Jesseh
 *
 */



#ifndef MOTOR_PASSO_H_
#define MOTOR_PASSO_H_
#include <Arduino.h>


class stepperMotor
{
  private:
	unsigned int sps = 500; //Steps per Second
	//Arduino Pins being used to connect the motor driver
	char bobbin1 = 10;
    char bobbin2 = 11;
    char bobbin3 = 12;
    char bobbin4 = 13;
    const unsigned int NUMBER_OF_STEPS_PER_ROUND = 2038;//number of steps to give one round
    const double ANGLE_PER_STEP = 0.17664376840039253; //this is the angle for each step
    short delay_ms = 2;//the time between two steps
    bool fullStep = true; //this indicates if the actuation is full step or half step
    bool rotation_dir = true; //this indicates the way of rotation_dir where the counter-clockwise is true
    bool modification = false;

void action(double angle)
{
	if(angle < 0)
	{
		rotation_dir = false;
		angle *= (-1);
		modification = true;
	}
	digitalWrite(bobbin1,LOW);
	digitalWrite(bobbin2,LOW);
	digitalWrite(bobbin3,LOW);
	digitalWrite(bobbin4,LOW);

	if(fullStep)
	{
		if(rotation_dir)
		{
			unsigned int counter = 0;
			while(counter < angle/ANGLE_PER_STEP)
			{
				//first actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//second actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//third actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//fourth actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;
			}//end while
		}//end of the if(rotation_dir)
		else
		{
			unsigned int counter = 0;
			while(counter < angle/ANGLE_PER_STEP)
			{
				//first actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//second actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//third actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//fourth actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;
			}//end while
		}//end else
	}//end of the if(fullStep)
	else
	{
		if(rotation_dir)
		{
			int counter = 0;
			while(counter < angle/ANGLE_PER_STEP)
			{
				//first actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//second actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//third actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//fourth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//fifth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//sixth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//seventh actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//eighth actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;
			}//end of while
		}//end of if(rotation_dir)
		else
		{
			int counter = 0;
			while(counter < angle/ANGLE_PER_STEP)
			{
				//first actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//second actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//third actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,HIGH);
				delay(delay_ms);
				counter++;

				//fourth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//fifth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,HIGH);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//sixth actuation
				digitalWrite(bobbin1,LOW);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//seventh actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,HIGH);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;

				//eighth actuation
				digitalWrite(bobbin1,HIGH);
				digitalWrite(bobbin2,LOW);
				digitalWrite(bobbin3,LOW);
				digitalWrite(bobbin4,LOW);
				delay(delay_ms);
				counter++;
			}//end of while
		}//end of else
	}//end of else
	if(modification)
	{
		modification = false;
		rotation_dir = true;
	}
}//end of the function action

  public:
	void run(double angle)
	{
	  action(angle);
	}// end of the function run

    void setrotation_dir(boolean state)
    {
    	rotation_dir = state;
    }//end of the function setrotation_dir

    void setFullStep(boolean state)
    {
    	fullStep = state;
    }//end of the function setFullStep

    void increaseSpeed()
    {
		if(delay_ms > 2)
		{
			delay_ms--;
			sps = 1000/delay_ms;
		}
    }//end of the function increaseSpeed

    void reduceSpeed()
    {
    	delay_ms++;
    	sps = 1000/delay_ms;
    }//end of the function reduceSpeed

    void set_sps(unsigned int new_sps)
	{
		sps = new_sps;
		delay_ms = 1000/sps;
		delay_ms = fullStep ? delay_ms : delay_ms/2;
	}

    //This function will receive the doors where the bobbins are conected to the Arduino and set it
    void setPins(int pin1, int pin2, int pin3, int pin4)
    {
		bobbin1 = pin1;
		bobbin2 = pin2;
		bobbin3 = pin3;
		bobbin4 = pin4;

		//all the bobbins are setted as OUTPUT
		pinMode(bobbin1,OUTPUT);
		pinMode(bobbin2,OUTPUT);
		pinMode(bobbin3,OUTPUT);
		pinMode(bobbin4,OUTPUT);
	}//end of the function setPins
};//end of the class

#endif /* MOTOR_PASSO_H_ */
