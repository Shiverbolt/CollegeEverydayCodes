#include<stdio.h>                                                                                                                                      
#include<stdlib.h>                                                                                                                                     
main()                                                                                                                                                 
{                                                                                                                                                      
int forkresult, parent_id;                                                                                                                             
forkresult=fork();                                                                                                                                     
if(forkresult!=0)                                                                                                                                      
{                                                                                                                                                      
printf("I'm in the parent my id is =%d", getpid());                                                                                                    
printf("and my child id is =%d\n",forkresult);                                                                                                         
}                                                                                                                                                      
parent_id=getpid();                                                                                                                                    
if(forkresult==0)                                                                                                                                      
printf("I'm in the child and my id is =%d",getpid());                                                                                                  
else                                                                                                                                                   
printf("and my parent id is =%d",parent_id);                                                                                                           
return 0;                                                                                                                                              
} 