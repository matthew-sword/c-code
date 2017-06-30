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

extern void by_time(char *); 
//extern void by_course(char *);

int main(int argc, char *argv[]) 
{
	int cho_way;
	char * filename = "CourseData.txt";//文件指针 
	
    printf("请选择查课方式:\n1.按日期\n2.按课程\n");
    scanf("%d",&cho_way);
    
    if (cho_way == 1)
       by_time(filename);
	else if (cho_way == 2)
	  printf("输入错误，其它功能正在开发中"); //by_course(filename);//添加参数 
	else
	   printf("输入错误，其它功能正在开发中"); 
	return 0;
}
