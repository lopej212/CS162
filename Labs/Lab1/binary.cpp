// This program performs a binary search on an integer
// array whose elements are in ascending order.
#include <iostream>
using namespace std;

//Function prototype
int binarySearch(const int [], int , int);

const int SIZE = 20; 

int main()
{
   //Create an array of ID nubmers sorted in ascendin order
   int IDnums[SIZE] = {101, 142, 147, 189, 199, 207, 222, 234,289,296,			    310,319,388,394,417,429,447,521,536,600};

   int empID, 		// Holds the ID to search for 
       result;		// Holds the search results
   
   // Get an employee ID to search for
   cout << "Enter the employee ID you wish to search for: ";
   cin >> empID;

   // Serach for ID
   result = binarySearch(IDnums, SIZE, empID);

   // If binarySearch returned -1, the ID was not found
   if (result == -1)
      cout << "That number does not exist in the array.\n";
   else
   {
      //otherwise results contains the subscript of 
      //the specified employee ID in the array
      cout << "ID" << empID << " was found in the element "
	   << result << " of the array.\n";
   }
   return 0;
}


   /***************************************************************
    * 				BinarySearch
    * This function performs a binary search on an integer array 
    * with size elements whose values are stored in ascending
    * order. The array is searched for the nubmer stored in the a
    * value parameter. If the nubmer is found, its array subscript
    * is returned, Otherwise, -1 is returned. 
    * ************************************************************/
   int binarySearch(const int array[], int size, int value)
   {
      int first = 0, 		//First array element
	  last = size-1, 	//Last array element
	  middle, 		//mdpoint of search
	  position = -1; 	// Position of search value
      bool  found = false; 	// Flag

      while(!found && first <= last)
      {
	 middle = (first + last) / 2;
	 if (array[middle] == value)
	 {
	    found = true;
	    position = middle;
	 }
	 else if(array[middle] > value)
	    last = middle-1;
	 else
	    first = middle +1;
      }
      return position; 
   }

