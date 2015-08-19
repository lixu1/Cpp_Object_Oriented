#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    cout<<"Welcome to choose your course!\nEnter you name and you birthday's year,month and day\n";
    char name[10];
    cin>>name;
    int year,month,day;
    cin>>year>>month>>day;
    Date d(year,month,day);
    Student student1(d,name);

    ObligatoryCourse ObligatoryCourse1("C++高等程序设计2",3);
    ObligatoryCourse ObligatoryCourse2("高等数学",6);
    ObligatoryCourse ObligatoryCourse3("线性代数",3);
    ElectiveCourse ElectiveCourse1("机器人",2);
    ElectiveCourse ElectiveCourse2("新能源技术",1);

    cout<<"必修课\n   1.C++高等程序设计2\n   2.高等数学\n   3.线性代数\n选修课\n   4.机器人\n   5.新能源技术\n输入你要选择的课程的代号，输入数字0结束\n";
    int ans;
    int checkcourseno[6];
    for(int i=0;i<6;i++)
    checkcourseno[i]=0;

    int p=0;
    while(cin>>ans && ans!=0)
    {
        int i=0;
        for(i=0;i<p;i++)
        {
            if(checkcourseno[i]==ans) break;
        }
        if(checkcourseno[i]==ans)
        {cout<<"你已经选了该门课程，不用重复选课！请重新输入！\n";}
        else
        {
            checkcourseno[p]=ans ;
            p++;
            switch(ans)
            {
            case 1:
                student1.chooseObligatoryCourse(& ObligatoryCourse1);
                break;
            case 2:
                student1.chooseObligatoryCourse(& ObligatoryCourse2);
                break;
            case 3:
                student1.chooseObligatoryCourse(& ObligatoryCourse3);
                break;
            case 4:
                student1.chooseElectiveCourse(& ElectiveCourse1);
                break;
            case 5:
                student1.chooseElectiveCourse(& ElectiveCourse2);
                break;
            default:
                cout<<"你输入了一个错误的课程代号！请重新输入！";
                break;
            }
        }
    }
    cout<<student1;
    cout<<"输入你的分数！\n";
    for(int i=0;i<student1.getCourseNumber();i++)
    {
        if(student1.isObligatoryCourse(i)) {cout<<student1.getCourseName(i);cout<<"  请输入成绩！\n" ; int mark;cin>>mark; student1.ObligatoryCourseSetGrade(i,mark); }
        else  {cout<<student1.getCourseName(i);cout<<"  请输入成绩！\n"; char mark ; cin>>mark ; student1.ElectiveCourseSetGrade(i,mark); }
    }
    cout<<student1;

}
