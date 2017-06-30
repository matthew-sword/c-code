#include <stdio.h>
#include <stdlib.h>
#include"fun.h"
#include"date.h"

void displayMenu(void);
void cleanMenu(void);

int main(void)
{

    int choice=0;
    do
   {

        displayMenu();
        scanf("%d",&choice);
        switch(choice){
           case 0:
                printf("\nThank you for using this program!\n");
                break;
           case 1:
                calculateDayInWeek2015();
                cleanMenu();
                break;
           case 2:
                printMonthCalendar2015();
                cleanMenu();
                break;
           case 3:
                printWeekCalendar2015();
                cleanMenu();
                break;
           case 4:
                getHolidayInSemester2015();
                cleanMenu();
                break;
           default:
                printf("\nInvalid Input ,please input the right choice\n"); /*输入的选择不符合要求，报错*/
                cleanMenu();
                break;
        }
    }while(choice!=0);

    return 0;
}


void displayMenu(void)
{
    printf("-------------------------------------------------\n");
    printf("Dear user welcome to this menu program\n");
    printf("There are four choices\n");
    printf("please input your choice(0-4):\n");
    printf("1:calculate the day in week\n");
    printf("2:print the month calendar\n");
    printf("3:print the week calendar\n");
    printf("4:check days in the semester\n");
    printf("0:exit\n");
    printf("-------------------------------------------------\n");
    printf("your choice is:");

    return;
}


void cleanMenu(void)
{
   printf("\nPress any key to continue...");
   getch();
   system("cls");
   return;
}
