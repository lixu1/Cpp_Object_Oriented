#include "Date.h"
#include <iostream>
using namespace std;
Date::Date(int x,int y,int z)
{
   SetYear(x);
   SetMonth(y);
   SetDay(z);
}
Date::~Date()
{
   //dtor
}
void Date::SetYear(int x)
{
   if(year>0) year=x;
}
void Date::SetMonth(int x)
{
   if((x>0)&&(x<13)) month=x;
}
void Date::SetDay(int x)
{
   if((x>0)&&(x<32))
   day=x;
}
int Date::GetYear()
{
   return year;
}
int Date::GetMonth()
{
   return month;
}
int Date::GetDay()
{
   return day;
}
bool Date::isLeapYear()
{
    bool a;
    x=this->year;
    if(x%4==0)
    {
        a=true;
        if(x%100==0)
        {
            a=false;
            if(x%400==0) a=true;
        }
    }
    return a;
}
void Date::nextDay()
{
    int x,y,z;
    x=this->year;
    y=this->month;
    z=this->day;
    int a[13];
    a[1]=31;a[3]=31;a[5]=31;a[7]=31;a[8]=31;a[10]=31;a[12]=31;
    if(isLeapYear()) a[2]=29;
    else a[2]=28;
    a[4]=30;a[6]=30;a[9]=30;a[11]=30;
    if(z+1<=a[y]) z++;
    else
    {
        if(y+1<=12) {z=1;y++;}
        else {z=1;y=1;x++;}
    }
    this->year = x;
    this->month=y;
    this->day=z;
}
void Date::print()
{
    cout<<month<<'/'<<day<<'/'<<year<<endl;
}
