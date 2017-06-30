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
//从文件中将数据导入到结构体数组
void displayRecord(Course syllabus[]);
//展示课程表
void updateRecord(Course syllabus[]);

void newRecord(Course syllabus[]);

void deleteRecord(Course syllabus[]);

int enterChoice(void);

void sortRecord(Course syllabus[]);

void saveRecord(FILE *fPtr,Course syllabus[]);




#endif // COURSE_H_INCLUDED
