#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK t1[100],t2[100];
OS_EVENT *sem;
INT8U err;
void  task1()
{
    while(1)
    {   OSSemPend(sem,0,&err);
         printf(" A ");
        OSSemPost(sem);
        OSTimeDlyHMSM(0,0,0,100);
   }
}
void  task2()
{
    while(1)
    {
     OSSemPend(sem,0,&err);
     printf(" B ");
	 OSSemPost(sem);
     OSTimeDlyHMSM(0,0,0,200);
    }
}
int main()
{	TargetInit();
	init_serial();
	OSInit();	
	sem = OSSemCreate(1);
	OSTaskCreate(task1,NULL,&t1[99],2);	
	OSTaskCreate(task2,NULL,&t2[99],1);	
	OSStart();
}