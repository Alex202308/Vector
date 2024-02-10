#include <iostream>
#include "vector.h"

int main ()
{
    // Example usage
    DynamicArray myArray(3);
    myArray.push_back(1);
    myArray.push_back(2);
    myArray.push_back(3);

    std::cout << "Size: " << myArray.getSize() << ", Capacity: " << myArray.getCapacity() << std::endl;

    myArray.push_back(4);

    myArray.insert(3, 10);

    std::cout << "Size: " << myArray.getSize() << ", Capacity: " << myArray.getCapacity() << std::endl;
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;



    std::cout << "Original Array: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    // Using copy constructor
    DynamicArray newArray = myArray;

    std::cout << "Copied Array: ";
    for (int i = 0; i < newArray.getSize(); ++i) {
        std::cout << newArray.at(i) << " ";
    }
    std::cout << std::endl;

    // Using assignment operator
    DynamicArray anotherArray;
    anotherArray = myArray;

    std::cout << "Assigned Array: ";
    for (int i = 0; i < anotherArray.getSize(); ++i) {
        std::cout << anotherArray.at(i) << " ";
    }



    std::cout << std::endl;
    myArray.pop_back();

    std::cout << "Size: " << myArray.getSize() << ", Capacity: " << myArray.getCapacity() << std::endl;
    std::cout << myArray.at(2) << std::endl;
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << myArray.empty() << std::endl;
    myArray.clear();
    myArray.push_back(3);
    myArray.push_back(1);
    myArray.push_back(4);
    myArray.push_back(1);
    myArray.push_back(5);

    std::cout << "Original Array: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    myArray.shrinkToFit();
    std::cout << "Array after shrinkToFit: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    std::cout << "Front element: " << myArray.front() << std::endl;
    std::cout << "Back element: " << myArray.back() << std::endl;

    int searchValue = 1;
    int foundIndex = myArray.find(searchValue);
    if (foundIndex != -1) {
        std::cout << "Value " << searchValue << " found at index " << foundIndex << std::endl;
    } else {
        std::cout << "Value " << searchValue << " not found in the array\n";
    }

    myArray.unique();
    std::cout << "Array after unique: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    myArray.reverse();
    std::cout << "Array after reverse: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

    myArray.sort();
    std::cout << "Array after sort: ";
    for (int i = 0; i < myArray.getSize(); ++i) {
        std::cout << myArray.at(i) << " ";
    }
    std::cout << std::endl;

   
    return 0;

}
