#include <stdio.h>

#define MAX_LENGTH 16

int main (void)
{
   double fahrenheit[MAX_LENGTH];
   double celsius[MAX_LENGTH];
   int fahr;
   int index;
   int size;

   size = 0;
   for (fahr = 0; fahr <= 300; fahr += 20)
   {
       fahrenheit[size] = fahr;
       size++;
   }
   for (index = 0; index < size; index++)
   {
       celsius[index] = (5.0 / 9.0) * (fahrenheit[index] - 32);
   }
   for (index = 0; index < size; index++)
   {
       printf("%6.1f\t%6.1f\n", fahrenheit[index], celsius[index]);
   }
   return 0;
}
