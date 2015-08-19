#include "Control.h"
#include <iostream>
#include <iomanip>

Control::Control()
{
    onumber=0;
    enumber=0;//ctor
    allObNumber=0;
    allElNumber=0;
}

Control::~Control()
{
    //dtor
}
int Control::run()
{
    cout<<"**************欢迎进入选课系统***************\n";
    cout<<"请输入你的姓名，生日。格式为：张三 1991 1 1\n";
    char m[10];
    int a,b,c;
    cin>>m>>a>>b>>c;
    student=new Student(a,b,c,m);
    BuildCourse();
    int choose;
    while( (choose=DisplayMenu())&&choose)
    {
					switch(choose)
					{			
        case 1:
        chooseCourse(1);break;
        case 2:
        chooseCourse(2);break;
        case 3:
        printCourse();break;
        case 4:
        printScore();
								cout<<"学生总学分是："<<student->getAllcreditHour()<<endl; break;
        case 5:
        cout<<"学生绩点是："<<fixed<<setprecision(2)<<student->calcCredit()<<endl;break;
        case 6:
        student->setScore();break;
					}
    }
    return 0;
}

int Control::DisplayMenu()
{
    int ans;
    cout<<"\n主菜单如下：请输入操作的相应代号！\n";
    cout<<"0,退出系统\n";
    cout<<"1,选必修课\n";
    cout<<"2,选选修课\n";
    cout<<"3,查询已选课程\n";
    cout<<"4,查询各门课程成绩\n";
    cout<<"5,查询绩点成绩\n";
    cout<<"6,为各门课程评分\n";
    cin>>ans;
    return ans;
}
void Control::BuildCourse()
{
    ocourse[0]=new ObligatoryCourse("C++高等程序设计2",3);
    ocourse[1]=new ObligatoryCourse("高等数学",6);
    ocourse[2]=new ObligatoryCourse("线性代数",3);
    allObNumber=3;
    ecourse[0]=new ElectiveCourse("机器人",2);
    ecourse[1]=new ElectiveCourse("新能源技术",1);
    allElNumber=2;
}

void Control::chooseCourse(int a)
{
    if(a==1)
    {
       cout<<"必修课如下：\n";
       for(int i=0;i<getallObNumber();i++)
       {
          cout<<i<<" "<<*ocourse[i];
       }
       cout<<"输入你要选择的课程编号！输入负数结束\n";
       int a;
       cin>>a;
       while(a>=0)
       {
          student->chooseObligatoryCourse((ObligatoryCourse *)ocourse[a]);
          cin>>a;
       }
    }
    if(a==2)
    {
       cout<<"选修课如下：\n";
       for(int i=0;i<getallElNumber();i++)
       {
          cout<<i<<" "<<*ecourse[i];
       }
       cout<<"输入你要选择的课程编号！输入负数结束\n";
       int a;
       cin>>a;
       while(a>=0)
       {
          student->chooseElectiveCourse((ElectiveCourse* )ecourse[a]);
          cin>>a;
       }
    }
}
void Control::printCourse()
{
   cout<<*student;
}
void Control::printScore()
{
   student->printScore();
}
