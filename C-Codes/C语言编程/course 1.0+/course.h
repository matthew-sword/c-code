#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED
#include <stdio.h>
typedef struct{
           int ID;
           int Month;
           int Day;
           int Seq;
           char Name[100];
    }Course;
void loadRecord(FILE *fPtr,Course syllabus[]);
//���ļ��н����ݵ��뵽�ṹ������
void displayRecord(Course syllabus[]);
//չʾ�γ̱�
void updateRecord(Course syllabus[]);

void newRecord(Course syllabus[]);

void deleteRecord(Course syllabus[]);

int enterChoice(void);

void sortRecord(Course syllabus[]);

void saveRecord(FILE *fPtr,Course syllabus[]);




#endif // COURSE_H_INCLUDED
