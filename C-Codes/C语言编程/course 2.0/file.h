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
//���ļ��н����ݵ��뵽����
void saveCourseList(const char * filename,Node* head);
//�������е����ݴ����ļ�
int enterChoice(void);
//�˵�ѡ��
void cleanMenu(void);
//����
int getDaySeqofYear(int month,int day);
/*���㼸�¼�����ȫ��ڼ���*/




#endif // FILE_H_INCLUDED
