//Jose Manuel Lopez Alcala
//lab 7 
//PreferredProject.cpp
//
#include "CustomerProject.hpp"
#include "PreferredProject.hpp"


double PreferredProject::billAmount()
{

   double totalcost;
   totalcost = (.85* materials) + ( .9* transportation);
   if(hours >= 100)
   {
      totalcost += 800;
   }else{
     totalcost += (hours*80);
   }

  return totalcost;
}


