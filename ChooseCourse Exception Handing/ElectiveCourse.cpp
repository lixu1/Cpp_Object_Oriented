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
    if(a<'A'||a>'E')
    throw MyCourseException();
    grade=a;
}

int ElectiveCourse::getScore()const
{
    switch(grade)
    {
        case 'A': return 95;
        case 'B': return 85;
        case 'C': return 75;
        case 'D': return 65;
        case 'E': return 55;
        default:return 0;
    }
}
