#include <iostream> 
#include <string> 
#include "numContainer.hpp"
using namespace std;

NumContainer::NumContainer(int s)
{
   size = s;
   ptr = new double[size];

}

void NumContainer::fillArray()
{
   for(int i = 0; i < size; i++)
   {
      cout <<"Enter number for index: " << size << endl;
      cin>> ptr[i];
   }
}

