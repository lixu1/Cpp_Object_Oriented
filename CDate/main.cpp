#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
    int year=2011,month=12,day=30;
    Date date(year,month,day);
    cout<<"year is "<<date.GetYear()<<" month is "<<date.GetMonth()
    <<" day is "<<date.GetDay()<<endl;
    date.print();
    if(date.isLeapYear()) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    date.nextDay();
    date.print();
    date.nextDay();
    date.print();
    if(date.isLeapYear()) cout<<"Yes"<<endl;
    else cout<<"NO"<<endl;
    int a,b,c;
    cin>>a>>b>>c;
    Date date1(a,b,c);
    date1.print();
    return 0;
}
