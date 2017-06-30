#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef struct course
{
	char name[15];
	char teacher[15];
	char place[20];  //全英文 
	int order[4];
	int week[19];
	int weekday[7];
} Strcou;

void savedata(const char* filename,const Strcou* course)      //储存数据 
{
	FILE* fptr;
	int i,j;
	fptr = fopen(filename,"a+");
	
	for (i = 0;i < 9;i ++)
	{
		fprintf(fptr,"%s\t%s\t%s\t",course[i].name,course[i].teacher,course[i].place);
		for (j = 0;j < 4;j ++)
		
		{
			fprintf(fptr,"%d ",course[i].order[j]);
		}
		for (j = 0;j < 19;j ++)
		{
			fprintf(fptr,"%d ",course[i].week[j]);
		}
		for (j = 0;j < 7;j ++)
		{
			fprintf(fptr,"%d ",course[i].weekday[j]);
		}
		
	}
	fclose(fptr); 
}

int main(int argc, char *argv[])
 {
 	int i,j;
 	char* filename = "CourseData.txt";
 	Strcou course[9];
 	
 	for (i = 0;i < 9;i ++)
	{
	    scanf("%s%s%s",&course[i].name,&course[i].teacher,&course[i].place);
		for (j = 0;j < 4;j ++)
		
		{
			scanf("%d",&course[i].order[j]);
		}
		for (j = 0;j < 19;j ++)
		{
			scanf("%d ",&course[i].week[j]);
		}
		for (j = 0;j < 7;j ++)
		{
			scanf("%d ",&course[i].weekday[j]);
		}
		
	}
	
	savedata(filename,course);
	return 0;
}
