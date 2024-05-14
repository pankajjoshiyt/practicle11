#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK t1[100],t2[100];
OS_EVENT  *mbox;
INT8U err,key='3';
void  task1()
{
    while(1)
    { 	err=OSMboxPost(mbox,(void *)key);
        printf(" S ");
        OSTimeDlyHMSM(0,0,0,200);
    }
}
void  task2()
{	INT8U  *msg;
    while(1)
    {	msg = (INT8U *)(OSMboxPend(mbox, 10, &err));
        if (err == OS_NO_ERR) 
			 printf(" Y  %c ",msg);
        else
			 printf(" N ");
        OSTimeDlyHMSM(0,0,0,100);
    }
}
int main()
{	TargetInit();
	init_serial();
	OSInit();	
	mbox = OSMboxCreate(0);	
	OSTaskCreate(task1,NULL,&t1[99],1);	
	OSTaskCreate(task2,NULL,&t2[99],2);	
	OSStart();
}