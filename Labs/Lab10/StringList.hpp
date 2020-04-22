//Jose Manuel Lopez Alcala
//Lab10

#ifndef STRING_LIST_HPP
#define STRING_LIST_HPP

#include <string> 
class StringList
{
   private:
      struct ListNode
      {
	 std::string value;
	 ListNode * next;
	 ListNode(std::string value1, ListNode* next1 = NULL)
	 {
	    value = value1;
	    next = next1;
	 }

      };

      ListNode * head;

   public: 
      StringList(){head = NULL;}
      ~StringList();
      void add(std::string);
      int positionOf(std::string);
      int size();
      StringList( StringList& obj);
      void displayList();
};

#endif
