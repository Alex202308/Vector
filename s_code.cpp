#include "stack.h"

// Default Constructer
MyStack::MyStack () {}

// Parameterized constructor
MyStack::MyStack (const DynamicArray& other) : stack(other){}

// Copy constructor
MyStack::MyStack (const MyStack& other) : stack(other.stack){}

int MyStack::top()
{	
	if(stack.getSize() == 0)
	{
		std::cout << "Stack is empty. " << std::endl;
		return 0;
	}
	else{
		return stack.back();
	}
}

void MyStack::pop()
{
	stack.pop_back();
}

void MyStack::push(int elem){
	stack.push_back(elem);
}

int MyStack::getSize()
{
	return stack.getSize();
}

bool MyStack::empty(){
	return stack.empty();
}
