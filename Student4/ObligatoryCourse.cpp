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
