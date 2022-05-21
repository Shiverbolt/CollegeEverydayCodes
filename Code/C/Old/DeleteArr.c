#include <stdio.h>
int main()
{
   int array[10], position, i, n;

   printf("Enter number of elements in array\n");
   scanf("%d", &n);

   printf("\n10Enter %d elements", n);

   for (i = 0; i < n; i++)
      scanf("%d", &array[i]);

   printf("Enter the location where you wish to delete element\n");
   scanf("%d", &position);

   if (position >= n+1)
      printf("Deletion not possible.\n");
   else
   {
      for (i = position - 1; i < n - 1; i++)
         array[i] = array[i+1];

      printf("\nResultant array:");

      for (i = 0; i < n - 1; i++)
         printf("%d\n", array[i]);
   }

   return 0;
}