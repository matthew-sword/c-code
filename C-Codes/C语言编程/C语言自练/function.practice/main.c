#include <stdio.h>
#include <stdlib.h>
int maximum(int x,int y,int z);

int main()
{  int number1;
   int number2;
   int number3;
   unsigned seed;
   printf("enter seed:");
   scanf("%u",&seed);
   srand(seed);
   number1=rand();
   printf("the first number is %d.\n",number1);
   number2=rand();
   printf("the second number is %d.\n",number2);
   number3=rand();
   printf("the third number is %d.\n",number3);
   printf("The max is %d.\n",maximum(number1,number2,number3));

    return 0;
}
int maximum(int x,int y,int z)
{
 int max;
 max=x;
 if(max<y)
  max=y;
 if(max<z)
  max=z;
 return max;
}
