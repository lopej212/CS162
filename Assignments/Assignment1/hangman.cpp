/************************************************
 * Author: Manuel Lopez Alcala
 * Date: September 27, 2017 (Week 1, Fall 2017) 
 * Description: Hangman! This program simulates a hangman game 
 * 		where the user is given a random word to guess
 * 		and ther are given unlimited tries to guesses
 * 		to figure out the word.
 * *********************************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

string word();
void hyphenator( char array[], int array_length);
void print_guessList(string guessList);
void print_hyphenated(char array[], int array_length);
bool word_guessed(char array[], int array_length);
void compare_change( string word,int word_length, string guess, char array[]);
bool letter_found(string letter, string word_list);

int main (){

   string word_game = word();
   int word_length = word_game.length();
   char array_hyphen[word_length];
   string user_input;
   bool guessed = false;
   string guess_list;
   int guesses = 0;



   cout << "Welcome to hangman!" << endl;
   cout << "Your secret word is: ";
   hyphenator(array_hyphen, word_length);
 //  cout << "\nWord is: " <<  word_game << endl;// for testing

   while(guessed == false){// Loops until word is completeley guessed
   
   cout << "\nPlease enter a letter: " << endl;
   cin >> user_input;
   if(letter_found(user_input,guess_list) == false){ 
      guesses++; 
      guess_list += user_input; 
      cout << "\nYour secret word is:";
      compare_change(word_game, word_length,user_input,array_hyphen);//guess and word comparison 
      print_hyphenated(array_hyphen, word_length);//print hyphenated word
      cout << "\nLetters chosen so far: ";
      print_guessList(guess_list);
      guessed = word_guessed(array_hyphen, word_length);

      //cout << "This is what is in user_input: " << user_input << endl;//for testing
   }else{
     cout << "You already guessed that letter!Guess somehting different." << endl; 
      }
   }

   cout << "\n\nYou guessed the word! It took you " << guesses << " guesses." << endl;
   
   return 0;

}
/*********************************************************
 * Function: letter_found()
 * Description: This funciton will return a boolean 
 * 		after checking if the the letter from user input
 * 		was in the list of letters 
 * Parameters:letter from user, list of letters already guessed
 * ******************************************************/
bool letter_found(string letter, string word_list){
   for(int i =0; i<word_list.length();i++){//loop for word's letters iteration
      if(word_list.at(i) == letter.at(0)){
	 return true;
      }
   }
   return false;
}


/*********************************************************
 * Function: print_guessList() 
 * Description: This function will print the list of letters
 * 		that the user has already guesed 
 * Parameters: String where the guesses are located 
 * ******************************************************/
void print_guessList(string guessList){
   for(int i =0; i < guessList.length();i++){//loop for interation of elements in string
      cout << guessList.at(i) << " " ;
   }
}

/*********************************************************
 * Function: print_hypenated() 
 * Description: This funtion will print the hypenated word
 * 		to show the user how long the word is and 
 * 		so that they can start guessing 
 * Parameters: Array where the hyphenated word is located, 
 * 	       Length of hte hyphneated word.
 * ******************************************************/
void print_hyphenated(char array[], int array_length){
   for( int i =0; i < array_length;i++){//loop for iteration of elements in array
      cout << array[i];
   }
}

/*********************************************************
 * Function: word_guessed() 
 * Description: This funtion will return a boolean value 
 * 		This will let the user know whether or not
 * 		the word has been guessed completly. 
 * Parameters: The array where the hyphenated word is located,
 * 	       The length of the array of the hyphenated word. 
 * ******************************************************/
bool word_guessed(char array[], int array_length){

   bool guessed = true;// returning value storage

   for( int i=0; i < array_length;i++){
      if(array[i] == '_'){
	 guessed = false;
      }
   }
   return guessed;
}

/*********************************************************
 * Function: compare_change() 
 * Description:This function will compare the guess from the user
 * 	       with the word being guessed. If there is a match 
 * 	       then the letter in the hyphenated array will be changed
 * 	       from a hyphen to the corresponding letter.  
 * Parameters: Word being guessed, word length, guess from user, hyphenated array 
 * ******************************************************/
void compare_change( string word,int word_length, string guess, char array[]){

   for(int y =0; y< word_length; y++){
      if(word.at(y) == guess.at(0)){//if letter is in the word
	 array[y] = guess.at(0);//swap the elements
      }
   }
}



/*********************************************************
 * Function: word() 
 * Description: This function will return an string (word ) 
 * 		that the user will be guessing. 
 * Parameters: NONE 
 * ******************************************************/
string word(){
   string array1[] = {"awkward","bagpipes","banjo","fishhook","gypsy","haiku","ivory","jukebox","kayak","oxygen"};

   srand(time(NULL));

   return array1[rand() % 10];//return random word from array
}

/*********************************************************
 * Function: hyphenator() 
 * Description: This function will fill in the array where
 * 		the correct letter will be located. It will
 * 		first be filled with "_" and printed to the 
 * 		console 
 * Parameters: array where hypenated word is locatd, length of word 
 * ******************************************************/
void hyphenator( char array[], int array_length){

   for(int i = 0; i < array_length; i++){
      array[i] = '_';//fill array with hyphens
   }

   for(int x =0; x < array_length; x++){
      cout << array[x];//print out the array
   }
}





