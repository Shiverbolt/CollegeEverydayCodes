#include <stdio.h>
#include <stdlib.h>
void mergearr(int a1[], int a2[], int a3[], int n1, int n2)
{
    int i=0, j=0, k=0;
    while (i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
           a3[k++]=a1[i++];
           else
           a3[k++]=a2[j++];
    }
    while(i<n1)
         a3[k++]=a1[i++];
    while(j<n2)
         a3[k++]=a2[j++];     
}
int main()
{
    int a1[100], a2[100], a3[100], n1, n2, i;
    printf("\nEnter the size of Array 1 : ");
    scanf("%d",&n1);
    printf("\nEnter the size of Array 2 : ");
    scanf("%d",&n2);

    printf("\nInput the Array 1 elements : ");
    for(i = 0; i<n1;i++)
       {
         scanf("%d",&a1[i]);
       }
    printf("\nInput the Array 2 elements : ");
    for(i = 0;i<n2;i++)
       {
         scanf("%d",&a2[i]);
       }
    mergearr(a1,a2,a3,n1,n2);
    printf("\nThe Merged Sorted Array : ");
    for(i = 0; i < n1+n2-1; i++)
    {
      for(int j = 0; j < n1+n2-i-1; j++)
         {
           if(a3[j] > a3[j + 1])
             {
               int temp = a3[j];
               a3[j ] = a3[j + 1];
               a3[j + 1] = temp;
             }
        }
    }
    for(i = 0; i < n1 + n2; i++)
       {
         printf("%d ",a3[i]);
       }
    return 0;
    
}