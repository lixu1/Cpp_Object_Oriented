#include "Date.h"
#include <iostream>
using namespace std;
int main()
{
	Date d1;
	Date d2(1993,2,28);
	cout<<d1<<"\n"<<d2<<endl;
	d2++;
	cout<<d2<<endl;
	++d2;
	cout<<d2++<<endl;
	cout<<++d2<<endl;
	cout<<d2<<endl;
	system("pause"); 
} 
