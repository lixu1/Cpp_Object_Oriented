#include "Student.h"
#include <iomanip>

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
char* Student::getName()
{
    return name;
}
int Student::getno()
{
    return count;
}

int Student::getCourseNumber()const
{
    return courseNumber;
}
int Student::getObligatoryNumber()const
{
    int n=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        n++;
    }
    return n;
}

int Student::getElectiveNumber()const
{
    int n=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        n++;
    }
    return n;
}

Date Student::GetbirthDate()
{
   return birthDate;
}
int Student::getAllcreditHour()const
{
    int allcredithour=0;
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
		{allcredithour=allcredithour+courseList[i]->GetcreditHour();}
    }
    return allcredithour;
}
double Student::calcCredit()const
{
    double obli = 0.0;
    double elec = 0.0;
    double all=getAllcreditHour();
    double alle=getElectiveNumber();
    for(int i=0;i<courseNumber;i++)
    {
        if(typeid(ObligatoryCourse)==typeid(*courseList[i]))
        {
            obli=obli + ((courseList[i]->getScore() * (courseList[i]->GetcreditHour()))/all);
			//cout<<obli<<endl;
        }
        if(typeid(ElectiveCourse)==typeid(*courseList[i]))
        {
            elec=elec + (courseList[i]->getScore()/alle);
			//cout<<elec<<endl;
        }

    }
	//cout<<all<<" "<<alle<<endl;
	//cout<<courseNumber<<endl;
    double ans=obli*0.6+elec*0.4;
    return  ans;
}
string Student::getCourseName(int i)
{
    return courseList[i]->Getname();
}

int Student::getCoursecreditHour(int i)
{
	return courseList[i]->GetcreditHour();
}
int Student::getScore(int i)
{
	return courseList[i]->getScore();
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
   output<<"����: "<<d.name<<" ��������: "<<d.birthDate
   <<" ѡ����Ϣ����:"<<endl;
   for(int i=0;i<d.courseNumber;i++)
   output<<*d.courseList[i];
   output<<"ѡ��������: "<<d.courseNumber<<endl;
   output<<"ѧ��������: "<<fixed<<setprecision(2)<<d.calcCredit()<<endl;
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
      cout<<*courseList[i]<<endl;
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
