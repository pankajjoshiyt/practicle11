#include "config.h"
#include "stdlib.h"
#include "serial.h"

/*Each task must have its own stack space. A stack must be declared as being of type OS_STK and must consist of contiguous memory locations.*/

OS_STK	t1[100],t2[100],t3[100]; //Each task has stack entries of this type. The data structure is located in file src/uC/os_cpu.h

void task1( )
{	  
	while(1)
   	{
			IO0SET = 1<<0;
			OSTimeDlyHMSM(0,0,0,500);  
			IO0CLR = 1<<0; 
			OSTimeDlyHMSM(0,0,0,500);//allows a task to delay itself for a user specified amount of seconds and milliseconds. 
   	}
}
 void task2( )
{
	while(1)
	{
		IO0SET = 1<<1; 
		OSTimeDlyHMSM(0,0,1,0); 
		IO0CLR = 1<<1;
		OSTimeDlyHMSM(0,0,1,0);		
	}
}
 void task3 ( )
{
	while(1)
	{
			IO0SET = 1<<2; // LED ON
			OSTimeDlyHMSM(0,0,2,0); //
			IO0CLR = 1<<2;// LED OFF 
			OSTimeDlyHMSM(0,0,2,0);
	}
}
int main()
{
	TargetInit();
	init_serial();
	OSInit();//Call this function first, Initializes uC/OS-II and must be called before calling OSStart()	
	OSTaskCreate(task1,NULL, &t1[99],1);// Ready state, Stack grows from high to low memory
	OSTaskCreate(task2,NULL, &t2[99],2);// Ready State	
	OSTaskCreate(task3,NULL, &t3[99],3);//Ready State
	OSStart();//Running
}