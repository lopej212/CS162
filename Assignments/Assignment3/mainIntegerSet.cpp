/* Jose Manuel Lopez Alcala
 * Assignement3 IntegerSet
 * CS 162
 */
#include <iostream> 
#include <string> 
#include "IntegerSet.hpp"
using namespace std;

int main()
{
   //Creates set 1 and adds some values to it
   IntegerSet set1;
   set1.add(1);
   set1.add(2);
   set1.add(3);
   set1.add(4);
   set1.add(5);

   cout <<"Elements in set1: " << endl;
   set1.print();//for testing

   IntegerSet set2;
   //set2.print();
   set2 = set1;
   //cout << "Elements in set2: "<< endl;//for testing
   //set2.print();//for testing

   //Tests out fucntions: size(), isEmpty(), and contains()
   cout << "\nElements in set2: " << set2.size() << endl;

   cout << "set1.isEmpty(): " << set1.isEmpty() << endl;

   cout << "se1 contains 0: " << set1.contains(0) << endl;

   cout << "set1 contains 3: " << set1.contains(3) << endl;

   //Will add more values and test the add function again
   set1.add(6);
   cout << "\nElements in set1 after adding 6: " << endl;
   set1.print();
   set1.add(7);
   set1.add(8);
   set1.add(9);
   set1.add(10);
   set1.add(11);
   cout << "\nElemetns in set1 after adding 7,8,9,10, and 11: " << endl;
   set1.print();
   
   //Test the remove() function by removing 4
   set1.remove(4);
   cout << "\nElements in set1 after removing 4: " << endl;
   set1.print();

   //Returns as a vector 
   vector<int> vectorArray = set1.getAsVector();
   cout << "\nElements in vector: "<< endl;
   for( int i=0; i < vectorArray.size(); i++)
   {
     cout << "Index " << i << " : " << vectorArray.at(i) << endl;
   }

   //Add more elements to set three for furhter testing
   IntegerSet set3;
   set3.add(3);
   set3.add(5);
   set3.add(6);
   set3.add(7);
   
   cout << "\nThis is set1: " << endl;// for testing
   set1.print();//for testing 
   
   cout << "\nThis is set3: " << endl;// for testing
   set3.print();//for testing
   cout << "\n" << endl;
   cout << "\nI will be adding 12 to set3" << endl;// for testing
   set3.add(12);
  //Test the overloaded "+" operator 
   IntegerSet setUnion = set3+set1;
   cout << "Union set: ";
   setUnion.print();

   //Tests the "*" operator 
   //set3.print();// for testing
   IntegerSet setIntersect = set1*set3;
   cout <<"\nIntersect set: ";
   setIntersect.print();

   //Test the "/" overloaded operator
   IntegerSet symmetric = set1/set3;

   cout <<"\nSymmetric Difference Set: " << endl;
   symmetric.print(); 
   
   
   cout << endl;
   return 0;

}

