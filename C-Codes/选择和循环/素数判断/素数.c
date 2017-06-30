#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int a,i,m,t=0;
	scanf("%d",&a);
	m=sqrt(a);
	for(i=2;i<=m;i++)
	{
	   if(a%i==0)
	     t=t+1;
	}
	if(t==0)
	  printf("%d is prime %d",a,m);
	else
	  printf("%d is not prime  %d",a,m);
	return 0;
}
