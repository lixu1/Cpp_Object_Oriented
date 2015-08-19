#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(string a,int b,int c)
:Course(a,b)
{
    mark=c;//ctor
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}
void ObligatoryCourse::setScore(int a)
{
    mark=a;
}
void ObligatoryCourse::print()
{
    cout<<"必修课课程名是 "<<Course::Getname()<<" 分数是 "<<mark<<endl;
}
