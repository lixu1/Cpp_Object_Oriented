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
        int getScore()const;
        void setScore(char);


    protected:
    private:
    char grade;
};

#endif // ELECTIVECOURSE_H
