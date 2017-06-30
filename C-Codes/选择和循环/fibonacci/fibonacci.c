#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	long int f1=1,f2=1,n;
	int i;
	
	printf("你想知道多少以内的菲波拉契数？");
	scanf("%ld",&n); 
	for(i=1;i<=100;i++)
	{
		if (f1 > n || f2 > n)
		    break;
		    
	    printf("%-12ld %-12ld ",f1,f2);
		if(i%2==0)
		   printf("\n");
		f1=f1+f2;
		f2=f2+f1;
			
	} 
	 
	return 0;
}
