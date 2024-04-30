/*
 * MyADT.cpp
 * 
 * Class Description: A linear data collection ADT.
 * 
 * Class Invariant: Data collection with the following characteristics:
 *                  - This is a value-oriented data collection and 
 *                    the elements are kept in ascending sort order of search key.
 *                  - Each element is unique (no duplicates). 
 *                  - Its data structure (CDT) is not expandable. This signifies that 
 *                    when this data collection becomes full, you do not have to resize 
 *                    its data structure (not in this Assignment 1). 
 *
 * Author: Izaz Zubayer (301386899)
 * Last modified: 1 Feb, 2024
 */


#include <iostream>
#include <cctype>
#include "MyADT.h"     // Header file of MyADT file
#include "Profile.h"   // Header file of Profile class

using std::cout;
using std::endl;



    
// Default constructor.
MyADT::MyADT() {
//    cout << "MyADT::default constructor executed!" << endl;   // For testing purposes ...
   // You can also use the above to figure out when this constructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

   // Initialize the element count of each array to 0
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        elements[i] = new Profile[MAX_ELEMENTS];
        elementCount[i] = 0;
    }
}


// // Copy constructor - Covered in Lab 3
// MyADT::MyADT(const MyADT& rhs) {

// //    cout << "MyADT::copy constructor executed!" << endl; // For testing purposes ... 
//    // You can also use the above to figure out when this constructor is executed.
//    // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.


// // Overloaded assignment operator - Covered in Lab 5
// // Therefore, we shall not be overloading this operator in our Assignment 1
// // MyADT & MyADT::operator=(const MyADT& rhs) {
//    // cout << "MyADT::operator= executed!" << endl; // For testing purposes ... 
//    // You can also use the above to figure out when this overloaded assignment = operator is executed.
//    // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.

// }

    
// Destructor
// Description: Destroys this object, releasing heap-allocated memory.
MyADT::~MyADT() {

   // cout << "MyADT::destructor" << endl;  // For testing purposes ...
   // You can also use the above to figure out when this destructor is executed.
   // If you do uncomment it, make sure to comment it out again before you submit your Assignment 1.
        // Looping through each array of elements and delete the elements

    //Delete all dynamically allocated memory
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        delete[] elements[i];
        elements[i] = nullptr;
    }
}  


// Description: Returns the total number of elements currently stored in the data collection MyADT.  
unsigned int MyADT::getElementCount() const {

    unsigned int totalCount = 0;

    // Looping through each array of elements and add up the element counts
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        totalCount += elementCount[i]; //update the total count
    }

    return totalCount;

}



// findIndex is helper function
int MyADT::findIndex(const char searchKey) const {
    // Looping through each array of elements and search for the target element
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        if (elements[i] != nullptr && elements[i][0].getSearchKey() == searchKey) {
            return i;  // Found the array with the corresponding search key
        }
    }
    return -1;  // Search key not found
}


// Description: Inserts an element in the data collection MyADT.
// Precondition: newElement must not already be in the data collection MyADT.  
// Postcondition: newElement inserted and the appropriate elementCount has been incremented.
//                Returns "true" when the insertion is successfull, otherwise "false".
bool MyADT::insert(const Profile& newElement) {

    //    cout << "If this the problem then say - ITS ME HI I AM THE PROBLEM ITS ME!!!!!" << endl;   // For testing purposes ...

    // Check if newElement is already in the data collection
    if (search(newElement) != nullptr) {
        // newElement is already in the data collection, insertion fails
        return false;
    }

    // Find the appropriate index for the array of elements
    int i = newElement.getSearchKey() - 'a';

    // Check if the array is full
    if (elementCount[i] == MAX_ELEMENTS) {
        // Array is full, insertion fails
        return false;
    }

    // Insert the new Profile object into the array at the appropriate position
    elements[i][elementCount[i]] = newElement;

    // Increment the element count for the corresponding array
    elementCount[i]++;

    // Insertion successful
    return true;
}


// Description: Removes an element from the data collection MyADT. 
// Postcondition: toBeRemoved (if found) is removed and the appropriate elementCount is decremented.
//                Returns "true" when the removal is successfull, otherwise "false".  

bool MyADT::remove(const Profile& toBeRemoved) {
    // Find the appropriate index for the array of elements
    int i = toBeRemoved.getSearchKey() - 'a';

    // Looping through each array of elements and search for the target element
    for (unsigned int j = 0; j < elementCount[i]; j++) {
        if (elements[i][j] == toBeRemoved) {
            // Shift the elements to the left
            for (unsigned int k = j; k < elementCount[i] - 1; k++) {
                elements[i][k] = elements[i][k + 1];
            }
            // Decrement the element count for the corresponding array
            elementCount[i]--;

            // Removal successful
            return true;
        }
    }
    // Removal fails
    return false;
}


  


// Description: Removes all elements from the data collection MyADT. 
// Postcondition: MyADT reverts back to its initialization state, i.e., 
//                the state it is in once it has been constructed (once
//                the default constructor has executed). 
void MyADT::removeAll() {
    // Loop through each array of elements and delete the arrays
    for (unsigned int i = 0; i < MAX_ALPHA; i++) {
        delete[] elements[i];
        elements[i] = nullptr;
        elementCount[i] = 0;
    }
}   
 

// Description: Searches for target element in the data collection MyADT. 
//              Returns a pointer to the element if found, otherwise, returns nullptr.
Profile* MyADT::search(const Profile& target) {
    // Find the appropriate index for the array of elements
    int i = target.getSearchKey() - 'a';

    // Looping through each array of elements and search for the target element
    for (unsigned int j = 0; j < elementCount[i]; j++) {
        if (elements[i][j].getSearchKey() == target.getSearchKey()) {
            // Target element found
            return &elements[i][j];
        }
    }
    // Target element not found
    return nullptr;
}



// Description: Prints all elements stored in the data collection MyADT in ascending order of search key.
// ***For Testing Purposes - Not part of this class' public interface.***
void MyADT::print() {

    // Looping through each array of elements and print the elements
    for (unsigned int i = 0; i < MAX_ALPHA; ++i) {
        for (unsigned int j = 0; j < elementCount[i]; ++j) {
            cout << elements[i][j] << endl;
        }
    }
}
//  End of implementation file
