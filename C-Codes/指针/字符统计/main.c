#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[])
 {
 	char a[100],*ap;
 	int upper=0,lower=0,num=0,space=0,other=0,i=0;
 	printf("�����ַ�\n"); 
	for(i=0;i<100;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n')
		  break;
	}
	ap=&a[0];
	while(*ap!='\n') 
	{
		if('A'<=*ap&&'Z'>=*ap)
		  upper+=1;
		if('a'<=*ap&&'z'>=*ap)
		  lower+=1;
		if('0'<=*ap&&'9'>=*ap)
		  num+=1;
		if(*ap==' ')
		  space+=1;
		else  ++other;
		ap++;  
	}
	printf("��д=%d\nСд=%d\n",upper,lower);
	printf("�ո�=%d\n����=%d\n����=%d\n",space,num,other);
	return 0;
}
