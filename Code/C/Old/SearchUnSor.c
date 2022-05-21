#include <stdio.h>
#include <stdlib.h>
  
int main()
{
    int arr[10], n, i, num;
      
    printf("Enter Number of Elements in Array\n");
    scanf("%d", &n);
    printf("\nEnter %d numbers: ", n);
     
    /* Read array elements */
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
     
    printf("Enter a number to serach in Array\n");
    scanf("%d", &num);
     
    /* search num in inputArray from index 0 to elementCount-1 */
    for(i = 0; i < n; i++)
    {
        if(arr[i] == num)
        {
            printf("Number %d found at index %d\n", num, i);
            break;
        }
    }
     
    if(i == n){
     printf("Number %d Not Present in Input Array\n", num);
    }
          
    
    return 0;
}