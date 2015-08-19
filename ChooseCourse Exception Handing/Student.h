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
      void DeleteChoose(int i);//ɾ���γ�


      void ObligatoryCourseSetGrade(int ,int );
      void ElectiveCourseSetGrade(int ,char );

      void setName( char* );
      char * getName();
      int getno();

      int getCourseNumber()const;//�γ�����
      int getObligatoryNumber()const;//���޿�����
      int getElectiveNumber()const;//ѡ�޿�����

      int getAllcreditHour()const;//��ѧ��
      double calcCredit()const;//�ɼ�����

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
