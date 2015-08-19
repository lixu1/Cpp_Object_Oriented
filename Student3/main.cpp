#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Date d1;
    Date d2(1993,2,28);
    Date d3(2000,12,30);
    
    cout<<"d1 is "<<d1<<"\n"<<"d2 is "<<d2<<"\n"<<"d3 is "<<d3<<endl;

    cout<<"d2 is "<<d2.GetYear()<<"-"<<d2.GetMonth()<<"-"<<d2.GetDay()<<endl;

    if(d2.isLeapYear())cout<<d2<<" is a leapyear"<<endl;
    else cout<<d2<<" is not a leapyear"<<endl;

    if(d3.isLeapYear())cout<<d3<<" is a leapyear"<<endl;
    else cout<<d3<<" is not a leapyear"<<endl;
			
    cout<<"++d2 is "<< ++d2<<endl;
    cout<<"d2 is "<< d2 << endl;
				
				
    cout<<"d3++ is "<< (d3++) <<endl;
    cout<<"d3 is "<< d3 << endl;

    d3+366;
    cout<<"d3 + 366 days is "<<d3<<endl;

    Date d4;
    cout<<"enter a date d4 ,included three integers ,year,month,day"<<endl;
    cin>>d4;
    cout<<"d4 is "<<d4<<endl;
    {
				Student student1(d2,"李四");
    Student student2(student1);
    student2.setName("张三");
    student2.SetBirthDate(1994,01,01);

    Course course1("高级语言程序设计-2",3);
    Course course2("数学分析",5);
    Course course3("思想道德修养",2);
    Course course4("高等数学",6);
    Course course5("近现代史",2);
    Course course6("大学体育",1);

    student1.addCourse(&course1);
    student1.addCourse(&course2);
    student1.addCourse(&course3);
    student1.addCourse(&course4);
    student1.addCourse(&course5);
    student1.addCourse(&course6);

    student2.addCourse(&course4);
    student2.addCourse(&course5);
    student2.addCourse(&course6);


    cout<<student1<<"\n"<<student2<<endl;
				}
				system("pause");
    return 0;
}
