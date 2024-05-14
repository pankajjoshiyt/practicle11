#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK t1[100],t2[100];
OS_EVENT *sem;
INT16U value;
void  task1 ()
{
	while(1)
    { 	value = OSSemAccept(sem);
		if(value>0)
	        printf(" A ");
        OSTimeDlyHMSM(0,0,0,100);
    }
}
void  task2 ()
{
    while(1)
    {	value = OSSemAccept(sem);
		if(value>0)
        	printf(" B ");
       	OSTimeDlyHMSM(0,0,0,200);
     }

}
int main()
{
	TargetInit();//function call
	init_serial();//function call
	OSInit();// init of OS 	
	sem = OSSemCreate(30); //counting semaphore
	OSTaskCreate(task1,NULL,&t1[99],2);	
	OSTaskCreate(task2,NULL,&t2[99],1);	
	OSStart();
}