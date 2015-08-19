#include "Control.h"
#include "Date.h"
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
    cout<<"**************欢迎进入选课系统***************\n";
    cout<<"请输入你的姓名，生日。格式为：张三 1991 1 1\n";
    char m[30];
    cin>>m;
    int a,b,c;
    cin>>a>>b>>c;
    Date *da;
    bool flag=false;
    do
    {
       try
       {
          Date d1(a,b,c);
          flag=true;
          da=new Date(d1);
          cout<<*da<<endl;
       }
       catch(MyDateException &mydate)
       {
          cout<<"发生错误！"<<mydate.what()<<endl;
          cout<<"请重新输入！你的生日！\n";
          cin>>a>>b>>c;
       }

    }while(!flag);
    student=new Student(*da,m);
    delete da;

    BuildCourse();
    int choose;
    while( (choose=DisplayMenu())&&choose)
    {
		switch(choose)
		{
        case 1:chooseCourse(choose);break;
        case 2:chooseCourse(choose);break;
        case 3:cout<<*student;break;
        case 4:student->printScore();break;
        case 5:cout<<"学生绩点是："<<fixed<<setprecision(2)<< student->calcCredit() <<endl;break;
        case 6:SetScore();break;
        case 7:SaveInformation();break;
        case 8:Deletecourse();break;
        default:cout<<"输入错误选项，请重新输入！\n";break;
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
    cout<<"3,查询学生信息\n";
    cout<<"4,查询各门课程成绩\n";
    cout<<"5,查询绩点成绩\n";
    cout<<"6,为各门课程评分\n";
    cout<<"7,保存更改的信息\n";
    cout<<"8,删除课程\n";
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
void Control::chooseCourse(int a)
{
    if(a==1)
    {
       int k[100];
	   for(int i=0;i<100;i++) k[i]=-1;int length=0;
		cout<<"必修课如下：\n";
       for(int m=0;m<getallObNumber();m++)
       {
          cout<<m<<" "<<*ocourse[m];
       }
       cout<<"输入你要选择的课程编号！输入负数结束\n";
       int a;
       cin>>a;
       while(a>=0)
       {
		   int j=0;
		   while(j<length)
		   { if(k[j]==a) break;j++;}
			if(j==length||length==0)
			{student->chooseObligatoryCourse((ObligatoryCourse *)ocourse[a]);
			cout<<"你选中了该门课程！"<<*ocourse[a];k[length++]=a;}
			else cout<<"你已经选择该门课程请不要重复选课！\n"<<endl;
          cin>>a;
       }
    }
    if(a==2)
    {
       int k[100];
	   for(int i=0;i<100;i++) k[i]=-1;int length=0;
	   cout<<"选修课如下：\n";

       for(int n=0;n<getallElNumber();n++)
       {
          cout<<n<<" "<<* ecourse[n];
       }
       cout<<"输入你要选择的课程编号！输入负数结束\n";
       int a;
       cin>>a;
       while(a>=0)
       {
          int j;
		  for(j=0;j<length;j++)
		  {if(k[j]==a)break;}
		if(j==length||length==0)
		{student->chooseElectiveCourse((ElectiveCourse* )ecourse[a]);
		cout<<"你选中了该门课程！"<<*ecourse[a];k[length++]=a;}
			else cout<<"你已经选择该门课程请不要重复选课！\n"<<endl;
          cin>>a;
       }
    }
}

void Control::Deletecourse()
{
   cout<<"请输入你要删除的课程名称，一次只能删除一门课程！\n";
   try
   {
      int i;cin>>i;
      if( (*student)[i]!=NULL)
      //delete (*student)[i];
      //for(int p=i;p<student->getCourseNumber();p++)
      //(*student)[p] = (*student)[p+1];
      student->DeleteChoose(i);
   }
   catch(MyStudentException &mystudent)
   {
      cout<<"发生错误！"<<mystudent.what()<<endl;
      cout<<"删除操作被取消！\n";
   }
}
void Control::SetScore()
{
   cout<<"请输入你要设置成绩的课程代号！输入负数结束\n";
   int i;
   cin>>i;
   while(i>=0)
   {
      try
      {
         if((*student)[i]!=NULL)
         student->setScore(i);
      }
      catch(MyStudentException &mystudent)
      {
         cout<<"发生错误！"<<mystudent.what()<<endl;
         cout<<"删除操作被取消！\n";
      }
      catch(MyCourseException &mycourse)
      {
         cout<<"发生错误！"<<mycourse.what()<<endl;

      }
      cout<<"请输入你要设置成绩的课程代号！输入负数结束\n";
      cin>>i;
   }
}
void Control::SaveInformation()
{
    cout<<"学生信息保存在xuesheng.txt中\n";
    ofstream outFile("xuesheng.txt",ios::app);
    if(!outFile) {cout<<"学生信息未能成功保存\n";}
    else
    {
        outFile<<*student;

    }
    outFile.close();
}
