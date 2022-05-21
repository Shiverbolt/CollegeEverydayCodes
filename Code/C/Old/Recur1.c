#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    static int i = 100;
    if (i >= 1) 
    {
        printf("%d ", i--);
        main();
    }
    return 0;
}