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


// 课程信息的数据结构, 其中日期以当年总天数记录
struct course {
    int id;
    int daySeq;
    int hourSeq;
    char name[MAXCOURSENAME];
    struct course * next;
};
typedef struct course Course;

// 函数DisplayCourseList，打印当前的课程表信息
// no return
void DisplayCourseList(const Course *list);

// 函数LoadCourseList，从文件读取课程表信息
// return the new head of list
Course *LoadCourseList(const char *filename, Course *list, const int loadMax );

// 函数SaveCourseList，向文件写入课程表信息
// no return
void SaveCourseList(const char *filename, Course *list, const int saveMax );

// 函数CreateNewCourse，创建一个新的课程结构体变量
// return the new record created
Course *CreateNewCourse(Course *newNode);

// 函数InsertCourseList，课程表信息插入一个新课程
// return the new head of list
Course *InsertCourseList(Course *list);

// 函数InsertCourseListByEnd，课程表信息尾部插入一个新课程
// return the new head of list
Course *InsertCourseListByEnd(Course *list, Course *newOne);

// 函数DeleteCourseList，删除课程表内一个课程的信息
// return the new head of list
Course *DeleteCourseList(Course *list);

// 函数DeleteCourseListByEnd，课程表信息尾部删除一个新课程
// return the new head of list
Course *DeleteCourseListByEnd(Course *list);

// 函数UpdateCourseList，更新课程表内一个课程的信息
void UpdateCourseList(Course *list);

#endif // COURSE_H_INCLUDED
