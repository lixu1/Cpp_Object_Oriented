#include "Student.h"

int Student::count=0;


Student::Student( Date &d, char *s)
:birthDate(d)
{
   name=NULL;
   count++;
   setName(s);
   for(int i=0;i<20;i++)
   courseList[i]=NULL;
   courseNumber=0;
}

Student::Student(int y,int m,int d,char *s)
:birthDate(y,m,d)
{
   name=NULL;
   count++;
   setName(s);
   for(int i=0;i<20;i++) courseList[i]=NULL;
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

int Student::getObligatoryNumber()
{
    int n=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        n++;
    }
    return n;
}

int Student::getElectiveNumber()
{
    int n=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        n++;
    }
    return n;
}

void Student::GetbirthDate()
{
   cout<<birthDate<<endl;
}
int Student::getAllcreditHour()
{
    int allcredithour=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
								allcredithour=allcredithour+courseList[i]->GetcreditHour();
    }
    return allcredithour;
}
double Student::calcCredit()
{
    double obli = 0.0;
    double elec = 0.0;
    double all=getAllcreditHour();
    double alle=getElectiveNumber();
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            cout<<courseList[i]->getScore()<<endl;
												obli=obli + ((courseList[i]->getScore() * (courseList[i]->GetcreditHour()))/all);
        }
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            elec=elec + (courseList[i]->getScore()/alle);
        }

    }
    cout<<obli<<endl;
    cout<<elec<<endl;
    double ans=obli*0.6+elec*0.4;
    return  ans;
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
    courseNumber++;
    return *this;
}

Student& Student::chooseElectiveCourse(ElectiveCourse *ElectiveCourse1)
{
    courseList[courseNumber]=new ElectiveCourse(* ElectiveCourse1);
				courseNumber++;
    return *this;
}

ostream &operator<<(ostream & output ,const Student &d)
{
   output<<"������ "<<d.name<<"      �������ڣ� "<<d.birthDate
   <<", ѡ����Ϣ���£�"<<endl;
   for(int i=0;i<d.courseNumber;i++)
   cout<<*d.courseList[i];
   cout<<"ѡ�������� "<<d.courseNumber<<endl;
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
void Student::printScore()
{
   for(int i=0;i<getCourseNumber();i++)
   {
      cout<<*courseList[i]<<"�����ǣ�"<<courseList[i]->getScore()<<endl;
   }
}
void Student::setScore()
{
   cout<<"��Ϊ��ѡ��Ŀγ����óɼ���";
   for(int i=0;i<getCourseNumber();i++)
   {
      cout<<*courseList[i];
      if(typeid(ObligatoryCourse)==typeid(* courseList[i]))
      {
         cout<<"����ٷ��Ʒ���\n";
         int a;
         cin>>a;
         ObligatoryCourseSetGrade(i,a);
      }
      if(typeid(ElectiveCourse)==typeid(* courseList[i]))
      {
         cout<<"����ȼ�������ABCD��E\n";
         char a;
         cin>>a;
         ElectiveCourseSetGrade(i,a);
      }
   }
}
