#include"date.h"


int getDaySeqofYear(int month,int day)
{
 int daySeqofYear,i;
 int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};/*存储每月天数的数组*/
 if(month==1){
    daySeqofYear=day;
 }
 else{
    daySeqofYear=day;
    for(i=0;i<=(month-2);i++){
        daySeqofYear=daySeqofYear+M[i];
    }
 }
 return daySeqofYear;
}


int getDaySeqofWeek(int daySeqofYear)
{
 int week;/*记录星期几的变量*/
 week=(daySeqofYear+3)%7;
 if(week==0){
    week=week+7;
 }
 return week;
}


int getMonth(int daySeqofYear)
{
 int month;
         if(daySeqofYear<=31)
            {
             month=1;
            }
         if(daySeqofYear>31&&daySeqofYear<=59)
            {
             month=2;
            }
         if(daySeqofYear>59&&daySeqofYear<=90)
            {
             month=3;
            }
          if(daySeqofYear>90&&daySeqofYear<=120)
            {
             month=4;
            }
           if(daySeqofYear>120&&daySeqofYear<=151)
            {
             month=5;
            }
            if(daySeqofYear>151&&daySeqofYear<=181)
            {
             month=6;
            }
             if(daySeqofYear>181&&daySeqofYear<=212)
            {
             month=7;
            }
             if(daySeqofYear>212&&daySeqofYear<=243)
            {
             month=8;
            }
             if(daySeqofYear>243&&daySeqofYear<=273)
            {
             month=9;
            }
             if(daySeqofYear>273&&daySeqofYear<=304)
            {
             month=10;
            }
             if(daySeqofYear>304&&daySeqofYear<=334)
            {
             month=11;
            }
            if(daySeqofYear>334&&daySeqofYear<=365)
            {
             month=12;
            }
 return month;
}


int getDay(int daySeqofYear)
{
  int day;
         if(daySeqofYear<=31)
            {
             day=daySeqofYear;
            }
         if(daySeqofYear>31&&daySeqofYear<=59)
            {
             day=daySeqofYear-31;
            }
         if(daySeqofYear>59&&daySeqofYear<=90)
            {
             day=daySeqofYear-59;
            }
          if(daySeqofYear>90&&daySeqofYear<=120)
            {
             day=daySeqofYear-90;
            }
           if(daySeqofYear>120&&daySeqofYear<=151)
            {
             day=daySeqofYear-120;
            }
            if(daySeqofYear>151&&daySeqofYear<=181)
            {
             day=daySeqofYear-151;
            }
             if(daySeqofYear>181&&daySeqofYear<=212)
            {
             day=daySeqofYear-181;
            }
             if(daySeqofYear>212&&daySeqofYear<=243)
            {
             day=daySeqofYear-212;
            }
             if(daySeqofYear>243&&daySeqofYear<=273)
            {
             day=daySeqofYear-243;
            }
             if(daySeqofYear>273&&daySeqofYear<=304)
            {
             day=daySeqofYear-273;
            }
             if(daySeqofYear>304&&daySeqofYear<=334)
            {
             day=daySeqofYear-304;
            }
            if(daySeqofYear>334&&daySeqofYear<=365)
            {
             day=daySeqofYear-334;
            }
 return day;
}

int getWeekSeqOfYear(int daySeqOfYear)
{
 int week;/*记录第几周的变量*/
 int remainder;
 if(daySeqOfYear<=4){
    week=1;
 }
 else{
    remainder=(daySeqOfYear-4)%7;
    if(remainder==0){
      week=(daySeqOfYear-4-remainder)/7+1;
    }
    else{
       week=(daySeqOfYear-4-remainder)/7+2;
    }
 }
 return week;
}

int isMonth(int month)
{
 if(month>12||month<1){
    return 0;
 }
 else{
    return 1;
 }
}

int isDay(int month,int day)
{
 int M[12]={31,28,31,30,31,30,31,31,30,31,30,31};
 if(day>M[month-1]||day<1){
    return 0;
 }
 else{
    return 1;
 }
}
