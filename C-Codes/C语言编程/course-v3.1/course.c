/*
 * Filename:    course.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-05-20
 * Purpose:     provide the functions operating on course record
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "course.h"
#include "date.h"


/*
 *  函数LoadCourseList，从文件读取课程表信息
 *  函数参数：
 *    const char *filename, 文件名
 *    Course *list, 课程清单列表
 *    const int loadMax, 读取记录数的最大值
 *  函数返回值:
 *    Course *list, 新的链表头指针
 */
Course * LoadCourseList(const char *filename, Course *list, const int loadMax)
{
    //以只读方式打开文件，获得文件指针
    FILE *fPtr = fopen ( filename, "r" );

    if ( fPtr == NULL )
    {
        printf("LoadCourseList: File could not be found. \n");
        return NULL;
    }

    // ---------------------------------------------------
    // part 1: clear the current linked list
    // ---------------------------------------------------
    while ( DeleteCourseListByEnd(list) != NULL )
    {
        ; // delete the end node until empty
    }
    if ( list != NULL )
    {
        printf("LoadCourseList: clearing linked list failed. \n");
        return NULL;
    }

    // ---------------------------------------------------
    // part 2: load the linked list from file
    // ---------------------------------------------------
    int i = 0;
    int result = 0;
    Course *pCourse = NULL;
    while ( !feof( fPtr ) )
    {
        if ( i == loadMax )
        {
            // 如果达到读取的最大值，则停止
            break;
        }

        pCourse = malloc( sizeof(Course) );
        pCourse->next = NULL;

        result = fscanf( fPtr, "%d%d%d%s\n", &(pCourse->id),
               &(pCourse->daySeq), &(pCourse->hourSeq), pCourse->name );

        if ( result < 0 )
        {
            // 文件为空
            i = 0;
            free(pCourse);
            break;
        }
        else
        {
            i ++;
            list = InsertCourseListByEnd(list, pCourse);
        }
    }

    //关闭文件
    fclose( fPtr );
    printf("Total %d records are loaded\n", i );

    return list;
}



/*
 *  函数SaveCourseList，向文件写入课程表信息
 *  函数参数：
 *    const char *filename, 文件名
 *    Course *list, 课程清单列表
 *    const int saveMax, 写入记录数的最大值
 *  函数返回值:
 *    none
 */
void SaveCourseList(const char *filename, Course *list, const int saveMax)
{
    //以写入方式打开文件，获得文件指针
    FILE *fPtr = fopen ( filename, "w+" );

    if ( fPtr == NULL )
    {
        printf("saveCourse: File could not be found. \n");
        return;
    }

    int i = 0;
    Course *pCourse = list;

    while ( !feof( fPtr ) && ( pCourse != NULL ))
    {
        if ( i == saveMax )
        {
            // 如果达到写入的最大值，则停止
            break;
        }

        fprintf( fPtr, "%d  %d  %d  %s\n", pCourse->id,
               pCourse->daySeq,  pCourse->hourSeq,
               pCourse->name );

        i ++;
        pCourse = pCourse->next ;
    }

    //关闭文件
    fclose( fPtr );

    printf("Total %d records are saved.\n", i );

    return;
}



/*
 *  函数DisplayCourseList，打印当前的课程表信息
 *  函数参数：
 *    Course *list, 课程清单列表
 *    const int numCourse, 课程数量
 *  函数返回值:
 *    none
 */
void DisplayCourseList(const Course *list)
{
    // 列表为空
    if ( list == NULL )
    {
        printf("DisplayCourseList: the list is empty \n");
        return ;
    }

    int i = 0;
    Course *pCourse = NULL;

    printf("\nThe current syllabus list:\n");
    printf("No.  Date   Seq   Course\n");
    for ( pCourse = list ; pCourse != NULL ; pCourse = pCourse->next )
    {
        printf("%2d   %2d-%2d  %2d    %s \n", pCourse->id,
               getMonth(pCourse->daySeq), getDay(pCourse->daySeq),
               pCourse->hourSeq, pCourse->name );
        i ++;
    } // end of for

    printf("Total %d records in Syllabus.\n", i);
}



/*
 *  函数CreateNewCourse，用户输入一门新课程信息
 *  函数参数：
 *    none
 *  函数返回值:
 *    Course *newOne, 新的课程记录的指针
 */
Course * CreateNewCourse(Course *newOne)
{
    int month = 0;
    int day = 0;
    int daySeq = 0;
    int hourSeq = 0;
    char newName[MAXCOURSENAME];

    // ---------------------------------------------------
    // part 1: checking whether the input is valid
    // ---------------------------------------------------
    printf("New course record:\n");
    printf("Please input the month: ");
    scanf("%d", &month );
    printf("Please input the day: ");
    scanf("%d", &day );
    if ( isDay( month, day ) == 0 )
    {
        printf("CreateNewCourse: Invalid date \n");
        return NULL ;
    }

    daySeq  = getDaySeqOfYear( month, day );
    printf("Please input the course hour seq: ");
    scanf("%d", &hourSeq );
    if ( hourSeq < 1 || hourSeq > 7 )
    {
        printf("CreateNewCourse: Invalid hourSeq \n");
        return NULL ;
    }
    printf("Please input the course name: ") ;
    scanf("%s", newName );
    printf("\n");

    // ---------------------------------------------------
    // part 2: create the new course record
    // ---------------------------------------------------
    newOne->id = 0;
    newOne->daySeq  = daySeq;
    newOne->hourSeq = hourSeq;
    strcpy( newOne->name, newName) ;
    newOne->next = NULL;

    return newOne ;
}


/*
 *  函数InsertCourseList，课程表信息插入一个新课程
 *  函数参数：
 *    Course *list, 课程清单列表
 *  函数返回值:
 *    Course *list, 新的链表头指针
 */
Course * InsertCourseList(Course *list)
{

    // ---------------------------------------------------
    // part 1: create a new course record
    // ---------------------------------------------------
    Course *pNewOne = NULL ;
    pNewOne = malloc( sizeof(Course) );
    pNewOne = CreateNewCourse( pNewOne );
    if ( pNewOne == NULL )
    {
        // create new node failed, return the current head
        free(pNewOne);
        return list;
    }
    printf("The input course record is:\n");
    printf("%2d   %2d-%2d  %2d    %s \n\n", pNewOne->id,
               getMonth(pNewOne->daySeq), getDay(pNewOne->daySeq),
               pNewOne->hourSeq, pNewOne->name );

    // ---------------------------------------------------
    // part 2: find out the place to insert
    // ---------------------------------------------------

    // 列表为空
    if ( list == NULL )
    {
        list = pNewOne;
        list->id = 1;
        return list;
    }

    // 头部插入
    if (( pNewOne->daySeq < list->daySeq )
        || (( pNewOne->daySeq == list->daySeq )
           && ( pNewOne->hourSeq < list->daySeq ) ))
    {
        pNewOne->next = list;
        list = pNewOne;
    }

    // 中间插入
    Course *pPrevious;
    Course *pCurrent;
    int isFound = 0;
    for ( pPrevious = NULL, pCurrent = list ;
          pCurrent != NULL ;
          pPrevious = pCurrent, pCurrent = pCurrent->next )
    {
        // find the position to insert
        if ( pNewOne->daySeq < pCurrent->daySeq )
        {
            isFound = 1;
            break;
        }
        if (( pNewOne->daySeq == pCurrent->daySeq )
            && ( pNewOne->hourSeq < pCurrent->hourSeq ))
        {
            isFound = 1;
            break;
        }
    }
    if ( isFound == 1 )
    {
        //insert in the middle of linked list
        pPrevious->next = pNewOne;
        pNewOne->next = pCurrent;
    }
    else
    {
        //insert to the end
        pPrevious->next = pNewOne;
    }

    // ---------------------------------------------------
    // part 3: set the id for each record in linked list
    // ---------------------------------------------------

    int i = 0;
    Course *pCourse = NULL;
    for ( pCourse = list ; pCourse != NULL ; pCourse = pCourse->next )
    {
        i ++;
        pCourse->id = i;
    } // end of for

    printf("A new record is inserted successfully\n");

    return list ;
}



/*
 *  函数DeleteCourseList，删除课程表内一个课程的信息
 *  函数参数：
 *    Course *list, 课程清单列表
 *  函数返回值:
 *    Course *list, 新的链表头指针
 */
Course * DeleteCourseList(Course * list )
{

    // 列表为空
    if ( list == NULL )
    {
        printf("DeleteCourseList: the list is empty \n");
        return  NULL ;
    }

    // ---------------------------------------------------
    // part 1: find out the course record to delete
    // ---------------------------------------------------
    int id;
    printf("Please input the course ID: ");
    scanf("%d", &id );

    int isFound = 0;
    Course *pPrevious;
    Course *pCurrent;

    // it is the first node
    if ( id == list->id )
    {
        pCurrent = list;
        list = list->next;
        isFound = 1;
    }
    // it is not the first node
    else
    {
        for ( pPrevious = NULL, pCurrent = list ;
              pCurrent != NULL ;
              pPrevious = pCurrent, pCurrent = pCurrent->next )
        {
            if ( id == pCurrent->id )
            {
                pPrevious->next = pCurrent->next;
                isFound = 1;
                break;
            }
        }
    }

    if ( isFound == 0 )
    {
        printf("DeleteCourseList: invalid id \n");
        return list ;
    }

    // ---------------------------------------------------
    // part 2: delete the node
    // ---------------------------------------------------
    printf("Delete course record:\n");
    printf("%2d   %2d-%2d  %2d    %s \n\n",pCurrent->id,
               getMonth(pCurrent->daySeq), getDay(pCurrent->daySeq),
               pCurrent->hourSeq, pCurrent->name );
    free(pCurrent);

    // ---------------------------------------------------
    // part 3: set the id for each record in linked list
    // ---------------------------------------------------
    int i = 0;
    Course *pCourse = NULL;
    for ( pCourse = list ; pCourse != NULL ; pCourse = pCourse->next )
    {
        i ++;
        pCourse->id = i;
    } // end of for

    printf("A record is deleted successfully\n");

    return list ;
}



/*
 *  函数UpdateCourseList，更新课程表内一个课程的信息
 *  函数参数：
 *    Course *list, 课程清单列表
 *  函数返回值:
 *    none
 */
void UpdateCourseList(Course * list)
{
    // 列表为空
    if ( list == NULL )
    {
        printf("UpdateCourseList: the list is empty \n");
        return ;
    }

    // ---------------------------------------------------
    // part 1: find out the course record to update
    // ---------------------------------------------------
    int id;
    printf("Please input the course ID: ");
    scanf("%d", &id );
    int isFound = 0;
    Course *pCurrent;

    for ( pCurrent = list ; pCurrent != NULL ; pCurrent = pCurrent->next )
    {
        if ( id == pCurrent->id )
        {
            isFound = 1;
            break;
        }
    }
    if ( isFound == 0 )
    {
        printf("UpdateCourseList: invalid id \n");
        return ;
    }
    printf("Find the course record to be updated:\n");
    printf("%2d   %2d-%2d  %2d    %s \n\n",pCurrent->id,
               getMonth(pCurrent->daySeq), getDay(pCurrent->daySeq),
               pCurrent->hourSeq, pCurrent->name );

    // ---------------------------------------------------
    // part 2: update the node
    // ---------------------------------------------------
    Course *pNewOne = NULL ;
    pNewOne = malloc( sizeof(Course) );
    pNewOne = CreateNewCourse( pNewOne );
    if ( pNewOne == NULL )
    {
        free(pNewOne);
        return;
    }
    pCurrent->daySeq = pNewOne->daySeq;
    pCurrent->hourSeq = pNewOne->hourSeq;
    strcpy( pCurrent->name, pNewOne->name);
    free(pNewOne);

    printf("Update course record as:\n");
    printf("%2d   %2d-%2d  %2d    %s \n\n",pCurrent->id,
               getMonth(pCurrent->daySeq), getDay(pCurrent->daySeq),
               pCurrent->hourSeq, pCurrent->name );

    return ;
}



/*
 *  函数InsertCourseListByEnd，在课程表尾部插入一个课程的信息
 *  函数参数：
 *    Course *list, 课程清单列表
 *  函数返回值:
 *    Course *list, 新的链表头指针
 */
Course * InsertCourseListByEnd(Course *list, Course *pNewOne)
{
    // if the linked list is empty
    if ( list == NULL )
    {
        pNewOne->id = 1;
        list = pNewOne;
        list->next = NULL;
        return list;
    }

    int i = 1;
    Course *pCourse = NULL;
    for ( pCourse = list ; pCourse->next != NULL ; pCourse = pCourse->next )
    {
        i++; // find the end of the linked list
    }
    pNewOne->id = i + 1;
    pCourse->next = pNewOne;

    return list;
}


/*
 *  函数DeleteCourseListByEnd，在课程表尾部删除一个课程的信息
 *  函数参数：
 *    Course *list, 课程清单列表
 *  函数返回值:
 *    Course *list, 新的链表头指针
 */
Course * DeleteCourseListByEnd(Course *list)
{

    // if the linked list is empty
    if ( list == NULL )
    {
        return list;
    }

    // only one node in this linked list
    if ( list->next == NULL )
    {
        free(list);
        return list;
    }

    Course *pCourse = NULL;
    for ( pCourse = list ; pCourse->next != NULL ; pCourse = pCourse->next )
    {
        ; // find the end of the linked list
    }
    free(pCourse);

    return list;
}
