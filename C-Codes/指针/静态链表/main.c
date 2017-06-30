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
		now = (struct gun *)malloc(sizeof(struct gun));//1 申请新空间 5
		if (head == NULL)
		    head = now;//2 头指针指向新空间 
		else 
		  pre->next = now;//6 当前最后元素指向新空间 
		now->next = NULL;//
	    strcpy(now->name,in);//3 赋值 
	    pre = now;//4 pre指向当前最后元素 
	}
	printf("here is the gun list\n");
	for (i = 0;i < 10;i ++)//display
	{
		printf("%s\n",head->name);
		head = head->next;
	}
	return 0;
}
