#ifndef MYEXCEPTIONHANDING_H
#define MYEXCEPTIONHANDING_H


class MyExceptionHanding
{
   public:
      MyExceptionHanding(char *);
      virtual ~MyExceptionHanding();
      char *what()const;
   protected:
   private:
   char *message;
};

#endif // MYEXCEPTIONHANDING_H
