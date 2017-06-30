#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	char s1[100],s2[20];
	int i,l1,l2;
	gets(s1);
	gets(s2);
	l1=strlen(s1);
	l2=strlen(s2);
	for(i=l1;i<l1+l2;i++)
	s1[i]=s2[i-l1];
	puts(s1); 
	return 0;
}
