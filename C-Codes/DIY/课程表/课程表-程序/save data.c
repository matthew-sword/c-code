#include <stdio.h>//改 i只等于0 
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
	
	for (i = 0;i < 1;i ++)
	{
		fprintf(fptr,"%s\t%s\t%s\t",course[i].name,course[i].teacher,course[i].place);
		fprintf(fptr,"   ");
		for (j = 0;j < 4;j ++)
		
		{
			fprintf(fptr,"%d ",course[i].order[j]);
		}
		 fprintf(fptr,"   ");
		for (j = 0;j < 14;j ++)//改 
		{
			fprintf(fptr,"%d ",course[i].week[j]);
		}
		fprintf(fptr,"   "); 
		for (j = 0;j < 3;j ++)//改 
		{
			fprintf(fptr,"%d ",course[i].weekday[j]);
		}
		fprintf(fptr,"\n"); 		
	}
	fclose(fptr); 
}

int main(int argc, char *argv[])
 {
 	int i,j;
 	char* filename = "CourseData.txt";
 	Strcou course[9];
 	
 	printf("请输入课程数据：名称 教师 地点 节次 周次 周几\n"); 
 	for (i = 0;i < 1;i ++)
	{
	    scanf("%s%s%s",course[i].name,course[i].teacher,course[i].place);
	}
	
	printf("\n");
	i = 0;
	for (j = 0;j < 4;j ++)
		{
			scanf("%d",&course[i].order[j]);
		}
		for (j = 0;j < 14;j ++)//改 
		{
			scanf("%d ",&course[i].week[j]);
		}
		for (j = 0;j < 3;j ++)//改 
		{
			scanf("%d",&course[i].weekday[j]);
		}	
		
	printf("input over"); 
	savedata(filename,course);
	return 0;
}
