#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include "Student.h"
#include "course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"
#include <fstream>
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
    void Deletecourse();
    void SetScore();

    Course *ocourse[100];
    Course *ecourse[100];
    int allElNumber;
    int allObNumber;
    int getallElNumber() {return allElNumber;};
    int getallObNumber() {return allObNumber;};

    void BuildCourse();
    void SaveInformation();

    Student * student;
};

#endif // CONTROL_H
