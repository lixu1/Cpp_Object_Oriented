#include "Course.h"

#include <string>
Course::Course(string a,int b)
{
   //ctor
   name=a;
   creditHour=b;
}

Course::~Course()
{
   //dtor
}

string Course::Getname()
{
   return name;
}

int Course::GetcreditHour()
{
   return creditHour;
}
void Course::Setname(string a)
{
   name=a;
}

void Course::SetcreditHour(int a)
{
   creditHour=a;
}

ostream &operator<<(ostream &output ,const Course &c)
{
   output<<"  课程名："<<c.name<<"  学分： "<<c.creditHour<<endl;
   return output;
}



