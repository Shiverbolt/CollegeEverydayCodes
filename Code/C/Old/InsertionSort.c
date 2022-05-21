#include <stdio.h>
int main()
{
    int n, i, d, temp;
    int arr[64];
 
    printf("Enter number of elements\n");
    scanf("%d", &n);
 
    printf("Enter %d integers\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (i = 1 ; i <= n - 1; i++)
    {
	    d = i;
            while ( d > 0 && arr[d-1] > arr[d])
            {	        
                temp     = arr[d];
                arr[d]   = arr[d-1];
                arr[d-1] = temp;
                d--;
            }
    }
    printf("Sorted list in ascending order:\n");
    for (i = 0; i <= n - 1; i++)
    {
        printf("%d\n", arr[i]);
    }
    return 0;
}
