/************************************************************************!
* \file caldatefunc1.c
* \brief calculate the days from DATE a to DATE b
*
*
*
* \author Vincent, vicentcj@163.com
* \version V0.1
* \date /2014.5.20
*
*
*************************************************************************/
#include "stdafx.h"
#include <memory.h>
#include "typedefine.h"
#include "caldate.h"
U16 days_of_year[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
static U16 rest_of_year[13] = {0,365,334,306,275,245,214,184,153,122,92,61,31};
static U16 rest_of_leap[13] = {0,366,335,306,275,245,214,184,153,122,92,61,31};
static U16 * ptr_to_year[2] = {rest_of_year,rest_of_leap};
static U16 is_leap_year(U16 year)
{
        return (year%4 == 0 && year % 100 != 0)|| year % 400 == 0 ;
}
static S16 is_late(DATE a, DATE b)
{
        return memcmp(a,b,sizeof(TIME));
}
extern S16 cal_days1(DATE a, DATE b)
{
        U16 tempyear,tempmonth;
        S16 i,sum = 0;
        i = is_late(a, b);
        if(i < 0) {
                sum += b->day;                                                                /**< calculate the days last in the month of date b*/
                for(tempyear = a->year; tempyear <= b->year; tempyear++) {
                        for(tempmonth = 1; tempmonth < 13; tempmonth++) {
                                if(a->year == b->year) {
                                        if(tempmonth > a->month && tempmonth < b->month) {    /**<in condition a and b are in the same year  */
                                                sum += days_of_year[tempmonth];
                                                if(tempmonth == 2 && (is_leap_year(tempyear)))
                                                        sum += 1;
                                        }
                                } else if(tempyear == a->year) {                             /**< calculate the rest days of year a  */
                                        if(tempmonth > a->month) {
                                                sum += days_of_year[tempmonth];
                                                if(tempmonth == 2 && (is_leap_year(tempyear)))
                                                        sum += 1;
                                        }
                                } else if(tempyear == b->year) {                             /**< calculate the days last in year b */
                                        if(tempmonth < b->month) {
                                                sum += days_of_year[tempmonth];
                                                if(tempmonth == 2 && (is_leap_year(tempyear)))
                                                        sum += 1;
                                        }
                                } else {
                                        sum += days_of_year[tempmonth];                     /**< calculate rest years */
                                        if(tempmonth == 2 && (is_leap_year(tempyear)))
                                                sum += 1;
                                }
                        }
                }
                sum += (days_of_year[a->month] - a->day);                                  /**< calculate the rest days in the month of date a */
                if(a->month == 2 && (is_leap_year(a->year)))
                        sum += 1;
        } else {
                sum = 0 - is_late(a,b);                                                   /**<date a is not early than date b */
        }

        return sum;
}
extern S16 cal_days(DATE a,DATE b)
{
        U16 j;
        S16 i,sum = 1;
        if((i = is_late(a,b)) < 0) {                                               /**<date a is  early than date b */
                sum += (ptr_to_year[(is_leap_year(a->year))][a->month] - a->day);     /**< calculate the rest days of year a  */
                for(j = a->year +1; j <= b->year; j++) {
                        sum += (is_leap_year(j)) ? 366 : 365;                     /**< calculate rest years */
                }
                sum -= (ptr_to_year[(is_leap_year(b->year))][b->month] - b->day);   /**< calculate the days last in year b */
        } else {
                sum -= i;                                                         /**<date a is not early than date b */
        }
        return sum;
}
