#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
  long fact(int n);
  int n;
  long f;
  scanf("%d",&n);
  f=fact(n);
  printf("n!=%ld",f);
	return 0;
}
long fact(int n)
{
	long s;
	if(n==0)
	  s=1;
	else
	  s=fact(n-1)*n;
    return (s);
	
}
