/*************************************************
 * Author: Jose Manuel Lopez Alcala
 * Date: 10/18/2017
 * Description: This program will create two lines from four 
 * 		points created at the top of the program. It will 	
 * 		then proceed to find slope and point of intersection fo the 
 * 		two lines and will print out all this information to the
 * 		user. 
 */
#include <iostream>
#include <string>
#include "line.hpp"
using namespace std;
int main()
{
   //Line 1 points**************** 
   double x1 = 0.5;
   double y1 = 1.5;

   double x2 = 2.0;
   double y2 = 0.0;
   //Line 2 points***************
   double x3 = 0.0;
   double y3 = 1.0;

   double x4 = -0.5;
   double y4 = 0.0;
   //LINE 1
   //This try-catch block will make sure that the 
   //points that are inside are not the same 
   try{
   Point pt1(x1,y1);
   Point pt2(x2,y2);
   Line line1(pt1,pt2);
   }catch(Line::DegenerateLineException dg)
   {
      cout<< "DegenerateLineException: " << dg.same << endl;
      return 0;
   }
   //If points are not the same, then the points 
   //are created and the line object made
   Point pt1(x1,y1);
   Point pt2(x2,y2);
   Line line1(pt1,pt2);

   //This try-catch block will check for an undefined slop
   //If the slop is undefined, then the program will terminate. 
   try{
   double slope = line1.slope();
   }catch(Line::UndefinedSlopeException(us))
   {
      cout << "UndefinedSlopeException: " << us.undefined << endl;
      return 0;
   }
   double slope = line1.slope();
   cout << "Line 1 slope: " << slope << endl;

   //LINE2 
   //This try-catch block will make sure that the 
   //points that are inside are not the same 
   try{
   Point pt3(x3,y3);
   Point pt4(x4,y4);
   Line line2(pt3,pt4);
   }catch(Line::DegenerateLineException dg)
   {
      cout<< "DegenerateLineException: " << dg.same << endl;
      return 0;
   }
   //If points are not the same, then the points 
   //are created and the line object made
   Point pt3(x3,y3);
   Point pt4(x4,y4);
   Line line2(pt3,pt4);

   //This try-catch block will check for an undefined slop
   //If the slop is undefined, then the program will terminate. 
   try{
   double slope2 = line2.slope();
   }catch(Line::UndefinedSlopeException(us))
   {
      cout << "UndefinedSlopeException: " << us.undefined << endl;
      return 0;
   }
   double slope2 = line2.slope();
   cout << "Line 2 slope: " << slope2 << endl;


   //This is where the intersection will be done
   //cout << "I made it Here" << endl; //for testing
   try{
   Point intersection = line1.intersectWith(line2);
   }catch(Line::ParallelLinesException(pl))
   {
      cout << "ParallelLinesException: " << pl.parallel << endl;
      return 0;
   }

   //This is the point that gets created for the intersection location 
   Point intersection = line1.intersectWith(line2);

   //Prints out the coordinate of intersection
   cout << "Coordinate of intersection: ";
   cout << "(" << intersection.xget() << "," << intersection.yget() << ")" << endl;


   return 0;
}

