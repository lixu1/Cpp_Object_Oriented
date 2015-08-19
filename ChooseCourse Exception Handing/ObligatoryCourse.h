#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H
#include "Course.h"
#include "MyCourseException.h"

#include <iostream>
#include <string>
using namespace std;

class ObligatoryCourse : public Course
{
    public:
        ObligatoryCourse(string ="",int =0,int =0);
        virtual ~ObligatoryCourse();
        int getScore() const {return mark;};
        void setScore(int);


    protected:
    private:
    int mark;
};

#endif // OBLIGATORYCOURSE_H
