#include <stdio.h>
int main()
{
  int arr[10], n, i, d, pos, t;

  printf("Enter number of elements\n");
  scanf("%d", &n);

  printf("Enter %d integers\n", n);

  for (i = 0; i < n; i++)
    scanf("%d", &arr[i]);

  for (i = 0; i < (n - 1); i++) // finding minimum element (n-1) times
  {
    pos = i;

    for (d = i + 1; d < n; d++)
    {
      if (arr[pos] > arr[d])
        pos = d;
    }
    if (pos != i)
    {
      t = arr[i];
      arr[i] = arr[pos];
      arr[pos] = t;
    }
  }

  printf("Sorted list in ascending order:\n");

  for (i = 0; i < n; i++)
    printf("%d\n", arr[i]);

  return 0;
}