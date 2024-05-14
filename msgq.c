#include "config.h"
#include "stdlib.h"
#include "serial.h"
OS_STK t1[100],t2[100];
OS_EVENT  *msgq;
INT8U i,err,dat[10] = {1,2,3,4,5,6,7,8,9,0};
void *q[10];
void  task1()
{    while(1)
    {   for(i=0;i<11;i++)
    	{	err = OSQPost(msgq, (void *)&dat[i]);
		  if (err==OS_Q_FULL)
		  printf("Queue is full. ");
		  else	
		  printf(" Sent %d ", dat[i]);        
    	    OSTimeDlyHMSM(0,0,0,100);
}	}	}
void  task2()
{	INT8U  *msg;
    while(1)
    {   msg=OSQPend(msgq,10,&err);
        if (err==OS_NO_ERR) 
           printf("Received = %d ",*msg);
        else
            printf("Not received");
		OSTimeDlyHMSM(0,0,1,0);
}	}
int main()					   
{	TargetInit();
	init_serial();
	OSInit();	
	msgq = OSQCreate(q,10);	
	OSTaskCreate(task1,NULL,&t1[99],1);	
	OSTaskCreate(task2,NULL,&t2[99],2);	
	OSStart();
}