/*
 * ACXExample.c
 *
 * Created: 3/22/2018 2:13:17 PM
 * Author : osbornejw
 */ 

#include <avr/io.h>
#include "acx.h"
#include "acxserial.h"

void thread0A();
void thread0B();
void thread1();
void thread2();
void thread3();
void thread4();
void helloThread();

void Serial_puts(uint8_t, char *);

int main(void)
{
	DDRK = 0x0f; // bits 0-3 are output
	PORTK = 0x00;  // clear to zero
	
	// after calling x_init(), the running thread is "thread 0"
	x_init();
	//x_new(1, thread1, true);
	//x_new(2, thread2, true);
	//x_new(3, thread3, true);
	//x_new(4, thread4, true);
	x_new(5, helloThread, true);
	
	// We are thread 0 now
	DDRB = 0x80;
	
    /* Replace with your application code */
    while (1) 
    {
		PORTB ^= 0x80;
		x_delay(100);
		
    }
}

void thread0A() {
	while(1)
	{
		PORTB ^= 0x80;
		x_delay(100);
	}
}
void thread0B() {
	while(1)
	{
		PORTB ^= 0x80;
		x_delay(1000);
	}
}

void thread1() {
	DDRK |= 0x01;
	while(1)
	{
		// run thread main
		PORTK ^= 0x01;
		x_delay(100);
	}
}

void thread2() {
	DDRK |= 0x02;
	while(1)
	{
		// run thread main
		PORTK ^= 0x02;
		x_delay(200);
	}
}
void thread3() {
	DDRK |= 0x04;
	while(1)
	{
		// run thread main
		PORTK ^= 0x04;
		x_delay(300);
	}
}
void thread4() {
	DDRK |= 0x08;
	while(1)
	{
		// run thread main
		PORTK ^= 0x08;
		x_new(0, thread0A, true);
		x_delay(4000);
		x_new(0, thread0B, true);
		x_delay(4000);
	}
}
void helloThread() {
	Serial_open(0, 115200L, SERIAL_8N1);
	char *str = "Hello!\n";
	while(1)
	{
		for(int i = 0; i < 7; i++)
			Serial_write(0, str[i]);
		x_delay(1000);
		//x_yield();
	}
}