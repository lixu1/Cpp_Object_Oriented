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

    ObligatoryCourse ObligatoryCourse1("C++�ߵȳ������2",3);
    ObligatoryCourse ObligatoryCourse2("�ߵ���ѧ",6);
    ObligatoryCourse ObligatoryCourse3("���Դ���",3);
    ElectiveCourse ElectiveCourse1("������",2);
    ElectiveCourse ElectiveCourse2("����Դ����",1);

    cout<<"���޿�\n   1.C++�ߵȳ������2\n   2.�ߵ���ѧ\n   3.���Դ���\nѡ�޿�\n   4.������\n   5.����Դ����\n������Ҫѡ��Ŀγ̵Ĵ��ţ���������0����\n";
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
        {cout<<"���Ѿ�ѡ�˸��ſγ̣������ظ�ѡ�Σ����������룡\n";}
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
                cout<<"��������һ������Ŀγ̴��ţ����������룡";
                break;
            }
        }
    }
    cout<<student1;
    cout<<"������ķ�����\n";
    for(int i=0;i<student1.getCourseNumber();i++)
    {
        if(student1.isObligatoryCourse(i)) {cout<<student1.getCourseName(i);cout<<"  ������ɼ���\n" ; int mark;cin>>mark; student1.ObligatoryCourseSetGrade(i,mark); }
        else  {cout<<student1.getCourseName(i);cout<<"  ������ɼ���\n"; char mark ; cin>>mark ; student1.ElectiveCourseSetGrade(i,mark); }
    }
    cout<<student1;

}
