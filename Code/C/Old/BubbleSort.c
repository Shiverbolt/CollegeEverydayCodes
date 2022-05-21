#include <stdio.h>

int main()
{
  int array[10], n, c, d, swap;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("\nEnter %d integers: ", n);

  for (c = 0; c < n; c++)
    scanf("%d", &array[c]);

  for (c = 0 ; c < n - 1; c++)
  {
    for (d = 0 ; d < n - c - 1; d++)
    {
      if (array[d] > array[d+1]) /* For decreasing order use '<' instead of '>' */
      {
        swap       = array[d];
        array[d]   = array[d+1];
        array[d+1] = swap;
      }
    }
  }

  printf("\nSorted list in ascending order: ");

  for (c = 0; c < n; c++)
     printf("\n%d", array[c]);

  return 0;
}
