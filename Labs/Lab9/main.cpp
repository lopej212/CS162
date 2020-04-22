 // Jose Manuel Lopez Alcala
// Lab 9 
// 11/21/17


#include <iostream> 
#include <stack>
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h>
using namespace std;
double postfixEval(char *postFix);


int main()
{

//   char postFix[] = "4 5 6 * +";// output: 30
   char postFix[] = "25 12 7 - 2 * /";//output: 2.5
   cout<< postFix << " = ";
   cout <<  postfixEval( postFix) << endl;
   




   return 0;

}


double postfixEval(char *postFix)
{

   stack<double> numbers;
   char *p;
   p = strtok(postFix," ");

   while(p != NULL)
   {
     // cout << endl;
     //cout << *p;

      if(isdigit(*p))
      {
	 //cout << "Here" << endl;
	 double n = atof(p);
	 //cout << endl;
	 //cout << "n: " << n << endl;
	 numbers.push(n);
	 //cout <<"Top stack: " << endl; 
	 //cout << numbers.top();
         
	 
	 p = strtok(NULL, " ");
      }else{
	 double op1;
	 double op2; 

	 //cout << "Here" << endl;
	 if((*p) == '+')
	 {
	    //cout << "Here" << endl;
	  
	    op2 = numbers.top();
	    //cout << op2 << endl;
	    numbers.pop();
	    op1 = numbers.top();
	    //cout << op1 << endl;
	    numbers.pop();

	    numbers.push(op1+op2);

	    //cout << numbers.top() << endl;
	 }else if((*p) == '*')
	 {
	    //cout << "Here" << endl;
	  
	    op2 = numbers.top();
	    //cout << op2 << endl;
	    numbers.pop();
	    op1 = numbers.top();
	    //cout << op1 << endl;
	    numbers.pop();

	    numbers.push(op1*op2);

	    //cout << numbers.top() << endl;
	 }else if((*p) == '/')
	 {
	    //cout << "Here" << endl;
	  
	    op2 = numbers.top();
	    //cout << op2 << endl;
	    numbers.pop();
	    op1 = numbers.top();
	    //cout << op1 << endl;
	    numbers.pop();

	    numbers.push(op1/op2);

	    //cout << numbers.top() << endl;
	 }else if((*p) == '-')
	 {
	    //cout << "Here" << endl;
	  
	    op2 = numbers.top();
	    //cout << op2 << endl;
	    numbers.pop();
	    op1 = numbers.top();
	    //cout << op1 << endl;
	    numbers.pop();

	    numbers.push(op1-op2);

	    //cout << numbers.top() << endl;
	 }  



      p = strtok(NULL, " ");

      }



   }

   return numbers.top();
}


