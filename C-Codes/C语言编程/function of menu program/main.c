#include <stdio.h>
#include <stdlib.h>
int cweek(int month,int day);
int cmonth(int month);
int cmonths(int mi);
int cdays(int mi);

int main()
{
    printf("Dear user welcome to this menu program.\n");
    printf("There are four choices.\n");
    printf("1:choice one is calculation week.\n");
    printf("2:choice two is print calendar.\n");
    printf("3:choice three is print week calendar.\n");
    printf("4:choice four is program exit.\n");
    int choice,a=1;
    int month,day,week;
    int m,n;
    int weeks,a1,a2,mi;
    while(a==1)
   {
    printf("please input your choice.\n");
    scanf("%d",&choice);
    if(choice==4){
        a=0;
    }
    else{
        a=1;
    }
    printf("your choice is %d.\n",choice);
    if(choice==1){
       printf("please enter the month.\n");
       scanf("%d",&month);
       printf("please enter the day.\n");
       scanf("%d",&day);
       week=cweek(month,day);
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
    }
    if(choice==2){
    printf("Please input month(1-12):\n");
    printf("Please input the month.\n");
    scanf("%d",&month);
    printf("2015-%d has total %d days.\n",month,cmonth(month));
    printf("Mon\tTue\tWed\tThu\tFri\tSta\tSun\n");
        day=1;
        m=1;
         while(day<=cmonth(month))
            {
              week=cweek(month,day);
              if(week==0)
                {
                 n=week+7;
                }
              else
                {
                 n=week;
                }
              if(day==1)
              {
                 while(m<n)
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
    if(choice==3){
        printf("Please input weekSeq in 2015(1-53):\n");
        scanf("%d",&weeks);
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
        month=cmonths(mi);
        day=cdays(mi);
        printf("%d.%d\t",month,day);
        mi++;
        }
      printf("\n");
    }
   }
    printf("Thank you ,welcome to this menu program again.\n");
    return 0;
}
  int cweek(int month,int day)
  {
   int week;
   if(month==1){
    week=(day+3)%7;
   }
   if(month==2){
    week=(day+31+3)%7;
   }
   if(month==3){
    week=(day+31+28+3)%7;
   }
   if(month==4){
    week=(day+31+28+3+31)%7;
   }
   if(month==5){
    week=(day+31+28+3+31+30)%7;
   }
   if(month==6){
    week=(day+31+28+3+31+30+31)%7;
   }
   if(month==7){
    week=(day+31+28+3+31+30+31+30)%7;
   }
   if(month==8){
    week=(day+31+28+3+31+30+31+30+31)%7;
   }
   if(month==9){
    week=(day+31+28+3+31+30+31+30+31+31)%7;
   }
   if(month==10){
    week=(day+31+28+3+31+30+31+30+31+31+30)%7;
   }
   if(month==11){
    week=(day+31+28+3+31+30+31+30+31+31+30+31)%7;
   }
   if(month==12){
    week=(day+31+28+3+31+30+31+30+31+31+30+31)%7;
   }
  return week;
  }
  int cmonth(int month)
  {
   int day;
   if(month==1)
        {
         day=31;
        }
    if(month==3)
       {
         day=31;
        }
    if(month==5)
       {
         day=31;
        }
    if(month==7)
       {
         day=31;
        }
    if(month==8)
       {
         day=31;
        }
    if(month==10)
       {
         day=31;
        }
     if(month==12)
       {
         day=31;
        }
    if(month==4)
        {
         day=30;
        }
    if(month==6)
        {
         day=30;
        }
    if(month==9)
        {
         day=30;
        }
    if(month==11)
        {
         day=30;
        }
    if(month==2)
        {
         day=28;
        }
    return day;
  }
  int cmonths(int mi){
      int month;
         if(mi<=31)
            {
             month=1;
            }
         if(mi>31&&mi<=59)
            {
             month=2;
            }
         if(mi>59&&mi<=90)
            {
             month=3;
            }
          if(mi>90&&mi<=120)
            {
             month=4;
            }
           if(mi>120&&mi<=151)
            {
             month=5;
            }
            if(mi>151&&mi<=181)
            {
             month=6;
            }
             if(mi>181&&mi<=212)
            {
             month=7;
            }
             if(mi>212&&mi<=243)
            {
             month=8;
            }
             if(mi>243&&mi<=273)
            {
             month=9;
            }
             if(mi>273&&mi<=304)
            {
             month=10;
            }
             if(mi>304&&mi<=334)
            {
             month=11;
            }
            if(mi>334&&mi<=365)
            {
             month=12;
            }
    return month;
  }
  int cdays(int mi){

    int day;
         if(mi<=31)
            {
             day=mi;
            }
         if(mi>31&&mi<=59)
            {
             day=mi-31;
            }
         if(mi>59&&mi<=90)
            {
             day=mi-59;
            }
          if(mi>90&&mi<=120)
            {
             day=mi-90;
            }
           if(mi>120&&mi<=151)
            {
             day=mi-120;
            }
            if(mi>151&&mi<=181)
            {
             day=mi-151;
            }
             if(mi>181&&mi<=212)
            {
             day=mi-181;
            }
             if(mi>212&&mi<=243)
            {
             day=mi-212;
            }
             if(mi>243&&mi<=273)
            {
             day=mi-243;
            }
             if(mi>273&&mi<=304)
            {
             day=mi-273;
            }
             if(mi>304&&mi<=334)
            {
             day=mi-304;
            }
            if(mi>334&&mi<=365)
            {
             day=mi-334;
            }
            return day;
            }
