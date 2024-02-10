#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class DynamicArray {
private:
    	int* arr;        // raw pointer to array
    	int size;        // count of current elements
    	int capacity;    // maximal count of elements

public:
    	// Default constructor
    	DynamicArray();

    	// Parameterized constructor
    	DynamicArray(int initialSize);

    	// Copy constructor
    	DynamicArray(const DynamicArray& other);

    	// Overload the assignment operator
    	DynamicArray& operator=(const DynamicArray& other);

    	// Destructor
    	~DynamicArray();

    	// Return the current number of elements in the array
    	int getSize() const;

    	// Return the current capacity of the array
    	int getCapacity() const;

    	// Return true if the array is empty, false otherwise
    	bool empty() const;

    	// Return the element at the specified index
    	int at(int index) const;

    	// Add an element to the end of the array. Resize if necessary.
    	void push_back(int value);

    	// Remove the last element from the array
    	void pop_back();

    	// Clear all elemets from the array and release memory
    	void clear();

    	// Insert a new element at the specified index
    	void insert(int index, int value);

    	// Return a pointer to the raw array data
    	int* data() const;

	// Reduces the capacity of the vector to fit its size
    	void shrinkToFit();

	// Accesses the first element
    	int& front();

	// Accesses the last element
 	int& back();
	
	// Searches for the first occurrence of a specified value in the vector.
    	// Returns -1 if the value is not present.
	int find(int value);

	// Helper function for sorting (using bubble sort)
	void bubbleSort();

	// Remove duplicate elements from the vector
    	void unique();

	// Reverse the order of elements in the vector
    	void reverse();

	// Sort the elements in the vector
    	void sort();
};
#endif
