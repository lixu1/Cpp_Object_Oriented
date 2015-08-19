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
    cout<<"**************��ӭ����ѡ��ϵͳ***************\n";
    cout<<"������������������ա���ʽΪ������ 1991 1 1\n";
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
								cout<<"ѧ����ѧ���ǣ�"<<student->getAllcreditHour()<<endl; break;
        case 5:
        cout<<"ѧ�������ǣ�"<<fixed<<setprecision(2)<<student->calcCredit()<<endl;break;
        case 6:
        student->setScore();break;
					}
    }
    return 0;
}

int Control::DisplayMenu()
{
    int ans;
    cout<<"\n���˵����£��������������Ӧ���ţ�\n";
    cout<<"0,�˳�ϵͳ\n";
    cout<<"1,ѡ���޿�\n";
    cout<<"2,ѡѡ�޿�\n";
    cout<<"3,��ѯ��ѡ�γ�\n";
    cout<<"4,��ѯ���ſγ̳ɼ�\n";
    cout<<"5,��ѯ����ɼ�\n";
    cout<<"6,Ϊ���ſγ�����\n";
    cin>>ans;
    return ans;
}
void Control::BuildCourse()
{
    ocourse[0]=new ObligatoryCourse("C++�ߵȳ������2",3);
    ocourse[1]=new ObligatoryCourse("�ߵ���ѧ",6);
    ocourse[2]=new ObligatoryCourse("���Դ���",3);
    allObNumber=3;
    ecourse[0]=new ElectiveCourse("������",2);
    ecourse[1]=new ElectiveCourse("����Դ����",1);
    allElNumber=2;
}

void Control::chooseCourse(int a)
{
    if(a==1)
    {
       cout<<"���޿����£�\n";
       for(int i=0;i<getallObNumber();i++)
       {
          cout<<i<<" "<<*ocourse[i];
       }
       cout<<"������Ҫѡ��Ŀγ̱�ţ����븺������\n";
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
       cout<<"ѡ�޿����£�\n";
       for(int i=0;i<getallElNumber();i++)
       {
          cout<<i<<" "<<*ecourse[i];
       }
       cout<<"������Ҫѡ��Ŀγ̱�ţ����븺������\n";
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
