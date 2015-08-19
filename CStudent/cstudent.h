#ifndef CSTUDENT_H
#define CSTUDENT_H
#include "Date.h"

class cstudent
{
   public:
      cstudent( Date &,  char *);
      cstudent (cstudent &);
      void setName( char*);
      void getName();
						
      void getno();

      void SetBirthDate(int ,int ,int);
      void GetbirthDate();

      virtual ~cstudent();
   protected:
   private:
      char * name;
      Date birthDate;
      static int count;
};

#endif // CSTUDENT_H
