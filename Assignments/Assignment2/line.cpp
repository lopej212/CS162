/* Jose Manuel Lopez Alcala
 * Assignment 2
 * File Name: line.cpp
 */
#include "line.hpp"
#include <iostream> 
using namespace std;
Point Line::getPoint1()
{
   return point1;
}

Point Line::getPoint2()
{
   return point2;
}
/*****************************
 * Description: This function will take two point objects and 
 * 		test them to check if they are the same point. 
 * 		If they are not the same, then copies the values
 * 		from the objects being passed to the points being used 
 * 		inside the line class for this line object.
 * 		If they are the same, then it will termniate the program.
 */		
Line::Line(Point p1, Point p2)
{
   /*
   cout <<"Test: " << p1.xget() << endl;//for testing
   cout <<"Test: " << p2.xget() << endl;//for testing
   cout <<"Test: " << p1.yget() << endl;//for testing
   cout <<"Test: " << p1.yget() << endl;//for testing
   */
   if((p1.xget() == p2.xget()) && (p1.yget() == p2.yget()))
   {
      throw DegenerateLineException(true);
   }

   point1 = p1;
   point2 = p2;
}
/****************************
 * Description: This function will calculte the slope of the line 
 * 		that this function is woring on. If the slope is undefinee,
 * 		then the funciton will return an exception and terminate 
 * 		the program. 
 */
double Line::slope()
{
   double y_delta = point2.yget() - point1.yget();
   double x_delta = point2.xget() - point1.xget();
   //cout << "Y_delta: " << y_delta << endl;// for testing
   //cout << "X_delta:" << x_delta << endl;//for testing

   if(x_delta == 0)
   {
      throw UndefinedSlopeException(true);
   }

   double slope = y_delta/x_delta;

   return slope;
}
/**************************************
 * Description: This function will return the point at which 
 * 		the lines intersect. If the lines are coincident 
 * 		or the lines are parallel, then it will return a  
 * 		excpetion and terminate the program
 */
Point Line::intersectWith(Line l)
{
   //Line1 
   double x1 = point1.xget();
   //cout << "x1: " << x1 << endl; //for testing 
   double x2 = point2.xget();
   //cout << "x2: " << x2 << endl; //for testing 
   double y1 = point1.yget();
   //cout << "y1: " << y1 << endl; //for testing 
   double y2 = point2.yget();
   //cout << "y2: " << y2 << endl; //for testing 
   //Line2
   Point p_x3 = l.getPoint1();
   Point p_x4 = l.getPoint2();

   double x3 = p_x3.xget(); 
   //cout << "x3: " << x3 << endl; //for testing 
   double x4 = p_x4.xget(); 
   //cout << "x4: " << x4 << endl; //for testing 
   double y3 = p_x3.yget(); 
   //cout << "y3: " << y3 << endl; //for testing 
   double y4 = p_x4.yget();
   //cout << "y4: " << x1 << endl; //for testing 

   double denum = (x1-x2)*(y3-y4)-(y1-y2)*(x3-x4);
   //cout << "denum: " << denum << endl;//for testing

   if(denum == 0)
   {
      throw ParallelLinesException(true);
   }

   //This is where the numerator and denominator are calcualted. They are calculated separetly to avoid
   //confusion
  double px = ((x1*y2-y1*x2)*(x3-x4)-(x1-x2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));
 double py = ((x1*y2-y1*x2)*(y3-y4)-(y1-y2)*(x3*y4-y3*x4))/((x1-x2)*(y3-y4)-(y1-y2)*(x3-x4));

 //cout << "px: " << px << endl;//for testin
 //cout << "py: " << py << endl;// for testing 

 //This is where the point is created. 
 Point point_intersect(px,py);

 return point_intersect;
}


