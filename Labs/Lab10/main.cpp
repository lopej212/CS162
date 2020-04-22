//Jose Manuel Lopez Alcala
//Lab10 

#include "StringList.hpp"
#include <iostream> 
int main()
{
   StringList List1;

   List1.add("1");
   List1.add("5");
   List1.add("7");
   List1.add("8");

   List1.displayList();

   std::cout << "The size of the list: " <<  List1.size() << std::endl;

   std::cout << "The position of the \"7\" : " << List1.positionOf("7") << std::endl;

   StringList List2 = List1;

   std::cout << "This is list 2: " << std::endl;
   List2.displayList(); 




   return 0;
}

