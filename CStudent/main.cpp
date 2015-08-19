#include <iostream>
#include "cstudent.h"
using namespace std;

int main()
{
	{  
			 Date birth1(1992,1,1);
    Date birth2(1993,2,2);

    cstudent t1(birth1,"zhangsan");
    t1.getno();
    t1.getName();
    t1.GetbirthDate();
    
				cstudent t11(t1);
			 t11.getno();
    t11.getName();
    t11.GetbirthDate();
    
				t11.setName("wangwu");
				t11.SetBirthDate(1993,1,1);
				t11.getno();
    t11.getName();
    t11.GetbirthDate();
				
    static cstudent t2(birth2,"lishi");
    t2.getno();
    t2.getName();
    t2.GetbirthDate();
 }

   system("pause");
}
