/*******************************************
 * Author: Jose Manuel Lopez Alcala
 * Assignment 4 
 * File: Average.cpp
 ****************************************/

#include "Shape.hpp"
#include <vector>
#include <iostream>
using namespace std;


/***********************************************
 * Description: 
 * This function will take the find the area of every 
 * shape and then return the average of set
 ***********************************************/
double averageArea(const vector<Shape*> & v)
{
   double total;//This is the variable that will be returned 
   for( int i = 0; i < v.size(); i++)
   {
     total +=  v[i]->Area();
   }

  // cout << "Total before division: " << total << endl;//Test

   double avg = total/(v.size());

   return avg;

}

