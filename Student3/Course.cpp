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
   output<<"  �γ�����"<<c.name<<"  ѧ�֣� "<<c.creditHour<<endl;
   return output;
}



