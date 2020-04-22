//Jose Manuel Lopez Alcala
//Lab10

#include "StringList.hpp"
//#include <string> 
#include <iostream> 
using namespace std;
StringList::~StringList()
{
   ListNode * nodePtr = head;
   while(nodePtr != NULL)
   {
      ListNode *garbage = nodePtr;
      nodePtr = nodePtr->next;
      delete garbage;
   }
}

void StringList::add(std::string s)
{
   if(head == NULL)
   {
      head = new ListNode(s);
   }else{
      ListNode *nodePtr= head;
      while(nodePtr->next != NULL)
      {
	 nodePtr = nodePtr->next;
      }

      nodePtr->next = new ListNode(s);
   }
}

int StringList::positionOf(std::string s)
{
   int index=0;
   ListNode *nodePtr = head;

   while(nodePtr)
   {
      if(nodePtr->value == s)
      {
	 return index;
      }

      index++;
      nodePtr = nodePtr->next;
   }

   return -1;
}

int StringList::size()
{
   int size=0;
   ListNode *nodePtr = head;
   
   while(nodePtr)
   {
      size++;
      nodePtr = nodePtr->next;
   }

   return size;
}


StringList::StringList( StringList& obj)
{
   head = NULL;

      ListNode *nodePtr = obj.head;//this is the head of the obj being copied
   for(int i =0; i< obj.size(); i++)
   {

      if(head == NULL)
      {
	 head = new ListNode(nodePtr->value);
      }else{

	 ListNode *nodePtr2 = head;//This is hte head of this object
//	 std::cout << "address: " << &nodePtr2 <<  std::endl;//
	 while(nodePtr2->next != NULL)
	 {

//	 std::cout << "address: " << &nodePtr2 <<  std::endl;//
	    nodePtr2 = nodePtr2->next;
	 }

	 nodePtr2->next = new ListNode(nodePtr->value);
      }
      
	// std::cout << "address: " << &nodePtr <<  std::endl;
      nodePtr = nodePtr->next;
	 //std::cout << "address: " << &nodePtr <<  std::endl;
   }
}

void StringList::displayList()
{
   ListNode *nodePtr = head;
   while(nodePtr)
   {
      cout << nodePtr->value << endl;
      nodePtr = nodePtr->next;
   }
}
