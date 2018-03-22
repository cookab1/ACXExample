/*
 * ACXExample.c
 *
 * Created: 3/22/2018 2:13:17 PM
 * Author : osbornejw
 */ 

#include <avr/io.h>
#include "acx.h"
#include "acxserial.h"

void thread1();
void thread2();
void thread3();
void thread4();
void helloThread();

int main(void)
{
	DDRK = 0x0f; // bits 0-3 are output
	PORTK = 0x00;  // clear to zero
	
	// after calling x_init(), the running thread is "thread 0"
	x_init();
	
	// We are thread 0 now
	
	
    /* Replace with your application code */
    while (1) 
    {
		
    }
}

void thread1() {
	while(1)
	{
		
	}
}

void thread2() {
	while(1)
	{
		
	}
}
void thread3() {
	while(1)
	{
		
	}
}
void thread4() {
	while(1)
	{
		
	}
}
void helloThread() {
	while(1)
	{
		
	}
}