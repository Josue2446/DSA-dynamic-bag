// FILE: wk3_bag2_Josue.h
// 
// Summary: Demonstration program for the 2nd version of the bag 
//          (bag2.h and bag2.cxx). This is a the same as the 
//          demonstration program for bag1, except that we no longer 
//          need to check whether the bag reaches its capacity.
//
// Test Cases: N/A
//
// Author: Josue 
//
// Date: 04/21/2023
//
// Summary of Modifications: 04/21/2023 - added reduceCapacity(); 
//                                        added insert(const value_type& numCopies,
//                                                     const value_type& entry);
//                                        added bag(bag&& rhs) noexcept;
// Compiler: Ubuntu (g++)
//
// CLASS PROVIDED: bag (a container class for a collection of items)
//
// TYPEDEFS and MEMBER CONSTANTS for the bag class:
//   typedef _____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef _____ size_type
//     bag::size_type is the data type of any variable that keeps track of how
//     many items are in a bag.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     bag::DEFAULT_CAPACITY is the initial capacity of a bag that is created
//     by the default constructor.
//
// CONSTRUCTOR for the bag class:
//   bag(size_type initial_capacity = DEFAULT_CAPACITY)
//     Postcondition: The bag is empty with an initial capacity given by the
//     parameter. The insert function will work efficiently (without
//     allocating new memory) until this capacity is reached.
//
//   bag(bag&& rhs) : noexcept
//     Postcondition: a newly created bag steals the resources from an existing bag
//                    while leaving it in a valid state with default values for the 
//                    respective data types of the private member variables.
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   void reserve(size_type new_capacity)
//     Postcondition: The bag's current capacity is changed to the
//     new_capacity (but not less than the number of items already in the
//     bag). The insert function will work efficiently (without allocating
//     new memory) until the new capacity is reached.
//
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void insert(const value_type& numCopies, const value_type& entry)
//     Postcondition: entry is inserted numCopies times into the bag.
//
//   void reduceCapacity()
//     Postcondition: capacity is reduced to only how much is currently being used
//                    by freeing extra unused memory.
//
//   void operator +=(const bag& addend) 
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type size( ) const 
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: Return value is number of times target is in the bag
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//   Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag:
//   If there is insufficient dynamic memory, then the following functions throw
//   bad_alloc: The constructors, reserve, insert, operator += ,
//   operator +, and the assignment operator.

#ifndef MAIN_SAVITCH_BAG2_H
#define MAIN_SAVITCH_BAG2_H
#include <cstdlib>  // Provides size_t

namespace Josue
{
    class bag
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef int value_type;
        typedef std::size_t size_type;
        static const size_type DEFAULT_CAPACITY = 30;        
        // CONSTRUCTORS and DESTRUCTOR
        bag(size_type initial_capacity = DEFAULT_CAPACITY);
        bag(const bag& source);
        // move constructor
        bag(bag&& rhs) noexcept;
        ~bag( );
        // MODIFICATION MEMBER FUNCTIONS
        void reserve(size_type new_capacity);
        bool erase_one(const value_type& target);
        	size_type erase(const value_type& target);
        void insert(const value_type& entry);
        void insert(const value_type& numCopies, const value_type& entry);
        void reduceCapacity();
        void operator +=(const bag& addend);
        void operator =(const bag& source);
        // CONSTANT MEMBER FUNCTIONS
        size_type size( ) const { return used; }
        size_type count(const value_type& target) const;
    private:
        value_type *data;     // Pointer to partially filled dynamic array
        size_type used;       // How much of array is being used
        size_type capacity;   // Current capacity of the bag
    };

    // NONMEMBER FUNCTIONS for the bag class
    bag operator +(const bag& b1, const bag& b2);
}

#endif

