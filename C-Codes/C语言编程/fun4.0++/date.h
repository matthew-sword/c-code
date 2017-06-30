#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

int getDaySeqofYear(int month,int day);/*计算几月几号是全年第几天*/
int getDaySeqofWeek(int daySeqofYear);/*计算全年第某天是星期几*/
int getMonth(int daySeqofYear);/*计算全年第某天是几月*/
int getDay(int daySeqofYear);/*计算全年第某天是几号*/
int getWeekSeqOfYear(int daySeqOfYear);/*计算全年第某天是第几周*/
int isMonth(int month);/*评估用户输入的月份是否符合要求*/
int isDay(int month,int day);/*评估用户输入的相应月份的日期是否符合要求*/

#endif // DATE_H_INCLUDED
