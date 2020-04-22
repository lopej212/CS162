/***************************************************
 * Author: Manuel Lopez Alcala
 * Date: Week 2 Fall 2017
 * Description: Custom sort function for sorting array 
 * 		with strings inside
 **************************************************/

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale>
#include <ctype.h>
using namespace std;

void wordstoLower(const string array1[], string array2[], int array_size);
void stringSort(string array[], int array_size);
void randomIndex(int array[], int array_size);
int main(){
   
   string words[] = {"Portrait", "charismatic","Guard","daring","Doomsday",
      	   	    "container","Disfigured","monkey","essence","diametric",
		    "Axis","Choker","consultant","Lasso","painkiller","reckless",
		    "massive","primate","scar","Blue"};

   string unsorted[10];//initially unassorted array 
   int indexes[10];//array for randome indexes
   randomIndex(indexes,10); 
   
   // This for loop will fill the unsorted array with
   // the random words from the word bank 
   for(int i =0; i<10; i++){
      int randomIndex = indexes[i];
      unsorted[i] = words[randomIndex]; 
   }

   cout << "Unassorted list of words:"<< endl;
   for(int n=0; n<10;n++){
      cout <<unsorted[n] << endl;
   }

   stringSort(unsorted,10);//sorting function call
   
   cout << "\nAssorted list of words:" << endl;
   for(int q=0; q<10;q++){
      cout << unsorted[q] << endl;
   }

return 0;
}
/*********************************************
 * Function: stringSort()
 * Description: This is the actual fucntion that is 
 * 		doing the sorting
 * Parameters: array that is being sorted,
 * 	       size of the array that is being sorted 
 *******************************************/
void stringSort(string array[], int array_size){
   string allLower[array_size];//array for lowercase words
   wordstoLower(array,allLower,array_size);//converts words to lowercase


   int startScan, minIndex; 
   string min1Value;
   string min2Value;
   
   //Selection sorth alogorith   
   for(startScan =0; startScan < (array_size - 1); startScan++)
   {
      minIndex = startScan;
      min1Value = allLower[startScan];
      min2Value = array[startScan];// second min value to map words from array lowercase to original
      

      for(int index = startScan + 1; index < array_size; index++)
      {
	 if(allLower[index] < min1Value)//comparison between lowercase version 
	 {
	    min1Value = allLower[index];
	    min2Value = array[index];//mapping second min value to index of comparison array
	    minIndex = index;
	 }
      }
	 allLower[minIndex] = allLower[startScan];
	 array[minIndex]=array[startScan];// moving element in orginal array 
	 allLower[startScan] = min1Value;
	 array[startScan]= min2Value;// moving elemetn in orginal array
   }

   /*
   //for testing 
   for(int q=0; q<10;q++){
      cout << allLower[q] << " " << endl;
   }*/
}


/*********************************************
 * Function: wordstoLower()
 * Description: This function will take in a array of strings
 * 		and a blank array of the same size  and
 * 		populate the second array with the lowercase equivalent
 * 		of the words in the first array.   
 * Parameters: string array1(original array)
 * 	       string array2(empty array)
 * 	       size of the arrays( they should both be the same
 *******************************************/
void wordstoLower(const string array1[], string array2[], int array_size){

   locale loc;
   string str = "";
   string word;
   char l;
   for(int i =0; i < array_size;i++){ // outer loop for words
      word = array1[i];//accesing word at index i
      for(int x =0; x < array1[i].length(); x++){ // inner loop for letters in words
	 l = word.at(x);//accesing letter from current word at index x
	 if(islower(l,loc)){// if letter is lower add to str
	    str.push_back(l);
	}else{
	   l = tolower(l);// if letter is not lowercase, convert and add to str
	   str.push_back(l);
	}
      }
      array2[i] = str;//assign lowercase word in second array at index i
      str.clear();
   }
}

/*********************************************
 * Function:randomIndex()
 * Description: Populates an array of size array_size
 * 		with non repeated nubmers
 * Parameters: int array, array to be filled 
 * 	       int array_size, integers that represents the seize of the array
 *******************************************/
void randomIndex(int array[], int array_size){
   srand(time(NULL));
   array[0] = rand() % 20;//assings first element to random number

   for(int i = 1; i < array_size; i ++){
      bool used;
      int numero;
      do{
	 numero = rand() % 20;
	 //Following for loop will go through every element in array to check
	 //if the number is already in there
	for(int x =0; x<i; x++){
	  if(array[x] == numero){
	    used = true;
	   break;
	  }else{
	     used = false;
	  }
	}
      }while(used == true);
    array[i] = numero;// assing number to element space at index i
   }
}  
