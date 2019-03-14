/*
 * DIO.c
 *
 * Created: 14.03.2019 18:33:17
 * Author : User
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "C:\el_nikitos\AVR_Lib\GPIO.h"
#include "C:\el_nikitos\AVR_Lib\UART_Serial.h"

int main(void)
{
	UART_open(8000000, 38400);
	UART_write(55);
	UART_write(56);
	UART_write(57);
	UART_write(58);
	UART_write(59);
	UART_write(60);

    pinMode(B1, OUTPUT);

	sei();
		
    while (1) 
    {
		digitalWrite(B1, HIGH);
		delay_counters(100000);
		digitalWrite(B1,LOW);
		delay_counters(100000);
		
    }
}

ISR(USART_RXC_vect)
{
	byte bf = UDR;

	if (bf == 5)	
	{
		UART_write(bf+1);
	}
}

