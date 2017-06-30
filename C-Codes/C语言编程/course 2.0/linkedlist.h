#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "InputCheck.h"



 void displayAllCourse(Node* head);
 //打印所有课程记录
 void displayOneCourse(Node* head,int id);
 //根据用选择的ID信息打印指定课程记录
 Node* insertCourse(Node* head);
 //插入新的课程记录，并根据时间排序自动插入到合适的位置
 Node* deleteCourse(Node* head);
 //删除某条课程记录
 Node* updateCourse(Node* head);
 //更新某条课程记录，更新时自动重新排序
 Node* sortID(Node* head);
 //重新编排课程记录的序号信息
 void referByDate(Node* head);
 //根据日期进行查询课程信息并打印
 void destroyCourse(Node* head);
 //程序退出后销毁链表

#endif // LINKEDLIST_H_INCLUDED
