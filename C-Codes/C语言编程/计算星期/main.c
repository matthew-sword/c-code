#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    int month,day,week;
    int a,b;
    printf("please enter the month.\n");
    scanf("%d",&month);
    printf("please enter the day.\n");
    scanf("%d",&day);
    if(month==1)
        {
          a=day%7;
          b=a+3;
        if(b<=7)
         week=b;
        else
         week=b-7;
    }
    if(month==2)
    {
        a=(day+31)%7;
        b=a+3;
     if(b<=7)
       week=b;
     else
       week=b-7;
    }
    if(month==3)
        {
         a=(day+31+28)%7;
         b=a+3;
        if(b<=7)
         week=b;
        else
         week=b-7;
    }
    printf("2015- %d - %d is No %d day in this week \n",month,day,week);
    if(week==1)
        {
         printf("Monday.\n");
        }
    if(week==2)
        {
         printf("Tuesday.\n");
        }
    if(week==3)
        {
         printf("Wednesday.\n");
        }
    if(week==4)
        {
         printf("Thursday.\n");
        }
    if(week==5)
        {
         printf("Friday.\n");
        }
    if(week==6)
        {
         printf("Saturday.\n");
        }
    if(week==7)
        {
         printf("Sunday.\n");
        }
    return 0;
}
