#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	int age(int n);
	printf("%c",age(5)); 
	return 0;
}
int age(int n)
{
	int c;
	if(n==1)
	  c=10;
    else
      c=age(n-1)+2;
    return (c);
}
