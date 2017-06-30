/*
 * Filename:    date.c
 * Author:      Wei Liu, liuwei@hust.edu.cn
 * Date:        2013-04-03
 * Purpose:     Supporting functions to calculate the dates
 *
 */

#include <stdio.h>
#include "date.h"

/*
 * function name: getDaySeqOfYear
 * input arguments: int month, int day
 * return value: int daySeqOfYear
 * function description: transfer the date to daySeqOfYear
 * it is supposed that the input is valid
 *
 */
int getDaySeqOfYear(int month, int day)
{
    int month2013[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };
    int daySeqOfYear = 0;
    int i = 0;

    // for the first month, no requirement on array
    if ( month == 1 )
    {
        daySeqOfYear = day;
    }
    // for the rest months, using array to calcualte the sum of days
    else if ( month > 1 )
    {
        for ( i = 1, daySeqOfYear = 0; i < month ; i ++ )
        {
            daySeqOfYear += month2013[ i - 1 ];
        }
        daySeqOfYear += day;
    }

    return daySeqOfYear;
}


/*
 * function name: getDaySeqOfWeek
 * input arguments: int daySeqOfYear
 * return value: int daySeqOfWeek
 * function description: transfer the daySeqOfYear to daySeqOfWeek
 * it is supposed that the input is valid
 *
 */
int getDaySeqOfWeek(int daySeqOfYear)
{
    // for the year 2013, 2013-01-01 is Tuesday;
    // this function can support other year by
    // modifying the calculation here.
    return daySeqOfYear % 7 + 1;
}


/*
 * function name: getMonth
 * input arguments: int daySeqOfYear
 * return value: int month
 * function description: transfer the daySeqOfYear to month
 * it is supposed that the input is valid
 *
 */
int getMonth(int daySeqOfYear)
{
    int month = 0 ;
    int month2013[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };
    int i = 0;

    // for the first month, no requirement on array
    if ( daySeqOfYear <= 31 )
    {
        month = 1;
    }
    // for the rest months, using array to calcualte the current month
    else if ( daySeqOfYear > 31 )
    {
        for ( i = 1 ; daySeqOfYear > month2013[ i - 1 ] ; i ++ )
        {
            daySeqOfYear -= month2013[ i - 1 ];
        }
        month = i;
    }
    return month;
}

/*
 * function name: getDay
 * input arguments: int daySeqOfYear
 * return value: int day
 * function description: transfer the daySeqOfYear to day
 * it is supposed that the input is valid
 *
 */
int getDay(int daySeqOfYear)
{
    int day = 0;
    int i = 0;
    int month2013[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };

    // for the first month, no requirement on array
    if ( daySeqOfYear <= 31 )
    {
        ;
    }
    // for the rest months, using array to calcualte the days in current month
    else if ( daySeqOfYear > 31 )
    {
        for ( i = 1 ; daySeqOfYear > month2013[ i - 1 ] ; i ++ )
        {
            daySeqOfYear -= month2013[ i - 1 ];
        }
    }
    day = daySeqOfYear ;

    return day;
}

/*
 * function name: getWeekSeqOfYear
 * input arguments: int daySeqOfYear
 * return value: int weekSeqOfYear
 * function description: transfer the daySeqOfYear to weekSeqOfYear
 * it is supposed that the input is valid
 *
 */
int getWeekSeqOfYear(int daySeqOfYear)
{
    return (int) daySeqOfYear / 7 + 1;
}

/*
 * function name: isMonth
 * input arguments: int month
 * return value: int result, result = 1/0 for ture/false
 * function description: determine whether the input is valid month
 *
 */
int isMonth(int month)
{
    return (( month >= 1 ) && ( month <= 12 ));
}

/*
 * function name: isDay
 * input arguments: int month, int day
 * return value: int result, result = 1/0 for ture/false
 * function description: determine whether the input is valid month
 *
 */
int isDay(int month, int day)
{
    if ( isMonth(month) == 0 )
    {
        return 0;
    }

    // for the year 2013, length of Feb is 28
    // this function can support Leap Year by modification
    int month2013[12] = {31, 28, 31, 30, 31, 30,
                         31, 31, 30, 31, 30, 31 };

    return (( day >= 1 ) && ( day <= month2013[month - 1] ));
}

/*
 * function name: isDay
 * input arguments: int month, int day
 * return value: int result, result = 1/0/-1 for MustHoliday/MustNOTHoliday/NormalDay
 * function description: determine whether the input is valid month
 *
 */
int isNationalHoliday(int month, int day)
{
    //一、元旦：1月1日至3日放假调休，共3天。1月5日（星期六）、1月6日（星期日）上班。
    //二、春节：2月9日至15日放假调休，共7天。2月16日（星期六）、2月17日（星期日）上班。
    //三、清明节：4月4日至6日放假调休，共3天。4月7日（星期日）上班。
    //四、劳动节：4月29日至5月1日放假调休，共3天。4月27日（星期六）、4月28日（星期日）上班。
    //五、端午节：6月10日至12日放假调休，共3天。6月8日（星期六）、6月9日（星期日）上班。
    //六、中秋节：9月19日至21日放假调休，共3天。9月22日（星期日）上班。
    //七、国庆节：10月1日至7日放假调休，共7天。9月29日（星期日）、10月12日（星期六）上班。

    int isHoliday = -1;


    if ( month == 1 )
    {
        if ( day >= 1 && day <= 3 )
        {
            isHoliday = 1;
        }
        if ( day >= 5 && day <= 6 )
        {
            isHoliday = 0;
        }
    }
    else if ( month == 2 )
    {
        if ( day >= 9 && day <= 15 )
        {
            isHoliday = 1;
        }
        if ( day >= 16 && day <= 17 )
        {
            isHoliday = 0;
        }
    }
    else if ( month == 4 )
    {
        if (( day >= 4 && day <= 6 ) || ( day>=29 && day<=30 ))
        {
            isHoliday = 1;
        }
        if (( day == 7 ) || ( day >= 27 && day <=28 ))
        {
            isHoliday = 0;
        }
    }
    else if ( month == 6 )
    {
        if ( day >= 10 && day <= 12 )
        {
            isHoliday = 1;
        }
        if ( day >= 8 && day <= 9 )
        {
            isHoliday = 0;
        }
    }
    else if ( month == 9 )
    {
        if ( day >= 19 && day <= 21 )
        {
            isHoliday = 1;
        }
        if ( day == 22 || day == 29 )
        {
            isHoliday = 0;
        }
    }
    else if ( month == 10 )
    {
        if ( day >= 1 && day <= 7 )
        {
            isHoliday = 1;
        }
        if ( day == 12 )
        {
            isHoliday = 0;
        }
    }

    return isHoliday;
}
