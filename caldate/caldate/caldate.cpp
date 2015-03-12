// caldate.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "caldate.h"

int _tmain(int argc, _TCHAR* argv[])
{
        S16 i=0;
//	i = is_leap_year(1984);
//	i = is_leap_year(1983);
//	i = is_leap_year(2400);
//	printf("%d\n", i);

       // TIME time1 = { 1984, 9, 1, 0, 0, 0 };
		TIME time1 = { 2014, 9, 1, 0, 0, 0 };
        TIME time2 = { 2014, 10, 1, 0, 0, 0 };
        DATE p1,p2;
        p1 = &time1;
        p2 = &time2;
        //i = is_late(p1,p2);
		printf("%d\n", i);
		i = cal_days(p2, p1);
        printf("%d\n",i);
		i = cal_days1(p1, p2);
		printf("%d\n", i);
        return 0;
}

