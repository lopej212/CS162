//Lab6 Jose Manuel Lopez Alcala
//

#include "MyInteger.hpp"

MyInteger::MyInteger(int x)
{
   pInteger = new int;
   *pInteger = x;
      
}

MyInteger::~MyInteger()
{
   delete pInteger;
}

MyInteger::MyInteger(const MyInteger &myInt)
{
   int * nPtr = new int;
   *nPtr = *(myInt.pInteger);
   pInteger = nPtr;

}

MyInteger MyInteger::operator=(const MyInteger &right)
{

   *pInteger = *(right.pInteger);

   return *this;
}





void MyInteger::setMyInt(int x)
{
   *pInteger = x;
}

int MyInteger::getMyInt()
{
   return *pInteger;
}


