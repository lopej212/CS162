// CS162 Lab1 
// Manuel Lopez

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
using namespace std;

void sortArray(int array[], int size);
void binarySearch(const int array[], int size, int target);
void linearSearch(const int arra[], int size, int target);
int main()
{
   int array1[1000] = {};
   int array2[10000] = {};
   int array3[100000] = {};
   int array4[1000000] = {};

  srand (time(NULL));


  for( int x = 0; x < 1000; x++){
     array1[x] = rand() % 1000000 + 1;
     //cout << array1[x] << endl; // for testing 
  }
  for (int i = 0; i < 10000; i++){
     array2[i] = rand() % 1000000 + 1;
  }
  for(int y = 0; y < 100000; y ++){
     array3[y] = rand() % 1000000 + 1;
  }
  for(int z = 0; z < 1000000; z++){
     array4[z] = rand() % 1000000 + 1;
  }


  sortArray(array1, 1000);
  sortArray(array2, 10000);
  sortArray(array3, 100000);
  sortArray(array4, 1000000);


  int target_value1 = rand() % 1000000 + 1;
  int target_value2 = rand() % 1000000 + 1;
  int target_value3 = rand() % 1000000 + 1;
  int target_value4 = rand() % 1000000 + 1;
  
  cout <<"*****Array1*****" << endl;
  linearSearch(array1,1000,target_value1);
  binarySearch(array1,1000,target_value1);

  cout <<"*****Array2*****" << endl;
  linearSearch(array2,10000,target_value2);
  binarySearch(array2,10000,target_value2);


  cout <<"*****Array3*****" << endl;
  linearSearch(array3,100000,target_value3);
  binarySearch(array3,100000,target_value3);

  cout <<"*****Array4*****" << endl;
  linearSearch(array4,1000000,target_value4);
  binarySearch(array4,1000000,target_value4);

}


void sortArray(int array[], int size){
   sort(array,array+size);
   /*
   for(int i = 0; i < size; i++){
      cout << array[i] << endl;
   }*/
}

void linearSearch(const int array[], int size, int target){
   int index = 0;
   bool found = false;
   int comparison = 0;
   
   cout << "Linear Search " << endl;
   cout << target << " is the target value. " << endl;

   while(index < size && !found)
   {
      comparison++;
      if(array[index] == target)
      {
	 found = true;
	 cout << "Number of comparisons: " << comparison << endl;
      }
      index++;
   }
   if( found == false)
      cout << target << " was never found" <<endl;
}

void binarySearch(const int array[], int size, int target)
{
   int first = 0,
       last = size-1,
       middle;
   bool found = false;
   int comparison = 0;
   
   cout << "Binary Search" << endl;
   cout << target << " is the target value. " << endl;

   while(!found && first <= last)
   {
      comparison++;
      middle = (first + last)/2;
      if(array[middle] == target)
      {
	 found = true;
	 cout << "Number was found after " << comparison << " comparisons." << endl;
      }
      else if (array[middle] > target)
	    last = middle - 1;
      else first = middle +1;
   }

   if(found == false)
      cout << target << " was never found." << endl;
}

      
