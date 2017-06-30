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
 *  ����LoadCourseList�����ļ���ȡ�γ̱���Ϣ
 *  ����������
 *    const char *filename, �ļ���
 *    Course *list, �γ��嵥�б�
 *    const int loadMax, ��ȡ��¼�������ֵ
 *  ��������ֵ:
 *    Course *list, �µ�����ͷָ��
 */
Course * LoadCourseList(const char *filename, Course *list, const int loadMax)
{
    //��ֻ����ʽ���ļ�������ļ�ָ��
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
            // ����ﵽ��ȡ�����ֵ����ֹͣ
            break;
        }

        pCourse = malloc( sizeof(Course) );
        pCourse->next = NULL;

        result = fscanf( fPtr, "%d%d%d%s\n", &(pCourse->id),
               &(pCourse->daySeq), &(pCourse->hourSeq), pCourse->name );

        if ( result < 0 )
        {
            // �ļ�Ϊ��
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

    //�ر��ļ�
    fclose( fPtr );
    printf("Total %d records are loaded\n", i );

    return list;
}



/*
 *  ����SaveCourseList�����ļ�д��γ̱���Ϣ
 *  ����������
 *    const char *filename, �ļ���
 *    Course *list, �γ��嵥�б�
 *    const int saveMax, д���¼�������ֵ
 *  ��������ֵ:
 *    none
 */
void SaveCourseList(const char *filename, Course *list, const int saveMax)
{
    //��д�뷽ʽ���ļ�������ļ�ָ��
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
            // ����ﵽд������ֵ����ֹͣ
            break;
        }

        fprintf( fPtr, "%d  %d  %d  %s\n", pCourse->id,
               pCourse->daySeq,  pCourse->hourSeq,
               pCourse->name );

        i ++;
        pCourse = pCourse->next ;
    }

    //�ر��ļ�
    fclose( fPtr );

    printf("Total %d records are saved.\n", i );

    return;
}



/*
 *  ����DisplayCourseList����ӡ��ǰ�Ŀγ̱���Ϣ
 *  ����������
 *    Course *list, �γ��嵥�б�
 *    const int numCourse, �γ�����
 *  ��������ֵ:
 *    none
 */
void DisplayCourseList(const Course *list)
{
    // �б�Ϊ��
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
 *  ����CreateNewCourse���û�����һ���¿γ���Ϣ
 *  ����������
 *    none
 *  ��������ֵ:
 *    Course *newOne, �µĿγ̼�¼��ָ��
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
 *  ����InsertCourseList���γ̱���Ϣ����һ���¿γ�
 *  ����������
 *    Course *list, �γ��嵥�б�
 *  ��������ֵ:
 *    Course *list, �µ�����ͷָ��
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

    // �б�Ϊ��
    if ( list == NULL )
    {
        list = pNewOne;
        list->id = 1;
        return list;
    }

    // ͷ������
    if (( pNewOne->daySeq < list->daySeq )
        || (( pNewOne->daySeq == list->daySeq )
           && ( pNewOne->hourSeq < list->daySeq ) ))
    {
        pNewOne->next = list;
        list = pNewOne;
    }

    // �м����
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
 *  ����DeleteCourseList��ɾ���γ̱���һ���γ̵���Ϣ
 *  ����������
 *    Course *list, �γ��嵥�б�
 *  ��������ֵ:
 *    Course *list, �µ�����ͷָ��
 */
Course * DeleteCourseList(Course * list )
{

    // �б�Ϊ��
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
 *  ����UpdateCourseList�����¿γ̱���һ���γ̵���Ϣ
 *  ����������
 *    Course *list, �γ��嵥�б�
 *  ��������ֵ:
 *    none
 */
void UpdateCourseList(Course * list)
{
    // �б�Ϊ��
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
 *  ����InsertCourseListByEnd���ڿγ̱�β������һ���γ̵���Ϣ
 *  ����������
 *    Course *list, �γ��嵥�б�
 *  ��������ֵ:
 *    Course *list, �µ�����ͷָ��
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
 *  ����DeleteCourseListByEnd���ڿγ̱�β��ɾ��һ���γ̵���Ϣ
 *  ����������
 *    Course *list, �γ��嵥�б�
 *  ��������ֵ:
 *    Course *list, �µ�����ͷָ��
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
