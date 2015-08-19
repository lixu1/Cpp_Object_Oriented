#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H
#include "Course.h"
#include <iostream>
#include <string>
using namespace std;

class ElectiveCourse :public Course
{
    public:
        ElectiveCourse(string ="",int =0,char ='\0');
        virtual ~ElectiveCourse();
        char getScore(){return grade;}
        void setScore(char);

        void print();
    protected:
    private:
    char grade;
};

#endif // ELECTIVECOURSE_H
