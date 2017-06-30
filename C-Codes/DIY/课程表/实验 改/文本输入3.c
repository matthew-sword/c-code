#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct student
{
	char name[10];
	int num;
	int age;
	char addr[15];
}Node;


void saveData(const char* filename,const Node* student)		
{
   FILE* fPtr;
   int i; 
   fPtr = fopen(filename,"a+");
   for(i = 0;i < 4;i++)
   {
      fprintf(fPtr,"%s\t%d\t%d\t%s\n",student[i].name[10],student[i].num,student[i].age,
      student[i].addr[15]);

   }
   fclose(fPtr);
}


int main(int argc, char *argv[]) 
{
	int i;
        char *filename = "test.txt";
        Node student[4]; 
	for (i = 0;i < 4;i ++)
	{
		scanf("%s%d%d%s",&student[i].name,&student[i].num,&student[i].age,&student[i].addr);
	}
        saveData(filename,student);
	return 0;
}
