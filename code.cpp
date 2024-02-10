#include "vector.h"

// Default constructer
DynamicArray::DynamicArray() : arr(nullptr), size(0), capacity(0) {}

// Parameterized constructor
DynamicArray::DynamicArray(int initialSize) : size(0), capacity(initialSize) {
    	arr = new int[capacity];
}

// Copy constructor
DynamicArray::DynamicArray(const DynamicArray& other) : size(other.size), capacity(other.capacity){
	arr = new int[capacity];
        for (int i = 0; i < size; ++i) {
            arr[i] = other.arr[i];
        }
}

// Overload the assignment operator
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
	if (this != &other) { // self-assignment check
            // Deallocate existing memory
            delete[] arr;

            // Copy values from the other object
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            
            for (int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];
            }
        }

        return *this;
}

// Destructor
DynamicArray::~DynamicArray() {
	delete[] arr;
}

// Return the current number of elements in the array
int DynamicArray::getSize() const {
	return size;
}

// Return the current capacity of the array
int DynamicArray::getCapacity() const {
	return capacity;
}

// Return true if the array is empty, false otherwise
bool DynamicArray::empty() const {
	return size == 0;
}

// Return the element at the specified index
int DynamicArray::at(int index) const {
	if (index >= 0 && index < size) {
		return arr[index];
   	 } else {
        	// Handle index out of bounds
        	std::cerr << "Index out of bounds\n";
        	return -1; // You might want to throw an exception here instead
   	 }
}

// Add an element to the end of the array. Resize if necessary.
void DynamicArray::push_back(int value) {
    	if (size == capacity) {
        	// Resize the array
        	int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        	int* newArr = new int[newCapacity];

        	// Copy existing elements to the new array
        	for (int i = 0; i < size; ++i) {
            	newArr[i] = arr[i];
        	}

        	// Delete the old array and update pointers
        	delete[] arr;
        	arr = newArr;
        	capacity = newCapacity;
    	}

    	// Add the new element and update size
    	arr[size] = value;
    	size++;
}

// Remove the last element from the array
void DynamicArray::pop_back() {
	if (size > 0) {
		--size;

	} else {
        	// Handle underflow (trying to pop from an empty array)
        	std::cerr << "Cannot pop from an empty array\n";
	}
}

// Clear all elements from the array and release memory
void DynamicArray::clear() {
    	delete[] arr;
    	arr = nullptr;
    	size = 0;
    	capacity = 0;
}

// Insert a new element at the specified index
void DynamicArray::insert(int index, int value) {

	if (index < 0 || index > size) {
		// Handle invalid index
	       	std::cerr << "Invalid index for insertion\n";
	        return;
	}

	if (size == capacity) {

		// Resize the array
		int newCapacity = (capacity == 0) ? 1 : capacity * 2;
		int* newArr = new int[newCapacity];

		// Copy elements before the insertion point
		for (int i = 0; i < index; ++i) {
			newArr[i] = arr[i];
		}

		// Insert the new element
		newArr[index] = value;

		// Copy elements after the insertion point
		for (int i = index; i < size; ++i) {
			newArr[i + 1] = arr[i];
		}

		// Delete the old array and update pointers
		delete[] arr;
		arr = newArr;
		capacity = newCapacity;
	        ++size;
	} 
	else {
		// Shift existing elements to make space for the new element
	        for (int i = size; i > index; --i) {
	            arr[i] = arr[i - 1];
	       	}

	       	// Insert the new element
	       	arr[index] = value;
	       	++size;
	}

}

// Return a pointer to the raw array data
int* DynamicArray::data() const {
        return arr;
}

// Reduces the capacity of the vector to fit its size
void DynamicArray::shrinkToFit() {
	if (size < capacity) {
            int* newArr = new int[size];
            for (int i = 0; i < size; ++i) {
                newArr[i] = arr[i];
            }
            delete[] arr;
            arr = newArr;
            capacity = size;
        }
}

// Accesses the first element
int& DynamicArray::front() {
        if (size > 0) {
            return arr[0];
        } else {
            // Handle empty array (you might want to throw an exception here)
            std::cerr << "Array is empty\n";
            // Returning a reference here is not ideal; you might want to return a sentinel value or throw an exception.
            return arr[0];
	}
}

// Accesses the last element
int& DynamicArray::back() {
        if (size > 0) {
            return arr[size - 1];
        } else {
            // Handle empty array (you might want to throw an exception here)
            std::cerr << "Array is empty\n";
            // Returning a reference here is not ideal; you might want to return a sentinel value or throw an exception.
            return arr[0];
        }
}

// Searches for the first occurrence of a specified value in the vector.
// Returns -1 if the value is not present.
int DynamicArray::find(int value) {
	for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                return i;
            }
        }
        return -1; // Value not found
}

// Helper function for sorting (using bubble sort)
void DynamicArray::bubbleSort() {
        for (int i = 0; i < size - 1; ++i) {
            for (int j = 0; j < size - i - 1; ++j) {
                if (arr[j] > arr[j + 1]) {
                    // Swap elements if they are in the wrong order
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
}

// Reverse the order of elements in the vector
void DynamicArray::reverse() {
        int start = 0;
        int end = size - 1;

        while (start < end) {
            // Swap elements at start and end indices without using std::swap
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            // Move indices toward the center
            ++start;
            --end;
        }
}

// Sort the elements in the vector
void DynamicArray::sort() {
        // Using bubble sort instead of std::sort
        bubbleSort();
}

void DynamicArray::unique() {
    	if (size <= 1) {
        	return; // No duplicates to remove
    	}

    	// Use bubble sort to bring duplicate elements together
    	bubbleSort();

    	int newIndex = 1; // Index for the modified array
    	for (int i = 1; i < size; ++i) {
        	if (arr[i] != arr[i - 1]) {
            		// The current element is different from the previous one, so it's considered unique
            		arr[newIndex++] = arr[i];
        	}
    	}	

    	// Update the size
    	size = newIndex;
}
