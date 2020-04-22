#include "MyInteger.hpp"
#include <iostream> 
using namespace std;

int main()
{
   MyInteger integer1(17);
   MyInteger integer2 = integer1;
   cout << integer1.getMyInt() << endl;
   cout << integer2.getMyInt() << endl;

   integer2.setMyInt(9);
   cout << integer1.getMyInt() << endl;
   cout << integer2.getMyInt() << endl;

   MyInteger integer3(42);
   integer2 = integer3;
   cout << integer2.getMyInt() << endl;
   cout << integer3.getMyInt() << endl;

   integer3.setMyInt(1);
   cout << integer2.getMyInt() << endl;
   cout << integer3.getMyInt() << endl;





   return 0;

}

