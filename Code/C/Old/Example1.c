#include <stdio.h>
#include <stdlib.h>
int main()
{
   int num1, num2, add, subtract, multiply, op;
   float divide;
 
   printf("Enter two integers\n");
   scanf("%d%d", &num1, &num2);
   printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n");
   printf("Enter your choice:");
   scanf("%d",&op);
   switch(op)
   {
     case 1:
        add = num1 + num2;
        printf("Sum= %d\n", add);
        break;
     case 2:
        subtract = num1 - num2;
        printf("Difference = %d\n", subtract);
        break;
     case 3:
        multiply = num1 * num2;
        printf("Multiplication = %d\n", multiply);
        break;
     case 4:
        divide = num1 / (float)num2;
        printf("Division = %.2f\n", divide);
        break;
      case 5:
         printf("Invalid");
         break;

   }
  return 0;       
}
 