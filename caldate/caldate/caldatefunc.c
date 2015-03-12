
#include "stdafx.h"
//#include "typedefine.h"
//#include "caldate.h"

extern U16 is_leap_year(U16 year)
{
    return (year%4 == 0 && year % 100 != 0)||( year % 400 == 0 && year % 100 ==0);
}
