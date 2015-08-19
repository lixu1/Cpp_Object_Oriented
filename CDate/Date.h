#ifndef DATE_H
#define DATE_H

class Date
{
   public:
      Date (int ,int ,int);
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
      unsigned int x;
      int year,month,day;
};
#endif // DATE_H
