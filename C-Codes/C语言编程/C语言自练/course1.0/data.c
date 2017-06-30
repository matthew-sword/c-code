#include"data.h"


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
