#include <iostream> 
#include "zombie.hpp"
#include <vector> 

using namespace std;

int main()
{
   vector<Zombie*> zombies;
   
   bool quit = false;

   int option;
   do{
      cout << "1) Create a new Zombie." << endl;
      cout << "2) Destroy a zombie. "<< endl;
      cout << "3) Print number of zombies." << endl;
      cout << "4) Tell all existing zombies to speak" << endl;
      cout << "5) Quit" << endl;
      cout << "Enter the option number to proceed: " << endl;
   
      cin >> option;

      if(option == 1)
      {
	 string name;
	 cout << "Enter zombie name: " << endl;
	 cin >> name;
	 Zombie *zombiePtr = new Zombie(name);
	 zombies.push_back(zombiePtr);
	 cout << "New zombie was created."  << endl;
      }
      if(option == 2)
      {
	 if(!zombies.empty()){
	 	delete zombies.at(zombies.size()-1);
	 	zombies.pop_back();
		cout << "The last zombie in the vector was destroyed." << endl;
	 }else{
	    cout << "You have no zombies left to delete." << endl;
	 }
      }
      if(option == 3)
      {
	 cout << "You have " << zombies.size() << " zombies." << endl;
      }
      if(option ==4 )
      {
	 for(int i =0; i<zombies.size(); i++)
	 {
	    zombies.at(i)->speakZ();
	 }
      }
      if(option == 5)
      {
	 quit = true;
      }
   }while(quit == false);




   return 0;
}

