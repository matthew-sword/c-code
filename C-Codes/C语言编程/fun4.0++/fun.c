#include <stdio.h>
#include"fun.h"
#include"date.h"


void calculateDayInWeek2015(void)
{
 int month,day,daySeqOfYear,week;
 int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 const char *weekday[7]={"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
 printf("please enter the month(1-12):\n");
 scanf("%d",&month);
 while(isMonth(month)==0){
   printf("your month does not meet the requirements.\n");
   printf("please enter the month(1-12): again.\n");
   scanf("%d",&month);
 }
 printf("please enter the day(1-%d):\n",M[month-1]);
 scanf("%d",&day);
 while(isDay(month,day)==0){
   printf("your day does not meet the requirements.\n");
   printf("please enter the day(1-%d) again.\n",M[month-1]);
   scanf("%d",&day);
 }
 daySeqOfYear=getDaySeqofYear(month,day);
 week=getDaySeqofWeek(daySeqOfYear);
 printf("2015- %d - %d is No %d day in this week \n",month,day,week);
 printf("%s",weekday[week-1]);
 printf("\n");
    }



void printMonthCalendar2015(void)
{
  int month,day,week,days,m;
  int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
  printf("Please input month(1-12):\n");
  scanf("%d",&month);
  while(isMonth(month)==0){
    printf("your month does not meet the requirements.\n");
    printf("please enter the month(1-12) again.\n");
    scanf("%d",&month);
 }
  printf("2015-%d has total %d days.\n",month,M[month-1]);
  printf("Mon\tTue\tWed\tThu\tFri\tSta\tSun\n");
   day=1;
   m=1;
         while(day<=M[month-1])
            {
               days=getDaySeqofYear(month,day);
               week=getDaySeqofWeek(days);
               if(day==1)
              {
                 while(m<week)
                {
                 printf("\t");
                 m++;
                }
              }
                printf("%d\t",day);
              if(week%7==0)
                {
                 printf("\n");
                }
                day++;
            }
            printf("\n");
}


void printWeekCalendar2015(void)
{
  int weeks;
  int month,day;
  int a=0;
  int a1,a2;/*星期是从第几天到第几天*/
  int mi;
  printf("Please input weekSeq in 2015(1-53):\n");
  while(a==0){
  printf("please enter the weeks.\n");
  scanf("%d",&weeks);
  if(weeks<1||weeks>53){
    printf("your weeks does not meet the requirements.\n");
  }
  else{
    a=1;
  }
 }
 if(weeks==1)
        {
         a1=1;
         a2=4;
        }
      if(weeks>1&&weeks<=53)
        {
         a1=(weeks-2)*7+5;
         a2=a1+6;
        }
  printf("No.%d week starts from No.%d day to No.%d day in 2015.\n",weeks,a1,a2);
  printf("#w:\tMon.\tTue.\tWed.\tThu.\tFri.\tSta.\tSun.\n");
   mi=a1;
      printf("\b%d\t",weeks);
      while(mi<=a2)
        {
         if(mi==1)
            {
             printf("\t\t\t");
            }
        month=getMonth(mi);
        day=getDay(mi);
        printf("%d.%d\t",month,day);
        mi++;
        }
      printf("\n");
}

void getHolidayInSemester2015(void)
{
 int startMonth=8,startDay=31,weeko;/*开学日期的初始化*/
 int month,day,daySeqOfYear,week,weeks;/*weeks是记录开学后第几周的变量*/
 int nextDay;//计算离最近的考试周的天数
 int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 printf("please enter the month(1-12):\n");
 scanf("%d",&month);
 while(isMonth(month)==0){
    printf("your month does not meet the requirements.\n");
    printf("please enter the month(1-12): again.\n");
    scanf("%d",&month);
 }
 printf("please enter the day(1-%d):\n",M[month-1]);
 scanf("%d",&day);
 while(isDay(month,day)==0){
    printf("your day does not meet the requirements.\n");
    printf("please enter the day(1-%d) again.\n",M[month-1]);
    scanf("%d",&day);
 }
  daySeqOfYear=getDaySeqofYear(startMonth,startDay);/*计算开学第一天属于全年第几天*/
  weeko=getWeekSeqOfYear(daySeqOfYear);/*计算开学第一周属于全年第几周*/
  daySeqOfYear=getDaySeqofYear(month,day);/*计算所查询的日期是全年第几天*/
  week=getDaySeqofWeek(daySeqOfYear);/*计算所查询的日期是星期几*/
  weeks=getWeekSeqOfYear(daySeqOfYear);/*计算所查询的日期在全年的第几周*/
  if(weeks<weeko){
    printf("There is not any information about that day now.\n");
  }
  if(weeks>=weeko&&weeks<=weeko+19){
        weeks=weeks+1-weeko;/*得到所查询的日期在本学期的第几周*/
        printf("2015-%d-%d is in the second half of autumn semester.\n",month,day);
        if(month==9){
            if(day==3||day==4||day==5){
                printf("Victory Day.\n");
            }
            else if(day==6||day==12){
                printf("It is the course day.\n");
            }
            else if(day==27){
                printf("Mid-Autumn Festival.\n");
            }
            else{
                if(week==6||week==7){
                    printf("The weekday.\n");
                }
                else{
                    printf("It is the course day.\n");
                }
            }
        }//判断九月的安排
        else if(month==10){
            if(day==1||day==2||day==3||day==4||day==5||day==6||day==7){
                printf("National Day.\n");
            }
            else if(day==10){
                printf("It is the course day.\n");
            }
            else{
                if(week==6||week==7){
                    printf("The weekday.\n");
                }
                else{
                    printf("It is the course day.\n");
                }
            }
        }//判断10月的安排
         else{
                if(week==6||week==7){
                    printf("The weekday.\n");
                }
                else{
                    printf("It is the course day.\n");
                }
            }//判断其他月份的安排
        if(weeks<13){
               nextDay=(13-1-weeks)*7+(7-week+1);//计算离最近考试周的公式
               printf("The next examination will be taken after %d days.\n",nextDay);
          }
        if(weeks==13){
               printf("Examination week.\n");
          }
        if(weeks>13&&weeks<20){
               nextDay=(20-1-weeks)*7+(7-week+1);//计算离最近考试周的公式
               printf("The next examination will be taken after %d days.\n",nextDay);
          }
        if(weeks==20){
               printf("Examination week.\n");
        }
  }
  if(weeks>weeko+19){
    printf("There is not any information about that day now.\n");
  }
  printf("\n");
}
