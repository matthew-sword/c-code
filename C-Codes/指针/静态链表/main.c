#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct gun
{
	char name[20];
	struct gun * next;
};

int main(int argc, char *argv[]) 
{
	struct gun * head = NULL;
	struct gun * pre,* now;
	int i;
	char in[10];
	for (i = 0;i < 10;i ++)//in put
	{
		printf("please put in the gun %d  ",i+1);
		scanf("%s",in);
		now = (struct gun *)malloc(sizeof(struct gun));//1 �����¿ռ� 5
		if (head == NULL)
		    head = now;//2 ͷָ��ָ���¿ռ� 
		else 
		  pre->next = now;//6 ��ǰ���Ԫ��ָ���¿ռ� 
		now->next = NULL;//
	    strcpy(now->name,in);//3 ��ֵ 
	    pre = now;//4 preָ��ǰ���Ԫ�� 
	}
	printf("here is the gun list\n");
	for (i = 0;i < 10;i ++)//display
	{
		printf("%s\n",head->name);
		head = head->next;
	}
	return 0;
}
