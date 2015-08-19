#ifndef DATE_H
#define DATE_H

class Date
{
   public:
      Date (int =2000,int =1,int=1);
      Date(Date &);
      //Date();
      virtual ~Date();
      int GetYear();
      int GetMonth();
      int GetDay();
      void SetYear(int );
      void SetMonth(int );
      void SetDay(int );

      bool isLeapYear();
      void nextDay();
      void print();
   protected:
   private:
      static int days[13];
      unsigned int x;
      int year,month,day;
};
#endif // DATE_H
