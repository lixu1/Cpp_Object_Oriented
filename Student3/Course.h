#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>

using namespace std;

class Course
{
   friend ostream &operator<<(ostream& ,const Course &);
   public:
      Course(string ='\0',int=0);
      virtual ~Course();

      string Getname();
      int GetcreditHour();
      void Setname(string );
      void SetcreditHour(int );
   protected:
   private:
   string name;
   int creditHour;
};

#endif // COURSE_H
