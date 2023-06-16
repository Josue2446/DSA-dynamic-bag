// FILE: wk3_bag2demo_Josue.cpp
// 
// Summary: Demonstration program for the 2nd version of the bag 
//          (bag2.h and bag2.cxx). This is a the same as the 
//          demonstration program for bag1, except that we no longer 
//          need to check whether the bag reaches its capacity.
//
// Test Cases: used valgrind to check for memory leaks - valgrind --leak-check=full
//             output: ==3443== HEAP SUMMARY:
//                     ==3443== in use at exit: 0 bytes in 0 blocks
//                     ==3443== total heap usage: 3 allocs, 3 frees, 73,848 bytes allocated
//                     ==3443== All heap blocks were freed -- no leaks are possible
// 
// Author: Josue 
//
// Date: 04/21/2023
//
// Summary of Modifications: 04/21/2023 - added reduceCapacity(), 
//                                        added insert(const value_type& numCopies,
//                                                     const value_type& entry);
//                                        added bag(bag&& rhs) noexcept;
// Compiler: Ubuntu (g++)

#include <algorithm>    // Provides std::move()
#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "wk3_bag2_Jlopez.h"       // With Item defined as an int
using namespace std;
using namespace Josue;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bag, stopping
// when the user types a negative number.

void check_ages(bag& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bag when it is typed,
// stopping when the bag is empty.


int main( )
{
    bag ages;

    ages.insert(8,5);

    cout << "number of 5's: " << ages.count(5);
    cout << endl;
    cout << "size: " << ages.size();

    ages.erase_one(5);

    cout << endl << "number of 5's: " <<  ages.count(5);
    cout << endl << "size: " << ages.size();
    cout << endl;
    
    // testing move constructor
    bag ages2 = std::move(ages);

    cout << "ages2.size() = " << ages2.size() << endl;
    cout << "ages.size() = " << ages.size() << endl;
    cout << "number of 5's in ages2: " << ages2.count(5) << endl;    

    return EXIT_SUCCESS;  
}


void get_ages(bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type the ages in your family. ";
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(bag& ages)
{
    int user_input; // An age from the user's family

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}

