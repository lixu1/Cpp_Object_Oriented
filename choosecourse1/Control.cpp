#include "Control.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Control::Control()
{
    allObNumber=0;
    allElNumber=0;
}

Control::~Control()
{
    if(student!=NULL)
		delete student;
	for(int i=0;i<allObNumber;i++)
	{	delete ocourse[i];}
	for(int j=0;j<allElNumber;j++)
	{	delete ecourse[j];}//dtor
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
        chooseCourse(choose);break;
        case 2:
        chooseCourse(choose);break;
        case 3:
        cout<<*student;break;
        case 4:
        student->printScore();break;
        case 5:
        cout<<"ѧ�������ǣ�"<<fixed<<setprecision(2)<< student->calcCredit() <<endl;break;
        case 6:
        student->setScore();break;
        case 7:
			{
				cout<<"ѧ����Ϣ������xuesheng.txt��\n";
				ofstream outFile("xuesheng.txt",ios::app);
				if(!outFile) {cout<<"ѧ����Ϣδ�ܳɹ�����\n";break;}
				else
				{
					outFile<<*student;
					
				}
				outFile.close();
				break;
			}
        default:
			cout<<"�������ѡ����������룡\n";break;
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
    cout<<"7,������ĵ���Ϣ\n";
    cin>>ans;
    return ans;
}
void Control::BuildCourse()
{
    ifstream infile("kecheng.txt", ios::in);
    if ( ! infile )  return ;
    int flag;
    string name;int xuefen;
    while (!infile.eof())
    {
        infile>>flag;
        if(flag==0)
        {
            infile>>name;
            infile>>xuefen;
            ocourse[allObNumber++] = new ObligatoryCourse(name,xuefen);
        }
        if(flag==1)
        {

            infile>>name;
            infile>>xuefen;
            //cin.ignore();
            ecourse[allElNumber++]=new ElectiveCourse(name,xuefen);
        }
    }
    infile.close();
}
void Control::BuildStudent()
{

}
void Control::chooseCourse(int a)
{
    if(a==1)
    {
       int k[100];
	   for(int i=0;i<100;i++) k[i]=-1;int length=0;
		cout<<"���޿����£�\n";
       for(int m=0;m<getallObNumber();m++)
       {
          cout<<m<<" "<<*ocourse[m];
       }
       cout<<"������Ҫѡ��Ŀγ̱�ţ����븺������\n";
       int a;
       cin>>a;
       while(a>=0)
       {
		   int j=0;
		   while(j<length)
		   { if(k[j]==a) break;j++;}
			if(j==length||length==0) 
			{student->chooseObligatoryCourse((ObligatoryCourse *)ocourse[a]); 
			cout<<"��ѡ���˸��ſγ̣�"<<*ocourse[a];k[length++]=a;}
			else cout<<"���Ѿ�ѡ����ſγ��벻Ҫ�ظ�ѡ�Σ�\n"<<endl;
          cin>>a;
       }
    }
    if(a==2)
    {
       int k[100];
	   for(int i=0;i<100;i++) k[i]=-1;int length=0;
	   cout<<"ѡ�޿����£�\n";
	   
       for(int n=0;n<getallElNumber();n++)
       {
          cout<<n<<" "<<* ecourse[n];
       }
       cout<<"������Ҫѡ��Ŀγ̱�ţ����븺������\n";
       int a;
       cin>>a;
       while(a>=0)
       {
          int j;
		  for(j=0;j<length;j++)
		  {if(k[j]==a)break;}
		if(j==length||length==0) 
		{student->chooseElectiveCourse((ElectiveCourse* )ecourse[a]);
		cout<<"��ѡ���˸��ſγ̣�"<<*ecourse[a];k[length++]=a;}
			else cout<<"���Ѿ�ѡ����ſγ��벻Ҫ�ظ�ѡ�Σ�\n"<<endl;
          cin>>a;
       }
    }
}
