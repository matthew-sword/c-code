#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Please input month(1-12):\n");
    int month,day,week,m,n;
    day=1;
    m=1;
    printf("Please input the month.\n");
    scanf("%d",&month);
    if(month==1)
        {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==3)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==5)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==7)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==8)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==10)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
     if(month==12)
       {
         printf("2015-%d has total 31 days.\n",month);
        }
    if(month==4)
        {
         printf("2015-%d has total 30 days.\n",month);
        }
    if(month==6)
        {
         printf("2015-%d has total 30 days.\n",month);
        }
    if(month==9)
        {
         printf("2015-%d has total 30 days.\n",month);
        }
    if(month==11)
        {
         printf("2015-%d has total 30 days.\n",month);
        }
    if(month==2)
        {
         printf("2015-%d has total 28 days.\n",month);
        }
    printf("Mon\tTue\tWed\tThu\tFri\tSta\tSun\n");
    if(month==1)
        {
         while(day<=31)
            {
              week=(day+3)%7;
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
        }
      if(month==2)
            {
             while(day<=28)
                {
                  week=(day+34)%7;
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
            }
     if(month==3)
                {
                 while(day<=31)
                    {
                      week=(day+62)%7;
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
                }
     if(month==4)
                {
                 while(day<=30)
                    {
                      week=(day+93)%7;
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
                }
     if(month==5)
                {
                 while(day<=31)
                    {
                      week=(day+123)%7;
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
                }
     if(month==6)
                {
                 while(day<=30)
                    {
                      week=(day+154)%7;
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
                }
 if(month==7)
            {
             while(day<=31)
                {
                  week=(day+184)%7;
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
            }
 if(month==8)
            {
             while(day<=31)
                {
                  week=(day+215)%7;
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
            }
 if(month==9)
            {
             while(day<=30)
                {
                  week=(day+246)%7;
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
            }
 if(month==10)
            {
             while(day<=31)
                {
                  week=(day+276)%7;
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
            }
 if(month==11)
            {
             while(day<=30)
                {
                  week=(day+307)%7;
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
            }
 if(month==12)
            {
             while(day<=31)
                {
                  week=(day+337)%7;
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
            }
    return 0;
}
