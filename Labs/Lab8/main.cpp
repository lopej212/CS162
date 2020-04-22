//Jose Manuel Lopez Alcala
//Lab 8 
#include <iostream>
#include <vector>
#include <ctime> 
#include <cstdlib>
#include <algorithm> 
template <typename T> 
void printVec(std::vector<T> list)
{
   for( typename std::vector<T>::iterator it = list.begin(); it != list.end(); it++)
   {
      std::cout << *it << std::endl;
   }

}

template <typename T>
void shuffleVec(std::vector<T> &list) 
{
   std::srand(unsigned ( std::time(NULL)));
   std::random_shuffle(list.begin(), list.end());
}



int main()
{

   std::vector<char> list1{'a','b','c','d','e'};
   printVec( list1);
   std::cout << std::endl;
   shuffleVec(list1);
   printVec(list1);




    return 0;

}

