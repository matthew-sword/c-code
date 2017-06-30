#include <stdio.h>
#include <stdlib.h>

 long Fibonacci(long number);

 int main()
{
    int i;
    for(i=1;i<=20;i++)
        {
         printf("Fibonacci %3d = %6ld \n",i,Fibonacci(i));
        }
    return 0;
}
long Fibonacci(long number)
{
 if(number<=2)
    {
     return 1;
    }
 else{
    return (Fibonacci(number-1)+Fibonacci(number-2));
 }
}
