#ifndef CALDATE_H_INCLUDED
#define CALDATE_H_INCLUDED

/************************************************************************!
* \file .h
* \brief
*
*
*
* \author Vincent, vicentcj@163.com
* \version V
* \date /2014
*************************************************************************/
#include "typedefine.h"
#include "node.h"

extern U16 days_of_year[13];

/** \brief
 *
 * \param year U16
 * \return extern U16 = 1 : leap year;
 *                    = 0 : not.
 */
//extern U16 is_leap_year(U16 year);

/** \brief compare a & b
 *
 * \param a DATE
 * \param b DATE
 * \return extern S16 > 0 : a is late than b;
 *                    = 0 : in the same day;
 *                    < 0 : a is early than b.
 */
//extern S16 is_late(DATE a, DATE b);

/** \brief calculate the days from DATE a to DATE b
 *
 * \param a DATE  begin
 * \param b DATE  end
 * \return extern S16 > 0 : days;
 *                    = 0 : a and b are in the same day;
 *                    < 0 : a is late than b.
 */
extern S16 cal_days1(DATE a, DATE b);

/** \brief calculate the days from DATE a to DATE b
 *
 * \param a DATE  begin
 * \param b DATE  end
 * \return extern S16 > 0 : days;
 *                    = 0 : a and b are in the same day;
 *                    < 0 : a is late than b.
 */
extern S16 cal_days(DATE a,DATE b);

#endif // CALDATE_H_INCLUDED
