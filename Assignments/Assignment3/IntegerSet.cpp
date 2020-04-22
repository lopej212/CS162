/* Jose Manuel Lopez Alcala
 * FIle NAME: IntegerSet.cpp
 */

#include "IntegerSet.hpp"
#include <iostream>
#include <vector>
using namespace std;
/*Discription: This is the constructor that makes
 * 	       the object with array size 10 and 
 * 	       numbers in set equal to zero
 */
IntegerSet::IntegerSet()
{
   ptr = new int[10];
   array_size = 10;
   numbers_inSet = 0;
}
/*Description: This is the copy constructor that will make a copy
 * 	       of everything that is in the other object and point 
 * 	       the point the pointer to its proper location
 */
IntegerSet::IntegerSet(const IntegerSet &number_set)
{
   array_size = number_set.array_size;
   ptr = new int[array_size];
   for(int i = 0 ; i < array_size; i++)
   {
      ptr[i] = number_set.ptr[i];
   }

   numbers_inSet = number_set.numbers_inSet;
}
/*Description: This is the overloaded assignement operator
 * 	       that takes two obejects and sets the left operand equal to the 	
 * 	       operand to the right 
 */
IntegerSet& IntegerSet::operator=(const IntegerSet &right)
{
   if(this != &right)
   {
      //cout << "I made it here" << endl;//for testing
      array_size = right.array_size;
      //cout << "arra_size:" << array_size << endl;//for testing
      delete [] ptr;
      ptr = new int[array_size];
      for(int i = 0; i < array_size; i++)
      {
	 ptr[i] = right.ptr[i];
	// cout<< "ptr[i] at index  " << i <<": " <<  ptr[i] << endl;//for testing
      }

      numbers_inSet=right.numbers_inSet;
   }

   return *this;
}

IntegerSet::~IntegerSet()
{
   delete [] ptr;
}
/*Description: This function will return the size of 
 * 	       the elements in the array
 */
int IntegerSet::size()
{
  return numbers_inSet;
}
/*Description: This function will return a boolean value corresponding 
 *             to whether or not the array is empty
 */
bool IntegerSet::isEmpty()
{
   if( numbers_inSet == 0)
   {
      return true;
   }else{
      return false;
   }
}
/*Description: This function will return a boolean value 
 * 	       that says wheter or not the array constains a 
 * 	       certain number
 */
bool IntegerSet::contains(int value)
{
   for(int i=0; i < numbers_inSet; i++)
   {
      if(value == ptr[i])
      {
	 return true;
      }
   }

   return false;
}

/*Description: This function will add another element into the array.
 * 		It will first check if the value already exists inside the array
 * 		and if it doesn't exist, it will add it to it.
 */
void IntegerSet::add(int a)
{
   if( contains(a) == true)
   {
      cout<< a  <<" is already in the set."<< endl;
   }else if( numbers_inSet == array_size){
      int biggerArray_size = array_size*2;
      int * bigger_array = new int[biggerArray_size];
      for(int i=0;i<array_size;i++){
	 bigger_array[i] = ptr[i];
      }
      bigger_array[array_size] = a;// adds new element to array 
      delete [] ptr;
      ptr = bigger_array;//Redirect pointer
      array_size = biggerArray_size;//This is where array size is upadted 
      numbers_inSet++;//This is where the numbers in the set get increased(after adding the new element)
   }else{
      ptr[numbers_inSet] = a;
      numbers_inSet++;//This is where the numbers in the set get increased(after adding the new element)
   }
}

/*Description: This function will remove an element from the array. 
 * 		This is if the element exist inside element, otherwise it will 
 * 		tell the user that the value is not inthe set
 */
void IntegerSet::remove(int r)
{
   if(contains(r) == false)
   {
      cout << "The number is not in the set." << endl;
   }else{
      int r_index;
      for(int i =0;i< numbers_inSet;i++){
	 if(r == ptr[i])
	 {
	    r_index = i;
	    break;
	 }
      }
      if(r_index==(numbers_inSet-1)){//This means if it is at the end
      numbers_inSet--;//This is where the numbers in set get updated
      }else{
	 for(int c = r_index; c < numbers_inSet-1; c ++)
	 {
	    ptr[c]=ptr[c+1];
	 }
	 numbers_inSet--;//This is where the numbers in set get updated
      }
   }
}
/*Description: This functino will print the values of the object */
void IntegerSet::print()
{
   for(int i=0; i<numbers_inSet;i++)
   {
      cout << ptr[i]<< ",";
   }

}

/*Description: This function will return the vector equivalent of the array*/
vector<int> IntegerSet::getAsVector()
{
   vector<int> intSet(ptr, ptr + numbers_inSet);
/*
   //for testing
   for(int i =0; i < intSet.size();i++)
   {
      cout << intSet.at(i) << " " << endl;
   }*/

   return intSet;

}

/*Description: This function is overloading the "+" operator. 
 * 		It will be the mathematical equivalent of the union 
 * 		of two sets
 */
IntegerSet  IntegerSet::operator+(IntegerSet set2)
{
   IntegerSet intSet_union = *this;
   //intSet_union.print();// for testing  
   for(int i = 0; i < set2.numbers_inSet; i++)
   {
      //cout << i << endl;// for testing
      intSet_union.add(set2.ptr[i]);
   }

   return intSet_union;
}
/*Description: This function is overloading the "*" operator
 * 		This is the mathematical equivalent of the intersection of 
 * 		two sets
 */
IntegerSet IntegerSet::operator*(IntegerSet set2)
{
   IntegerSet intSet_intersect;
   for(int j =0; j< this->numbers_inSet; j++)
   {
      for(int k =0; k< set2.numbers_inSet; k++)
      {
	 if(ptr[j] == set2.ptr[k])
	 {
	    intSet_intersect.add(ptr[j]);
	 }
      }
   }

   return intSet_intersect;
}
/*Description: This function is overloading the "/" operator
 * 		This is the mathematical equivalent of the symmetric 
 * 		difference of two sets.
 *
 */
IntegerSet IntegerSet::operator/(IntegerSet set2)
{
   IntegerSet sym_diffSet;

   //The folowing two for loops will check the first 
   //set and add any elements that are part of the symmetric
   //different set to the set
   for(int i = 0; i< this->numbers_inSet; i++)
   {
      bool inOtherSet = false;
      for (int k =0; k < set2.numbers_inSet; k++)
      {
	 if(ptr[i] == set2.ptr[k])
	 {
	    inOtherSet = true;
	    break;
	 }
      }

      if(inOtherSet == false)
      {
	 sym_diffSet.add(ptr[i]);
      }

   }

   //The folowing two for loops will check the second
   //set and add any elements that are part of the symmetric
   //different set to the set

   for(int i = 0; i< set2.numbers_inSet; i++)
   {
      bool inOtherSet = false;
      for (int k =0; k < this->numbers_inSet; k++)
      {
	 if(set2.ptr[i] == this->ptr[k])
	 {
	    inOtherSet = true;
	    break;
	 }
      }

      if(inOtherSet == false)
      {
	 sym_diffSet.add(set2.ptr[i]);
      }

   }

   return sym_diffSet;

}

/*
IntegerSet IntegerSet::operator/(IntegerSet set2)
{
   IntegerSet union_set = *this*set2;
   union_set.print();

   IntegerSet diff_set;

   for(int q =0; q < this->numbers_inSet ;q++)
   {
      bool inUnion = false;
      for(int u = 0; u < union_set.numbers_inSet ;u++)
      {
	 if(ptr[q] == union_set.ptr[u])
	 {
	    inUnion = true;
	 }
      }
     if( inUnion == false)
     {
       	diff_set.add(ptr[q]);
     }
   }


   for(int q =0; q < set2.numbers_inSet ;q++)
   {
      bool inUnion = false;
      for(int u = 0; u < union_set.numbers_inSet ;u++)
      {
	 if(set2.ptr[q] == union_set.ptr[u])
	 {
	    inUnion = true;
	 }
      }
     if( inUnion == false)
     {
       	diff_set.add(set2.ptr[q]);
     }
   }

   return diff_set;

}*/
