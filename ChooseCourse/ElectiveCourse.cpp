#include "ElectiveCourse.h"

ElectiveCourse::ElectiveCourse(string a,int b,char c)
:Course(a,b)
{
    grade=c;//ctor
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}
void ElectiveCourse::setScore(char a)
{
    grade=a;
}
void ElectiveCourse::print()
{
    cout<<"选修课课程名是 "<<Course::Getname()<<" 成绩是 "<<grade<<endl;
}
