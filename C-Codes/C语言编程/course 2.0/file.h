#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node{
   int ID;
   int Month;
   int Day;
   int Seq;
   int Number;
   char Name[100];
   struct node *nextPtr;
 };
 typedef struct node Node;



Node* loadCourseList(const char * filename);
//从文件中将数据导入到链表
void saveCourseList(const char * filename,Node* head);
//将链表中的数据存入文件
int enterChoice(void);
//菜单选择
void cleanMenu(void);
//清屏
int getDaySeqofYear(int month,int day);
/*计算几月几号是全年第几天*/




#endif // FILE_H_INCLUDED
