#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK	t1[100],t2[100],t3[100];
void task1()
{	  
	while(1)
   	{
		printf(" Task1ON ");
			OSTimeDlyHMSM(0,0,0,500);  
			printf(" Task1OFF ");
		OSTimeDlyHMSM(0,0,0,500);
   	}
}
 void task2()
{
	while(1)
	{
			printf(" Task2ON ");
		OSTimeDlyHMSM(0,0,1,0); 
				printf(" Task2OFF ");
			OSTimeDlyHMSM(0,0,1,0);		
}
}
 void task3 ()
{
	while(1)
	{
				printf(" Task3ON ");
		OSTimeDlyHMSM(0,0,2,0);
				printf(" Task3OFF ");
		OSTimeDlyHMSM(0,0,2,0);
	}
}
int main()
{
	IO0DIR=0x0ff;
	TargetInit();
	init_serial();
	OSInit();	
	OSTaskCreate(task1,NULL,&t1[99],1);	
	OSTaskCreate(task2,NULL,&t2[99],2);	
	OSTaskCreate(task3,NULL,&t3[99],3);
	OSStart();
}