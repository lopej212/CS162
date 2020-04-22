//Lab 6 Jose Manuel Lopez Alcala
//

#ifndef MYINTEGER_H
#define MYINTEGER_H

class MyInteger
{
   private:
   int *pInteger;

   public: 
   MyInteger(int x );
   ~MyInteger();
   MyInteger(const MyInteger &myInt);
   MyInteger operator=(const MyInteger &right);
   void setMyInt(int x);
   int getMyInt();

};

#endif


