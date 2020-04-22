/**************************************
 * Author: Jose Manuel Lopez Alcala
 * CS162
 * Assignment 5
 * File: Main.cpp
 * This is for testing purposes 
 **************************************/

#include "Library.hpp"
#include <iostream>
#include <vector> 
int main()
{

   std::cout << "Starting test sequence..." << std::endl;

   Library Library1;
   Book b1("b001", "Don Quixote", "Miguel de Cervantes");
   Movie m1("m001", "Titanic", "James Cameron"); 
   Album a1("a001", "AM", "Artic Monkeys");
   Library1.addLibraryItem(&b1);
   Library1.addLibraryItem(&m1); 
   Library1.addLibraryItem(&a1);
   Patron p1("p1010", "Pepe");
   Patron p2("v2020", "Victor");
   Patron p3("b3030", "Benji");
   std::cout << "Address of patron \"p1010\": " << &p1 << std::endl;
   std::cout << "Address of patron \"b3030\" : " << &p3 << std::endl;
   Library1.addPatron(&p1);
   Library1.addPatron(&p2);
   Library1.addPatron(&p3);
   Library1.incrementCurrentDate();
   std::cout << "ID of patron 1: " <<  p1.getIdNum()<< std::endl;
   std::cout << "Name of patron 2: " <<  p2.getName() << std::endl;
   std::cout << "Check out length of b1: " <<  b1.getCheckOutLength() << std::endl;
   std::cout << "ID of m1: " <<  m1.getIdCode() << std::endl;
   std::cout << "Title of a1: " << a1.getTitle() << std::endl;
   std::cout << "Adress of \"b3030\" : " << Library1.getPatron("b3030") << std::endl;
   std::cout << "Address of \"m001\" : " << Library1.getLibraryItem("m001") << std::endl;
   std::cout << "Fine for p3: " << p3.getFineAmount() << std::endl;
   std::cout << "Location of b1: " << b1.getLocation() << std::endl;
   std::cout << "Patorn \"b001\" is Looking for item \"s10101\"..." << Library1.checkOutLibraryItem("s1010", "p001") << std::endl;
   std::cout << "Patron \"p1010\" is Looking for item \"p001\" ..." << Library1.checkOutLibraryItem("p101", "b001") << std::endl;
   std::cout << "Patron \"p1010\" is wanting to check out item \"b001\"..." << Library1.checkOutLibraryItem("p1010", "b001") << std::endl;
   std::cout << "Got check out to: " << b1.getCheckedOutBy() << std::endl;
   std::cout << "Date checked out: " << b1.getDateCheckedOut() << std::endl;
   std::vector<LibraryItem*> test = p1.getCheckedOutItems();
   std::cout << "Size of the vector where checked out items are held: " << test.size() << std::endl; 
   std::cout << "Patron \"b3030\" is wanting to check out item \"b001\" ... " << Library1.checkOutLibraryItem("b3030", "b001") << std::endl;
   std::cout << "Patron \"b3030\" is wanting to request item \"s001\" ... " << Library1.requestLibraryItem("b3030", "s001") << std::endl;
   std::cout << "Trying to return item \"m001\" ... " << Library1.returnLibraryItem("m001") << std::endl;
   std::cout << "Patron \"b3030\" is wanting to request  item \"b001\" ... " << Library1.requestLibraryItem("b3030", "b001") << std::endl;
   std::cout << "Patron \"v2020\" is wanting to request item \"b001\" ... " << Library1.requestLibraryItem("v2020", "b001") << std::endl;
   std::cout << "b1 was requestd by: " << b1.getRequestedBy() << std::endl;
   for(int i=0; i<22; i++)
   {
      Library1.incrementCurrentDate();
   }
   std::cout << "22 days have passsed. " << std::endl;
   std::cout << "Pepe's fine is now: " << p1.getFineAmount() << std::endl;

   std::cout << "Item \"b001\" is trying to be returned... " << Library1.returnLibraryItem("b001") << std::endl;
   std::cout << "Patron \"Q1010\" is trying to pay $1.00 ... " << Library1.payFine("Q1010", 1.00) << std::endl;
   std::cout << "Patron \"p1010\" is tyring to pay $1.00 ... " << Library1.payFine("p1010", -1.00) << std::endl;
   std::cout << "Patron \"p1010\" new balance is: " << p1.getFineAmount() << std::endl;


   std::cout << "End of test. " << std::endl;
   return 0;
}

