#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	float a,b,c,t;
	scanf("%f %f %f",&a,&b,&c);
	if(a>b)
	  t=a;
	else
	  t=b;
	if(t>c)
	  printf("the max number is %f",t);
	else
	  printf("the max number is %f",c); 
	return 0;
}
