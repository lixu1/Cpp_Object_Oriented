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
    cout<<"ѡ�޿ογ����� "<<Course::Getname()<<" �ɼ��� "<<grade<<endl;
}
