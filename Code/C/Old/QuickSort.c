#include<stdio.h>
void quicksort(int arr[10],int first,int last)
{
   int i, d, pivot, temp;

   if(first<last)
   {
      pivot=first;
      i=first;
      d=last;

      while(i<d)
      {
         while(arr[i]<=arr[pivot]&&i<last)
            i++;
         while(arr[d]>arr[pivot])
            d--;
         if(i<d)
         {
            temp=arr[i];
            arr[i]=arr[d];
            arr[d]=temp;
         }
      }

      temp=arr[pivot];
      arr[pivot]=arr[d];
      arr[d]=temp;
      quicksort(arr,first,d-1);
      quicksort(arr,d+1,last);

   }
}

int main()
{
   int i, c, arr[10];

   printf("\nEnter the arr of elements: ");
   scanf("%d",&c);

   printf("Enter %d elements: ", c);
   for(i=0;i<c;i++)
      scanf("%d",&arr[i]);

   quicksort(arr,0,c-1);

   printf("\nSorted Array: ");
   for(i=0;i<c;i++)
      printf(" %d",arr[i]);

   return 0;
}
