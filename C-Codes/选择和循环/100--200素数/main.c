#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,j,t;
	float m;
	for(i=100;i<=200;i++)
	{
		t=0; 
		m=sqrt(i);
		for(j=2;j<=m;j++)
		{
		 if(i%j==0) 
		   t=t+1;
		}
		if(t==0)
		  printf("%5d  ",i);
	 } 
	 
	return 0;
}
