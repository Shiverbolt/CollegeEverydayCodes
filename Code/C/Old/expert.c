#include<stdio.h>                                                                                                                                      
#include<stdlib.h>                                                                                                                                     
main()                                                                                                                                                 
{                                                                                                                                                      
int forkresult, parent_id, a=10, b=20, c, d;
c=a+b;
d=b-a;
forkresult=fork();                                                                                                                                     
if(forkresult!=0)                                                                                                                                      
{                                                                                                                                                      
printf("I'm in parent\n"); 
printf("Present process id=%d\n", getpid());
printf("Leaving for child\n");
printf("I'm in child process\nPresent process id=%d\n", forkresult);
printf("Addition of two no:%d\n",c);
}                                                                                                                                                      
parent_id=getpid();                                                                                                                                    
//if(forkresult==0)                                                                                                                                      
//printf("I'm in child process\nPresent process id=%d\n", forkresult);
//else  
printf("Substraction of two no:%d\n",d);
printf("I'm in parent again\nParent id is =%d",parent_id);
return 0;                                                                                                                                              
} 