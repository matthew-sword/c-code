#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	void ncopy(char *,char *,int);
	int m;
	char s1[20],s2[20];
	gets(s1);
	printf("从第几个字符开始复制?\n");
	scanf("%d",&m);
	if(m>strlen(s1))
	  printf("error\a");
	else
	{
	  ncopy(s1,s2,m);
	  printf("the result: %s",s2);	
	}
	
	return 0;
}
void ncopy(char *p1,char *p2,int m)
{
	int n=0;
	while(n<m-1)
	{
		n++;
		p1++;
	}
	while(*p1!='\0')
	{
	  *p2=*p1;
	  p1++;
	  p2++;
	}
	*p2='\0';
	
}
