//Jose Manuel Lopez Alcala
//Lab 7 
//main.cpp
#include "CustomerProject.hpp"
#include "PreferredProject.hpp"
#include "RegularProject.hpp"
#include <iostream>
using namespace std;
int main()
{
   PreferredProject pp(10,30,8);
   CustomerProejct *cp_pp &pp;

   RegularProject rp(10,30,8);
   CustomerProject *cp_rp = &rp;

   cout << "PreferredProject cost."  << endl;
   cp_pp->billAmount();
   cout "RegularProject cost." << endl;
   cp_rp->billAmount();

   return 0;

}


  
