/*
 * comunicacao_serial.h
 *
 *  Created on: Jun 2, 2016
*	Authors: Dark Matter
 *      	 Jesseh
 */

#include <Arduino.h>
#include <HardwareSerial.h>

#ifndef COMUNICACAO_SERIAL_H_
#define COMUNICACAO_SERIAL_H_



class ComMatlab
{
private:
	char*	_string_com;
public:
	ComMatlab(unsigned long baudps=9600)
	{
		Serial.begin(baudps);
		//Testa a conexao
		//Esse eh o nosso handshake
		Serial.println('c');
		char teste_in = 'n';
		while(teste_in != 'c')
		{
			teste_in = Serial.read();
		}
		_string_com = new char[50];

	}

	char ler_char()
	{
		char c;
		while(Serial.available()==0);
		while(Serial.available()>0)
		{
			c = (char)Serial.read();
		}
		return c;
	}

	void escreve_char(char c)
	{
		Serial.println(c);
	}

	char* ler_string()
	{
		while(Serial.available()==0);
		int i = 0;
		char c = Serial.read();
		while(Serial.available()>0 & c!='\n')
		{
			_string_com[i] = c;
			i++;
			c = Serial.read();
		}

		return _string_com;
	}

	void escreve_string(const char* string, unsigned char tam_string)
	{
		int i =0;
		for(i=0;i<tam_string;i++)
		{
			Serial.print(string[i]);
		}
		Serial.println();
	}
};



#endif /* COMUNICACAO_SERIAL_H_ */
