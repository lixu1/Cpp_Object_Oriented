#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"

#include <iostream>
#include <string>
using namespace std;

class Student
{
   friend ostream &operator<<(ostream & ,const Student &);
   public:
      Student ( Date &,  char * );
      Student (Student &);


      Student& chooseObligatoryCourse(ObligatoryCourse * ObligatoryCourse1);
      Student& chooseElectiveCourse(ElectiveCourse * ElectiveCourse1);

      bool isObligatoryCourse(int a) { return obligatoryCourse[a];}
      void ObligatoryCourseSetGrade(int ,int );
      void ElectiveCourseSetGrade(int ,char );

      void setName( char* );
      void getName();
      int getno();
      int getCourseNumber();
      string getCourseName(int);

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
      bool obligatoryCourse[20];
};

#endif // CSTUDENT_H
