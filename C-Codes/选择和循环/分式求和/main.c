#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i; 
	float m=2,n=1,s=0;
	for(i=1;i<=20;i++)
	{
		s+=m/n;
		m=m+n;
		n=m-n;
	}
	printf("%f",s);
	return 0;
}
