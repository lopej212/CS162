/******************************************
 * Author: Jose Manuel Lopez Alcala
 * Class: CS162
 * Assignment4
 * File: main.cpp 
 *****************************************/

#include <iostream>
#include "Shape.hpp"
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Square.hpp" 
#include <vector>

using namespace std;

//Average function in other file
double averageArea(const vector<Shape*> &v);

int main()
{
   //Creation of Shape pointers 
   //pointing to circles, rectangles,and 
   //squares
   Shape *c1 = new Circle(3);
   Shape *c2 = new Circle(4);

   Shape *r1 = new Rectangle(5,3);
   Shape *r2 = new Rectangle(6,4);

   Shape *s1 = new Square(7);
   Shape *s2 = new Square(8);

   //Creation of Vector 
   vector<Shape*> shapes{c1, c2,r1,r2,s1,s2};
   

   //Set one of shapes
   cout << "Set one of Shapes: " << endl;
   cout << "Cirlce1 Area: "  << c1->Area() << endl;//Test
   cout << "Circle1 Perimeter: " << c1->Perimeter() << endl;//Test
   cout << "Rectangle1 Area: " << r1->Area() << endl;//Test
   cout << "Rectagnle1 Perimeter: " << r1->Perimeter() << endl;//Test
   cout << "Square1 Area: " << s1->Area() << endl;//Test
   cout << "Square1 Perimeter: " << s1->Perimeter() << endl;//Test
  
   cout << endl; 
   //Set two of Shapes  
   cout << "Set two of Shapes: " << endl;
   cout << "Cirlce2 Area: "  << c2->Area() << endl;//Test
   cout << "Circle2 Perimeter: " << c2->Perimeter() << endl;//Test
   cout << "Rectangle2 Area: " << r2->Area() << endl;//Test
   cout << "Rectagnle2 Perimeter: " << r2->Perimeter() << endl;//Test
   cout << "Square2 Area: " << s2->Area() << endl;//Test
   cout << "Square2 Perimeter: " << s2->Perimeter() << endl;//Test

   cout << endl;
   cout << "Average area of shapes: ";
   cout << averageArea(shapes) << endl;

   //Deallocation of memory
   delete c1;
   delete c2;
   delete r1;
   delete r2;
   delete s1;
   delete s2;



   return 0;

}

