#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	int i,s=1;
	for(i=1;i<10;i++)
	{
		s=(s+1)*2; 
	 }
	 printf("第一天共有%d个桃子",s); 
	return 0;
}
