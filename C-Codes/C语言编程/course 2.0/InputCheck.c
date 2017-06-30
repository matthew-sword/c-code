#include "InputCheck.h"

int checkMonth(void)
{
    int month;
    int check = 0;
    printf("Please enter the month.\n");
    while(check == 0){
        scanf("%d",&month);
        if( month > 12 || month < 1 ){
            check = 0;
            printf("Please enter the month again.\n");
        }
        else{
            check = 1;
        }
    }
    return month;
}


int checkDay(int month)
{
    int day;
    int check = 0;
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printf("Please enter the day.\n");
    while(check == 0){
        scanf("%d",&day);
        if(day>a[month-1] || day<1){
           check = 0;
           printf("Please enter the day again.\n");
        }
        else{
            check = 1;
        }
    }
    return day;
}

int checkSeq(void)
{
    int seq;
    int check = 0;
    printf("Please enter the seq.\n");
    while(check == 0){
        scanf("%d",&seq);
        if(seq>12 || seq<1){
           printf("Please enter the seq again.\n");
        }
        else{
            check = 1;
        }
    }
    return seq;
}
