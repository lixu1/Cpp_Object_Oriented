#include "Date.h"
#include <iostream>
#include <iomanip>

using namespace std;

const int Date::days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int x,int y,int z)
{
   SetYear(x);
   SetMonth(y);
   SetDay(z);
}

Date::Date(const Date &t)
{
    year=t.year;
    month=t.month;
    day=t.day;
}

Date::~Date()
{
   //dtor
}

void Date::SetYear(int x)
{
   if(year>0) year=x;
   else year=2000;
}

void Date::SetMonth(int x)
{
   if((x>0)&&(x<13)) month=x;
   else month=1;
}

void Date::SetDay(int x)
{
   if(month ==2&&isLeapYear())
      day=(x>=1&&x<=29)? x:1;
   else
      day=(x>=1&&x<=days[month]) ? x : 1;
}
int Date::GetYear()const
{
   return year;
}

int Date::GetMonth()const
{
   return month;
}

int Date::GetDay()const
{
   return day;
}

bool Date::isLeapYear()const
{
    bool a;
    int x=this->year;
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

    if(isLeapYear()&&y==2)
    {
       if(z+1<=29) z++;
    			else  { y++;z=1;}
    }
    else
    {
       if(z+1<=days[y]) z++;
       else
       {
          if(y+1<=12) {z=1;y++;}
          else {z=1;y=1;x++;}
       }
    }
    this->year = x;
    this->month=y;
    this->day=z;
}
ostream &operator<<(ostream &output ,const Date &d)
{
    output<<d.year<<"-"<<setfill('0')<<setw(2)<<d.month<<"-"<<setw(2)<<d.day;
    return output;
}

istream &operator>>(istream &input,Date &d)
{
    int x,y,z;
    input>>x>>y>>z;
    d.SetYear(x);
    d.SetMonth(y);
    d.SetDay(z);
    return input;

}
Date &Date::operator++()
{
    nextDay();
    return *this;
}
Date Date::operator++(int )
{
    Date temp= *this;
    nextDay();
    return temp;
}

Date& Date::operator+(int k)
{
    for(int i=0;i<k;i++)
    {
        nextDay();
    }
    return *this;
}
