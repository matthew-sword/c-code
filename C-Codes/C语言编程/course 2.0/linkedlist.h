#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "InputCheck.h"



 void displayAllCourse(Node* head);
 //��ӡ���пγ̼�¼
 void displayOneCourse(Node* head,int id);
 //������ѡ���ID��Ϣ��ӡָ���γ̼�¼
 Node* insertCourse(Node* head);
 //�����µĿγ̼�¼��������ʱ�������Զ����뵽���ʵ�λ��
 Node* deleteCourse(Node* head);
 //ɾ��ĳ���γ̼�¼
 Node* updateCourse(Node* head);
 //����ĳ���γ̼�¼������ʱ�Զ���������
 Node* sortID(Node* head);
 //���±��ſγ̼�¼�������Ϣ
 void referByDate(Node* head);
 //�������ڽ��в�ѯ�γ���Ϣ����ӡ
 void destroyCourse(Node* head);
 //�����˳�����������

#endif // LINKEDLIST_H_INCLUDED
