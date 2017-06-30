#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	int a[11][11],i,j;
    for(i=1;i<11;i++)
    {
    	a[i][1]=1;
    	a[i][i]=1;
	}
	for(i=3;i<11;i++)
	{
		for(j=2;j<i;j++)
		a[i][j]=a[i-1][j-1]+a[i-1][j];
	}
	for(i=1;i<11;i++)
	{
		for(j=1;j<=i;j++)
		  printf("%-6ld",a[i][j]);
		printf("\n");
	}
	return 0;
}
