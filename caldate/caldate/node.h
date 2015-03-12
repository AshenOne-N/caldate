#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

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

typedef struct time_node
{
    U16 year;
    U16 month;
    U16 day;
    U16 hour;
    U16 minite;
    U16 second;
}TIME,*ptr_to_time;
typedef ptr_to_time DATE;


#endif // NODE_H_INCLUDED
