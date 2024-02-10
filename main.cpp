#include <iostream>
#include "stack.h"

int main() {
	MyStack obj;
	obj.push(20);
	std::cout << "The last elemenet is " << obj.top() << std::endl;
	obj.push(30);
	obj.push(31);
	std::cout << "The last elemenet is " << obj.top() << std::endl;
	obj.pop();
	std::cout << "The last elemenet is " << obj.top() << std::endl;
	obj.pop();
	std::cout << "The last elemenet is " << obj.top() << std::endl;
	obj.pop();
	std::cout << "The last elemenet is " << obj.top() << std::endl;
	obj.pop();
	
	

}
