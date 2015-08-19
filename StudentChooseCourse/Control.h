#ifndef CONTROL_H
#define CONTROL_H
#include <iostream>
#include "Control.h"
#include "Student.h"
#include "course.h"
#include "ObligatoryCourse.h"
#include "ElectiveCourse.h"
#include "Date.h"

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

    Student * student;
};

#endif // CONTROL_H
