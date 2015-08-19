#ifndef CONTROL_H
#define CONTROL_H
#include "Student.h"
#include <iostream>
using namespace std;

class Control
{
    public:
        Control();
        virtual ~Control();
        int run();
    protected:

    private:
    int DisplayMenu();
    void chooseCourse(int);

    Course *ocourse[10];
    Course *ecourse[10];
    int allElNumber;
    int allObNumber;
    int getallElNumber() {return allElNumber;};
    int getallObNumber() {return allObNumber;};

    void BuildCourse();
    void printCourse();
    void printScore();


    int onumber;
    int enumber;
    Student * student;
};

#endif // CONTROL_H
