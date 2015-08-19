#ifndef STUDENT_H
#define STUDENT_H

#include "Date.h"
#include "Course.h"
#include "ElectiveCourse.h"
#include "ObligatoryCourse.h"
#include "MyStudentException.h"

#include <typeinfo>
#include <iostream>
using namespace std;

class Student
{
   friend ostream &operator<<(ostream & ,const Student &);
   public:
      Course *operator[](int subscript);
      const Course *operator[](int subscript) const;

      Student ( Date &,  char * );
      Student (Student &);
      Student (int ,int ,int ,char *);


      Student& chooseObligatoryCourse(ObligatoryCourse * ObligatoryCourse1);
      Student& chooseElectiveCourse(ElectiveCourse * ElectiveCourse1);
      void DeleteChoose(int i);//删除课程


      void ObligatoryCourseSetGrade(int ,int );
      void ElectiveCourseSetGrade(int ,char );

      void setName( char* );
      char * getName();
      int getno();

      int getCourseNumber()const;//课程总数
      int getObligatoryNumber()const;//必修课总数
      int getElectiveNumber()const;//选修课总数

      int getAllcreditHour()const;//总学分
      double calcCredit()const;//成绩绩点

      string getCourseName(int);
      int getCoursecreditHour(int);
      int getScore(int);

      void SetBirthDate(int ,int ,int);
      Date GetbirthDate();
      void printScore();
      void setScore(int);



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
