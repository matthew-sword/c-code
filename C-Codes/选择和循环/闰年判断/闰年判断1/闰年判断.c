#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int y;
	printf("please put in the year ");
	scanf("%d",&y);
	if(y%4!=0)
	  printf("%d is not leap year",y);
	else if(y%100==0)
	       { if(y%400!=0)
	         printf("%d is not leap year",y);
	         else
	         printf("%d is leap year",y);
	       } 
	else
	printf("%d is leap year",y);       
	return 0;
}
