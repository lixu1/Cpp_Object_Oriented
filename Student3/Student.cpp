#include "Student.h"
#include "Course.h"
#include <cstring>
#include "Date.h"
#include <iostream>
using namespace std;

int Student::count=0;


Student::Student( Date &d, char *s)
:birthDate(d)
{
   name=NULL;
   count++;
   cout<<"Creat a "<<s<<" object,now have "<<count<<" object!"<<endl;
   setName(s);
   for(int i=0;i<20;i++)
   courseList[i]=NULL;
   courseNumber=0;
}

Student::Student(Student &s)
:birthDate(s.birthDate)
{
   count++;
   cout<<"Copy a "<<s.name<<" object,now have "<<count<<" student object!"<<endl;
   setName(s.name);
}

Student::~Student()
{
   count--;//dtor
   cout<<"Delect a "<<name<<" object ,now have "<<count<<" student object!"<<endl;
   delete [] name;
}


void Student::setName(char *s)
{
	   if(name!=NULL) {delete []name; }
    int length=strlen(s);
    name=new char[length+1];//ctor
    strcpy(name,s);
}
void Student::getName()
{
    cout<<name<<endl;
}
void Student::getno()
{
    cout<<count<<endl;
}
void Student::GetbirthDate()
{
   cout<<birthDate<<endl;
}
void Student::SetBirthDate(int a,int b,int c)
{
   birthDate.SetDay(c);
   birthDate.SetMonth(b);
   birthDate.SetYear(a);
}

Student& Student::addCourse(Course *course )
{
   courseList[courseNumber]=course;
   courseNumber++;
   return *this;
}
ostream &operator<<(ostream & output ,const Student &d)
{
   output<<"姓名： "<<d.name<<"      出生日期： "<<d.birthDate
   <<", 选课信息如下："<<endl;
   for(int i=0;i<d.courseNumber;i++)
   cout<<*(d.courseList[i]);
   
			return output;
}
