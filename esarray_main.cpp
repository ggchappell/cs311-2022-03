// esarray_main.cpp
// Glenn G. Chappell
// 2022-10-18
//
// For CS 311 Fall 2022
// Check whether ESArray package compiles
// Requires esarray.h, esarray.cpp

#include "esarray.h"  // For class ESArray
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <utility>
using std::move;
#include <cassert>
// For assert


// use_all_ESArray
// Use all functionality of class ESArray.
// Calls to ESArray functionality are not actually executed.
void use_all_ESArray()
{
    // Fake the compiler out. Return, but in a way that will make the
    //  compiler unsure whether we always return.
    for (int i = 0; i < 3; ++i)
    {
        if (i == 2)
            return;
    }
    assert(false);  // Do not execute past this point!

    [[maybe_unused]] int ii;  // For returned int values
    ESArray aa;               // For returned ESArray values

    // Member type size_type
    auto s = ESArray::size_type(9);

    // Member type value_type
    ESArray::value_type v;

    // Member type iterator
    ESArray::iterator it;

    // Member type const_iterator
    ESArray::const_iterator cit;

    // Default ctor
    const ESArray ca1;

    // Ctor from size
    ESArray a2(s);

    // Copy ctor
    ESArray a3(ca1);

    // Move ctor
    ESArray atmp1;
    ESArray a4(move(atmp1));

    // Dctor
    // Called when function exits after creating ESArray objects

    // Copy op=
    aa = (a2 = ca1);

    // Move op=
    ESArray atmp2;
    aa = (a3 = move(atmp2));

    // Bracket op, non-const
    a2[s] = v;
    ii = a2[s];

    // Bracket op, const
    ii = ca1[s];

    // size
    s = ca1.size();

    // empty
    if (ca1.empty()) cout << "empty";

    // begin, non-const
    it = a2.begin();
    *it = v;
    ii = *it;

    // begin, const
    cit = ca1.begin();
    ii = *cit;

    // end, non-const
    it = a2.end()-1;
    *it = v;
    ii = *it;

    // end, const
    cit = ca1.end()-1;
    ii = *cit;

    // resize
    a2.resize(s);

    // insert
    it = a2.insert(it, v);

    // erase
    it = a2.erase(it);

    // push_back
    a2.push_back(v);

    // pop_back
    a2.pop_back();

    // swap
    a2.swap(a3);
}


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Pretend to call all functions in ESArray package. Print message.
int main()
{
    // Use all functionality in ESArray package
    use_all_ESArray();

    // Inform the user what's up
    cout << "\n";
    cout << "**********************************\n";
    cout << "* ESArray package compiles. Yay! *\n";
    cout << "**********************************\n";
    cout << "\n";
    cout << "This program checks whether the ESArray package compiles."
         << " It includes\n";
    cout << "calls to all package functions, and it uses all package"
         << " member types.\n";
    cout << "However, when the program is executed, none of these"
         << " function calls are\n";
    cout << "actually made, and no ESArray objects are created.\n";
    cout << endl;

    // Wait for user
    cout << "Press ENTER to quit ";
    userPause();
}

