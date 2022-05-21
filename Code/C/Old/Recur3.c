#include <stdio.h>
int main() 
{
    int n = 1;
    pb(n);
    return 0;
}
int pb(int num) 
{
    if(num <= 100) 
    {
        printf("%d ",num);
        pb(num+1);
    }
}