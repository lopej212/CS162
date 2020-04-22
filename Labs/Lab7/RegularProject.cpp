//Jose Manuel Lopez Alcala
//Lab7
//RegularProject.cpp
//

#include "CustomerProject.hpp"
#include "RegularProject.hpp"

double RegularProject::billAmount()
{
   double totalcost;

   totalcost = transportation + materials + ( hours*80);
   return totalcost;
}



