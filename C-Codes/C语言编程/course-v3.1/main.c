/*
 * Filename:    main.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-05-20
 * Purpose:     provide the functions operating on course linked list
 *
 */

/*
 * ��д�γ̱�ĳ���֧���ļ���д��¼
 * 1. �γ̱�����Ϊcourse�Ľṹ������¼����ѧ�ڵ��Ͽμ�¼��
 * �ýṹ���Ԫ�ذ����Ͽμ�¼��š��Ͽε�����(��2013��ȫ��
 * �ڼ���)���Ͽνڴ�(1-4)���γ����ơ�����ѧ�ڵ��Ͽμ�¼��
 * course���͵�����
 *
 * ����:
 * ID       Date       Seq.       Course
 * 1        02-25       3          C++
 * 2        04-27       3          C++
 * 3        05-03       1          Digital-circuit
 * 4        05-06       2          Math
 * 5        05-07       1          C++
 *
 * 3. �������к��ȶ�ȡsyllabus.txt�ļ�������ṹ���������
 * �ݵ��ڴ档�û��Կγ̱���в���ʱ��������ļ����û�ѡ��
 * �˳�����ʱ�����ڴ��е�syllabus��������ļ��С�
 *
 * 4. �ó����������ȥ������ϵͳ�˵����ɣ�����Ҫ�ڹ�����
 * ����������date.c/date.h���ļ��еĻ��������ڼ���ĺ���
 * ����γ̱���صĺ������뵽�ļ�course.c/course.h��ȥ��
 * main���������ˡ�
 *
 * 5. �û��Ĳ�������������ѡ��ɾ��ĳ�Ͽμ�¼��ŵĿγ���Ϣ
 * ���޸�ĳ�Ͽμ�¼���Ͽ����ڡ��ڴΣ������µ��Ͽμ�¼��Ϣ��
 *
 * 6. ÿ���û����������޸��Ͽμ�¼�������Զ�����ʱ��˳
 * ����Ͽμ�¼���������Ͽμ�¼���Զ����¡�
 * ����ɾ����3Ԫ�صĿγ̱�Ϊ��
 * ID       Date       Seq.       Course
 * 1        02-25       3          C++
 * 2        04-27       3          C++
 * 3        05-06       2          Math
 * 4        05-07       1          C++
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "course.h"
#include "date.h"

void DisplayMenu( void );
void CleanMenu( void );

int main( void )
{
    int numCourse = 0;
    Course *syllabus = NULL;

    // ���ļ�����γ̱��б�ļ�¼
    printf("Loading the records from syllabus.txt ...\n");
    syllabus = LoadCourseList( "syllabus.txt", syllabus, MAXNUMCOURSE );

    int choice = 0;
    do
    {
        DisplayMenu();
        scanf("%d", &choice );

        switch ( choice )
        {
            case 0:
                // ����0�����ļ���������γ̱��б�ļ�¼
                syllabus = LoadCourseList( "syllabus.txt", syllabus, MAXNUMCOURSE );
                CleanMenu();
                break;

            case 1:
                // ����1����ӡĿǰ�Ŀγ̱��б���¼��������ı�
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 2:
                // ����2�������µĿγ̱��¼����¼�������ܸı�
                syllabus = InsertCourseList( syllabus );
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 3:
                // ����3������ĳ���γ̱��¼����¼��������ı�
                UpdateCourseList( syllabus );
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 4:
                // ����4��ɾ��ĳ���γ̱��¼����¼�������ܸı�
                syllabus = DeleteCourseList( syllabus );
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 5:
                break;

            default:
                printf("\nInvalid Input, please input the right choice\n");
                break;
        } // end of switch

    } while ( choice != 5 ); // end of while loop

    // ���ļ�д��γ̱��б�ļ�¼
    SaveCourseList( "syllabus.txt", syllabus, MAXNUMCOURSE );
    printf("\n");

    return 0;
}


/*
 *  ����DisplayMenu����ӡ�˵�
 *  ����������
 *    none
 *  ��������ֵ:
 *    none
 */
void DisplayMenu( void )
{
    printf("---------------------------------\n");
    printf("Please input your choice (1-6): \n");
    printf("0 = load records from the file \n");
    printf("1 = display the records \n");
    printf("2 = insert a new record \n");
    printf("3 = update a existed record \n");
    printf("4 = delete a existed record \n");
    printf("5 = exit and save to the file \n");
    printf("---------------------------------\n");
    printf("Your choice is: ");
    return;
}


/*
 *  ����CleanMenu�������Ļ
 *  ����������
 *    none
 *  ��������ֵ:
 *    none
 */
void CleanMenu( void )
{
    printf("\nPress any key to continue ... ");
    getch();
    system("cls");
    return;
}
