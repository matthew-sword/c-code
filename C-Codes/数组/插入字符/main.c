#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,j,n,l,t,k;
	char a[30]={2,6,8,12,45,55,67};
	scanf("%d",&n);
	l=strlen(a);
	t=l;
	for(i=0;i<l;i++)
		if(n<a[i])
		{
		t=i;
		break;	
		  }  
	for(j=0;j<7-t;j++)
	{
		a[7-j]=a[7-1-j];
		}
	a[t]=n;
	for(k=0;k<=7;k++)
	printf("%d ",a[k]);
	return 0;
}
