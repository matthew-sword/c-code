/*
 * Filename:    main.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-05-20
 * Purpose:     provide the functions operating on course linked list
 *
 */

/*
 * 编写课程表的程序，支持文件读写记录
 * 1. 课程表用名为course的结构体来记录春季学期的上课记录，
 * 该结构体的元素包括上课记录编号、上课的日期(即2013年全年
 * 第几天)、上课节次(1-4)、课程名称。整个学期的上课记录用
 * course类型的链表：
 *
 * 例如:
 * ID       Date       Seq.       Course
 * 1        02-25       3          C++
 * 2        04-27       3          C++
 * 3        05-03       1          Digital-circuit
 * 4        05-06       2          Math
 * 5        05-07       1          C++
 *
 * 3. 程序运行后先读取syllabus.txt文件，载入结构体数组的数
 * 据到内存。用户对课程表进行操作时无需操作文件。用户选择
 * 退出程序时，将内存中的syllabus链表存入文件中。
 *
 * 4. 该程序无需与过去的日历系统菜单集成，但需要在工程中
 * 包括并利用date.c/date.h等文件中的基本的日期计算的函数
 * ，与课程表相关的函数放入到文件course.c/course.h中去，
 * main函数简单明了。
 *
 * 5. 用户的操作包括：可以选择删除某上课记录编号的课程信息
 * ，修改某上课记录的上课日期、节次，增加新的上课记录信息。
 *
 * 6. 每次用户新增或者修改上课记录后，数组自动按照时间顺
 * 序对上课记录进行排序，上课记录号自动更新。
 * 例如删除第3元素的课程表为：
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

    // 从文件载入课程表列表的记录
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
                // 功能0：从文件重新载入课程表列表的记录
                syllabus = LoadCourseList( "syllabus.txt", syllabus, MAXNUMCOURSE );
                CleanMenu();
                break;

            case 1:
                // 功能1：打印目前的课程表列表，记录数量不会改变
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 2:
                // 功能2：插入新的课程表记录，记录数量可能改变
                syllabus = InsertCourseList( syllabus );
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 3:
                // 功能3：更新某条课程表记录，记录数量不会改变
                UpdateCourseList( syllabus );
                DisplayCourseList( syllabus );
                CleanMenu();
                break;

            case 4:
                // 功能4：删除某条课程表记录，记录数量可能改变
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

    // 向文件写入课程表列表的记录
    SaveCourseList( "syllabus.txt", syllabus, MAXNUMCOURSE );
    printf("\n");

    return 0;
}


/*
 *  函数DisplayMenu，打印菜单
 *  函数参数：
 *    none
 *  函数返回值:
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
 *  函数CleanMenu，清空屏幕
 *  函数参数：
 *    none
 *  函数返回值:
 *    none
 */
void CleanMenu( void )
{
    printf("\nPress any key to continue ... ");
    getch();
    system("cls");
    return;
}
