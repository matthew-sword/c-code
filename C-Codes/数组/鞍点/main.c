#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	int a[4][5],i,j,k,max,max_j,p;
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
			scanf("%d",&a[i][j]);
	 }
	for(i=0;i<4;i++)
	{
		max=a[i][0];
		max_j=0;
		for(j=0;j<5;j++)
		{
			if(a[i][j]>max)
			{
				max=a[i][j];
				max_j=j;
			}	
		}
		p=1;
		for(k=0;k<4;k++)
		 {
		 	if(max>a[k][max_j])
		 	{
		 		p=0;
		 		continue;
			 }
		  }
		if(p=1)
		 {
		 	printf("andian is a[%d][%d]=%d\n",i,max_j,max);
		 	break;
		 }
	}
	if(p=0)
	  printf("no an dian");	
	return 0;
}
