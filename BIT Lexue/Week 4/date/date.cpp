// This is the solution of 日期】计算天数（编主函数，未来考试的形式之一）
// Created by FUGUO on 2024/11/2.
//
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <iostream>
using namespace std;

// 声明函数原型
int leap_year( int );
int year_days( int );
int days(int, int, int);

int leap_year( int year )   // 判断闰年或平年
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}

int year_days(int year)     // 计算一整年的天数
{   return leap_year( year ) ? 366 : 365;
}

int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;

    if  ( leap_year( year ) && month >2 )
        day++;

    for ( i=1; i<month; i++ )
        day += months[i];

    return day;
}

int main()
{
    int year1,month1,day1,year2,month2,day2;
    cin>>year1>>month1>>day1>>year2>>month2>>day2;
    int sum=0;

    for(int i=year1;i<year2;i++){
        sum+= year_days(i);
    }

    sum += days(year2,month2,day2)-days(year2,month1,day1);
    cout<<sum<<" days"<<endl;
    return 0;
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */