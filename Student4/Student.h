#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"

#include <iostream>
using namespace std;

class Student
{
   friend ostream &operator<<(ostream & ,const Student &);
   public:
      Student ( Date &,  char * );
      Student (Student &);
      Student (int ,int ,int ,char *);


      Student& chooseObligatoryCourse(ObligatoryCourse * ObligatoryCourse1);
      Student& chooseElectiveCourse(ElectiveCourse * ElectiveCourse1);


      void ObligatoryCourseSetGrade(int ,int );
      void ElectiveCourseSetGrade(int ,char );

      void setName( char* );
      void getName();
      int getno();

      int getCourseNumber();//�γ�����
      int getObligatoryNumber();//���޿�����
      int getElectiveNumber();//ѡ�޿�����

      int getAllcreditHour();
      double calcCredit();

      string getCourseName(int);

      void SetBirthDate(int ,int ,int);
      void GetbirthDate();
      void printScore();
      void setScore();

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
