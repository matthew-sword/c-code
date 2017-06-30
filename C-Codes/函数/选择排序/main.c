#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int a[10],i;
	void sort(int s[],int n);
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	sort(a,10);
	printf("the sorted number is ");
	for(i=0;i<10;i++)
		printf("%d ",a[i]); 
	return 0;
}
void sort(int s[],int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;i++)
	{
	  k=i;
	  for(j=i+1;j<n;j++)
	    if(s[j]<s[k])
		  k=j;
       t=s[k];
	   s[k]=s[i];
	   s[i]=t;	
	}
}
