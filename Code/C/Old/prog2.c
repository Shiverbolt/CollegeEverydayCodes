#include<stdio.h>
#include<stdlib.h>
main()
{
int childpid;
childpid=fork();
if( (childpid == -1)
{
printf("\n Can't fork.\n");
exit(0);
}
else if(childpid == 0)
{ /* Child process */
printf("\n Child: Child pid = %d, Parent pid = %d \n", getpid(), getppid());
exit(0);
}
else
{ /* Parent Process */
printf("\n Parent: Child pid = %d, Parent pid = %d \n", childpid, getpid());
exit(0);
}
}