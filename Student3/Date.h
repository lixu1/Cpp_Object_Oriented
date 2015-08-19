#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;

class Date
{
    friend ostream &operator<<(ostream & ,const Date &);
    friend istream &operator>>(istream & ,Date &);
    public:
        Date(int x=2000,int y=1,int z=1);
        Date(Date &);
        void SetYear(int);
        void SetMonth(int );
        void SetDay(int);

        int GetDay()const ;
        int GetMonth()const ;
        int GetYear()const ;

        bool isLeapYear()const ;
        void nextDay();

        Date &operator++();
        Date operator++(int);
        Date& operator+(int );

        virtual ~Date();
    protected:
    private:
    int year;
    int month;
    int day;
    static const int days[13];
};

#endif // DATE_H
