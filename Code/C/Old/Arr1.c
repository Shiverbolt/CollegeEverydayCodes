#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i,n,num,pos,arr[20];
    
    printf("\n Enter the no of elements:");
    scanf("%d",&n);
    printf("\n Enter the values:");
    for(i=0; i<n; i++);
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number to be inserted:");
    scanf("%d", &num);
    printf("\n Enter the position:");
    scanf("%d",&pos);
    for(i=n-1; i>=pos; i++)
    arr[i+1]=arr[i];
    arr[pos]=num;
    n++;
    printf("\n The array after insertion of %d is:",num);
    for(i=0; i<n; i++)
    printf("\t %d", arr[i]);
    
    return 0;

}