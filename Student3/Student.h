#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"
#include "Course.h"
#include <iostream>
using namespace std;

class Student
{
   friend ostream &operator<<(ostream & ,const Student &);
   public:
      Student( Date &,  char * );
      Student (Student &);

      Student& addCourse(Course *course );

      void setName( char* );
      void getName();
      void getno();

      void SetBirthDate(int ,int ,int);
      void GetbirthDate();

      virtual ~Student();
   protected:
   private:
      char * name;
      Date birthDate;
      static int count;
      Course *courseList[20];
      int courseNumber;
};

#endif // CSTUDENT_H
