/*
 * Filename:    course.h
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-05-20
 * Purpose:     provide the functions operating on course record
 *
 */

#ifndef COURSE_H_INCLUDED
#define COURSE_H_INCLUDED

#define MAXNUMCOURSE    100
#define MAXCOURSENAME   30

#define DEBUG           1


// �γ���Ϣ�����ݽṹ, ���������Ե�����������¼
struct course {
    int id;
    int daySeq;
    int hourSeq;
    char name[MAXCOURSENAME];
    struct course * next;
};
typedef struct course Course;

// ����DisplayCourseList����ӡ��ǰ�Ŀγ̱���Ϣ
// no return
void DisplayCourseList(const Course *list);

// ����LoadCourseList�����ļ���ȡ�γ̱���Ϣ
// return the new head of list
Course *LoadCourseList(const char *filename, Course *list, const int loadMax );

// ����SaveCourseList�����ļ�д��γ̱���Ϣ
// no return
void SaveCourseList(const char *filename, Course *list, const int saveMax );

// ����CreateNewCourse������һ���µĿγ̽ṹ�����
// return the new record created
Course *CreateNewCourse(Course *newNode);

// ����InsertCourseList���γ̱���Ϣ����һ���¿γ�
// return the new head of list
Course *InsertCourseList(Course *list);

// ����InsertCourseListByEnd���γ̱���Ϣβ������һ���¿γ�
// return the new head of list
Course *InsertCourseListByEnd(Course *list, Course *newOne);

// ����DeleteCourseList��ɾ���γ̱���һ���γ̵���Ϣ
// return the new head of list
Course *DeleteCourseList(Course *list);

// ����DeleteCourseListByEnd���γ̱���Ϣβ��ɾ��һ���¿γ�
// return the new head of list
Course *DeleteCourseListByEnd(Course *list);

// ����UpdateCourseList�����¿γ̱���һ���γ̵���Ϣ
void UpdateCourseList(Course *list);

#endif // COURSE_H_INCLUDED
