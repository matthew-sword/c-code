#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int a[3][4],i,j,max,c,d;
	for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	max=a[0][0];
	 for(i=0;i<=2;i++)
	{
		for(j=0;j<=3;j++)
		{
		   if(a[i][j]>max)
		     {
			   max=a[i][j];
			   c=i;
			   d=j;
			 }
		}
	}
	printf("%d\n(%d,%d)",max,c,d);
	
	return 0;
}
