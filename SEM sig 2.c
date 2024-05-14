#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK t1[100],t2[100];
OS_EVENT *sem;
INT8U err;
char vari='A';
void  task1 ()
{
	while(1)
    { 	OSSemPend(sem,10,&err);
		if(err==OS_NO_ERR)
			printf(" %c ",vari);
		else
			printf(" 1 ");
    }
}
void task2 ()
{
	while(1) 
	{ if(vari=='Z')
		vari='A';
	OSSemPost(sem);
		vari++;
		OSTimeDlyHMSM(0,0,0,100);
	}
}
int main()
{	TargetInit();
	init_serial();
	OSInit();	
	sem = OSSemCreate(0);
	OSTaskCreate(task1,NULL,&t1[99],1);	
	OSTaskCreate(task2,NULL,&t2[99],2);	
	OSStart();
}