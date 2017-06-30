#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,j,k;
	float s,t;
	for(k=0;k<=0;k++)
	{
	for(i=1;i<=7;i++)
	{
		t=4-fabs(4-i);
		for(j=1;j<=7;j++)
		{
			s=fabs(4-j);
			if(s<t)
			  printf("*");
			else
			  printf(" ");
		}
		printf("\n");
	 } 
    }
	return 0;
}
