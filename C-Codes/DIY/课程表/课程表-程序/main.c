#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
typedef struct course
{
	char name[15];
	char teacher[15];
	char place[20];  //ȫӢ�� 
	int order[4];
	int week[19];
	int weekday[7];
} Strcou;

extern void by_time(char *); 
//extern void by_course(char *);

int main(int argc, char *argv[]) 
{
	int cho_way;
	char * filename = "CourseData.txt";//�ļ�ָ�� 
	
    printf("��ѡ���η�ʽ:\n1.������\n2.���γ�\n");
    scanf("%d",&cho_way);
    
    if (cho_way == 1)
       by_time(filename);
	else if (cho_way == 2)
	  printf("������������������ڿ�����"); //by_course(filename);//��Ӳ��� 
	else
	   printf("������������������ڿ�����"); 
	return 0;
}
