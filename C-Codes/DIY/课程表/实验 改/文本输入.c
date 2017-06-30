#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student
{
	char name[10];
	int num;
	int age;
	char addr[15];
} student[2];//Node,*NodePtr;


void saveData(const char* filename)//,const Node* student)		
{
   FILE* fPtr;
   int i; 
   fPtr = fopen(filename,"a+");
   printf("before write\n");
   	for (i = 0;i < 2;i ++)
	{ 
		printf("%d\n",i+1);
		printf("%s%d%d%s\n",student[i].name,student[i].num,student[i].age,
      student[i].addr);
	}
   for(i = 0;i < 2;i++)
   {
      
	  printf("save %d\n",i+1);
	  fprintf(fPtr,"%s\t%d\t%d\t%s\n",student[i].name,student[i].num,student[i].age,
      student[i].addr);

   }
    printf("after write\n");
   	for (i = 0;i < 2;i ++)
	{ 
		printf("%d\n",i+1);
		printf("%s%d%d%s\n",student[i].name,student[i].num,student[i].age,
      student[i].addr);
	}
   fclose(fPtr);
}


int main(int argc, char *argv[]) 
{
	int i;
	//int *
    char *filename = "test.txt";
   // Node student[4];
    //NodePtr stu;
	for (i = 0;i < 2;i ++)
	{ 
		printf("%d\n",i+1);
		scanf("%s%d%d%s",&student[i].name,&student[i].num,&student[i].age,
      &student[i].addr);
	}
		printf("before save\n");
		for (i = 0;i < 2;i ++)
	{ 
		
		printf("%d\n",i+1);
		printf("%s%d%d%s\n",student[i].name,student[i].num,student[i].age,
      student[i].addr);
	}
	
	saveData(filename);
	printf("after save\n");
		for (i = 0;i < 2;i ++)
	{ 
		printf("%d\n",i+1);
		printf("%s%d%d%s\n",student[i].name,student[i].num,student[i].age,
      student[i].addr);
	}
	return 0;
}
