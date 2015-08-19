#include "MyExceptionHanding.h"

MyExceptionHanding::MyExceptionHanding(char *a)
{
   message=a;//ctor
}

MyExceptionHanding::~MyExceptionHanding()
{
   //dtor
}
char *MyExceptionHanding::what()const
{
   return message;
}
