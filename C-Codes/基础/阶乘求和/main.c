#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
   	float t=1,s=0;
	int i,j;
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=i;j++)
		{
			t=t*j;
		}
		s+=t;
		t=1;
	 }
	printf("tne sum is %e",s); 

	return 0;
}
