/*
 * Filename:    date.h
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-04-03
 * Purpose:     Supporting functions to calculate the dates
 *
 */

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

//functions used for date calcuation
int getDaySeqOfYear(int month, int day);
int getDaySeqOfWeek(int daySeqOfYear);
int getMonth(int daySeqOfYear);
int getDay(int daySeqOfYear);
int getWeekSeqOfYear(int daySeqOfYear);

//functions used for verify the month or day
int isMonth(int month);
    // result = 1/0 for ture/false
int isDay(int month, int day);
    // result = 1/0 for ture/false

//functions used for determine the holiday
int isNationalHoliday(int month, int day);
    // result = 1/0/-1 for MustHoliday/MustNOTHoliday/NormalDay

#endif // DATE_H_INCLUDED
