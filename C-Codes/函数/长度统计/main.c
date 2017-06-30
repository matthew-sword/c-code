#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
   int length (char *sp);
   int len;
   char s[100];
   scanf("%s",s);
   len=length(s);
   printf("%d",len);
	return 0;
}
int length(char *sp)
{
	int i,n=0;
	while(*sp!='\0')
	{
		n++;
		sp++;
	 } 
	return(n);
}
