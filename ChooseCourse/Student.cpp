#include "Student.h"
#include "string.h"
int Student::count=0;


Student::Student( Date &d, char *s)
:birthDate(dm)
{
   name=NULL;
   count++;
   setName(s);
   for(int i=0;i<20;i++)
   courseList[i]=NULL;
   courseNumber=0;
}

Student::Student(Student &s)
:birthDate(s.birthDate)
{
   count++;
   setName(s.name);
   for(int i=0;i<20;i++)
   courseList[i]=NULL;
   courseNumber=0;
}

Student::~Student()
{
   count--;//dtor
   delete [] name;
   for(int i=0;i<courseNumber;i++)
    delete courseList[i];

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
int Student::getno()
{
    return count;
}

int Student::getCourseNumber()
{
    return courseNumber;
}
void Student::GetbirthDate()
{
   cout<<birthDate<<endl;
}

string Student::getCourseName(int i)
{
    return courseList[i]->Getname();
}
void Student::SetBirthDate(int a,int b,int c)
{
   birthDate.SetDay(c);
   birthDate.SetMonth(b);
   birthDate.SetYear(a);
}



Student& Student::chooseObligatoryCourse(ObligatoryCourse * ObligatoryCourse1)
{
    courseList[courseNumber]=new ObligatoryCourse(* ObligatoryCourse1);
    obligatoryCourse[courseNumber]=true;
    courseNumber++;
    return *this;
}

Student& Student::chooseElectiveCourse(ElectiveCourse *ElectiveCourse1)
{
    courseList[courseNumber]=new ElectiveCourse(* ElectiveCourse1);
    obligatoryCourse[courseNumber]=false;
    courseNumber++;
    return *this;
}

ostream &operator<<(ostream & output ,const Student &d)
{
   output<<"姓名： "<<d.name<<"      出生日期： "<<d.birthDate
   <<", 选课信息如下："<<endl;
   for(int i=0;i<d.courseNumber;i++)
   {
       if(d.obligatoryCourse[i])
       {
           cout<< *(d.courseList[i]);
           ((ObligatoryCourse *)d.courseList[i])->print();
       }
       if(! d.obligatoryCourse[i])
       {
           cout<< *(d.courseList[i]);
           ((ElectiveCourse *)d.courseList[i])->print();
       }
   }
   cout<<"选课总数是 "<<d.courseNumber<<endl;

    return output;
}
void Student::ObligatoryCourseSetGrade(int courseNumber,int mark)
{
    ((ObligatoryCourse *)courseList[courseNumber])->setScore(mark);
}
void Student::ElectiveCourseSetGrade(int courseNumber,char mark)
{
    ( (ElectiveCourse *)courseList[courseNumber] )->setScore(mark);
}
