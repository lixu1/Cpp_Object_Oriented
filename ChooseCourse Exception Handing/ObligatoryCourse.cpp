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
    if(a<0||a>100)
    throw MyCourseException();
    mark=a;
}
