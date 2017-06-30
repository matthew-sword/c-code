#include <stdio.h>
#include <stdlib.h>

struct student
{
	char name[10];
	int num;
	int age;
	char addr[15];
} student[2];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main()
{
 int i;
 FILE *fp = fopen("test2.txt","r");
  for(i = 0;i < 2;i ++)
	{
		fread(&student[i],sizeof(struct student),1,fp);
		printf("%-10s %4d %4d %-15s\n",student[i].name,student[i].num,student[i].age,
		student[i].addr);
   }
		   	fclose(fp);
 return 0;
}
