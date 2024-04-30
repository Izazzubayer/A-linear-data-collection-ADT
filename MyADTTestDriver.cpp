/*
MyADTTestDriver.cpp
 * 
 * Class Description: For Testing Purpose
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
#include "MyADT.h"
#include "Profile.h"

using std::cout;
using std::endl;

int main() {
    // Test the MyADT class

    MyADT myADT;

    // Creating Profile objects for testing
    Profile profile1("user1", "User One", "user1@example.com", "01/01/1990");
    Profile profile2("user2", "User Two", "user2@example.com", "02/02/1991");
    Profile profile3("user3", "User Three", "user3@example.com", "03/03/1992");

    // Test1 insert
    if (myADT.insert(profile1)) {
        cout << "Profile1 inserted SUCCESSFULLY." << endl;
    } else {
        cout << "Profile1 insertion failed." << endl;
    }

    // Test2 search
    Profile* foundProfile = myADT.search(profile1);
    if (foundProfile != nullptr) {
        cout << "Profile1 found: " << *foundProfile << endl;
    } else {
        cout << "Profile1 not found." << endl;
    }

    // Test3 insert duplicate (should fail)
    if (!myADT.insert(profile1)) {
        cout << "Duplicate insertion correctly failed." << endl;
    } else {
        cout << "Duplicate insertion failed." << endl;
    }

    // Test4 remove
    if (myADT.remove(profile1)) {
        cout << "Profile1 removed SUCCESSFULLY." << endl;
    } else {
        cout << "Profile1 removal failed." << endl;
    }

    // Test5 remove non-existing (should fail)
    if (!myADT.remove(profile1)) {
        cout << "Remove non-existing correctly failed." << endl;
    } else {
        cout << "Remove non-existing failed." << endl;
    }

    // Print the contents of MyADT
    cout << "MyADT contents after operations:" << endl;
    myADT.print();

    // Continue more test cases

    // Test6 insert multiple profiles
    if (myADT.insert(profile2)) {
        cout << "Profile2 inserted SUCCESSFULLY." << endl;
    } else {
        cout << "Profile2 insertion failed." << endl;
    }

    if (myADT.insert(profile3)) {
        cout << "Profile3 inserted SUCCESSFULLY." << endl;
    } else {
        cout << "Profile3 insertion failed." << endl;
    }

    // Print the contents of MyADT after inserting more profiles
    cout << "MyADT contents after inserting profile2 and profile3:" << endl;
    myADT.print();

    // Test7 remove a profile
    if (myADT.remove(profile2)) {
        cout << "Profile2 removed SUCCESSFULLY." << endl;
    } else {
        cout << "Profile2 removal failed." << endl;
    }

    // Print the contents of MyADT after removing profile2
    cout << "MyADT contents after removing profile2:" << endl;
    myADT.print();

    // Test8 remove non-existing profile (should fail)
    if (!myADT.remove(profile2)) {
        cout << "Remove non-existing profile2 correctly failed." << endl;
    } else {
        cout << "Remove non-existing profile2 failed." << endl;
    }

    return 0;
}
// End of MyADTTestDriver.cpp