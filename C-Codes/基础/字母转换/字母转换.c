#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char a,b;
	scanf("%c",&a);
	if(a>='A'&&a<='Z')
	 {
	   b=a+32;
	   printf("%c",b);
	 }
	else if(a>='a'&&a<='z')
	 {
	  b=a-32;
	  printf("%c",b);
     }
	else 
	  printf("wrong"); 
	return 0;
}
