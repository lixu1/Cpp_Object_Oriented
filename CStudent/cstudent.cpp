#include "cstudent.h"
#include <cstring>
#include "Date.h"
#include <iostream>
using namespace std;

int cstudent::count=0;

cstudent::cstudent( Date &d, char *s)
:birthDate(d)
{
   name==NULL;
   count++;
   cout<<"Creat a new object,now have "<<count<<" object!"<<endl;
   setName(s);
}

cstudent::cstudent(cstudent &s)
:birthDate(s.birthDate)
{
   count++;
   cout<<"Copy a new object,now have "<<count<<" object!"<<endl;
   setName(s.name);
}

cstudent::~cstudent()
{
   count--;//dtor
   cout<<"Delect a "<<name<<" object ,now have "<<count<<" object!"<<endl;
   delete [] name;
}


void cstudent::setName(char *s)
{
	   if(name!=NULL) {delete []name; }
    int length=strlen(s);
    name=new char[length+1];//ctor
    strcpy(name,s);
}
void cstudent::getName()
{
    cout<<name<<endl;
}
void cstudent::getno()
{
    cout<<count<<endl;
}
void cstudent::GetbirthDate()
{
   birthDate.print();
}
void cstudent::SetBirthDate(int a,int b,int c)
{
   birthDate.SetDay(c);
   birthDate.SetMonth(b);
   birthDate.SetYear(a);
}
