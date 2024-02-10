#ifndef STACK_H
#define STACK_H
#include "../../Vector/vector.h"
class MyStack {
	private:
		DynamicArray stack;
		
	public:
		//Default Constructor
		MyStack ();

		//Parameterized Constructor
		MyStack (const DynamicArray& other);
		
		//Copy Constructor
		MyStack (const MyStack& other);
		
		//Returns the last element of the stack
		int top();
		
		//Frees the stack by one element
		void pop();
		
		//Аdds one element from the end of the stack
		void push(int elem);
		
		//Gets stack size
		int getSize();
		
		//Returns one if the stack is empty and if not then zero
		bool empty();

};
#endif
