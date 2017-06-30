#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student
{
	char name[10];
	int num;
	int age;
	char addr[15];
} student[2];

void save()
{
	FILE * fp;
	int i;
	printf("hello world\n");
	if ((fp = fopen("test2.txt","w")) == NULL)
	{
		printf("cant\n");
		return;
	}
	
	for(i = 0;i < 2;i ++)
	{
		if (fwrite(&student[i],sizeof(struct student),1,fp) != 1)
		   	printf("error\n");
	}
	fclose(fp);
	printf("save succeed\n");
}
int main(int argc, char *argv[]) 
{
	int i;
	for (i = 0;i < 2;i ++)
	{
		printf("please input the %d\n",i+1);
		scanf("%s%d%d%s",&student[i].name,&student[i].num,&student[i].age,&student[i].addr);
        save();
	}
	return 0;
}
