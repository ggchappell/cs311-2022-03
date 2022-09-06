// inventoryentry_test.cpp
// Glenn G. Chappell
// 2022-09-06
//
// For CS 311 Fall 2022
// Test program for class InventoryEntry
// For Assignment 1, Exercise A
// Uses the "doctest" unit-testing framework, version 2
// Requires doctest.h, inventoryentry.h, inventoryentry.cpp

// Includes for code to be tested
#include "inventoryentry.h"  // For class InventoryEntry
#include "inventoryentry.h"  // Double-inclusion check, for testing only

// Includes for the "doctest" unit-testing framework
#define DOCTEST_CONFIG_IMPLEMENT
                             // We write our own main
#define DOCTEST_CONFIG_SUPER_FAST_ASSERTS
                             // Reduce compile time
#include "doctest.h"         // For doctest

// Includes for all test programs
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;

// Additional includes for this test program
#include <string>
using std::string;
#include <ostream>
using std::ostream;
#include <sstream>
using std::ostringstream;
#include <cstddef>
using std::size_t;
#include <utility>
using std::move;

// Printable name for this test suite
const std::string test_suite_name =
    "class InventoryEntry"
    " - CS 311 Assn 1, Ex A";


// *********************************************************************
// Helper Functions/Classes for This Test Program
// *********************************************************************


// class TypeCheck
// This class exists in order to have static member function "check",
// which takes a parameter of a given type, by reference. Objects of
// type TypeCheck<T> cannot be created.
// Usage:
//     TypeCheck<MyType>::check(x)
//      returns true if the type of x is (MyType) or (const MyType),
//      otherwise false.
// Invariants: None.
// Requirements on Types: None.
template<typename T>
class TypeCheck {

private:

    // No default ctor
    TypeCheck() = delete;

    // Uncopyable. Do not define copy/move ctor/assn.
    TypeCheck(const TypeCheck &) = delete;
    TypeCheck(TypeCheck &&) = delete;
    TypeCheck<T> & operator=(const TypeCheck &) = delete;
    TypeCheck<T> & operator=(TypeCheck &&) = delete;

    // Compiler-generated dctor is used (but irrelevant).
    ~TypeCheck() = default;

public:

    // check
    // The function and function template below simulate a single
    // function that takes a single parameter, and returns true iff the
    // parameter has type T or (const T).

    // check (reference-to-const T)
    // Pre: None.
    // Post:
    //     Return is true.
    // Does not throw (No-Throw Guarantee)
    static bool check([[maybe_unused]] const T & param)
    {
        return true;
    }

    // check (reference-to-const non-T)
    // Pre: None.
    // Post:
    //     Return is false.
    // Requirements on types: None.
    // Does not throw (No-Throw Guarantee)
    template <typename OtherType>
    static bool check([[maybe_unused]] const OtherType & param)
    {
        return false;
    }

};  // End class TypeCheck


// *********************************************************************
// Test Cases
// *********************************************************************


TEST_CASE( "Function return types are correct" )
{
    InventoryEntry t1;
    InventoryEntry t2;

    SUBCASE( "Copy assn returns InventoryEntry by ref" )
    {
        [[maybe_unused]] InventoryEntry & r(t1 = t2);  // By-ref check
        REQUIRE( TypeCheck<InventoryEntry>::check(t1 = t2) );
    }

    SUBCASE( "Move assn returns InventoryEntry by ref" )
    {
        InventoryEntry t_movable;
        [[maybe_unused]] InventoryEntry & r(t1 = move(t_movable));
                                                      // By-ref check
        REQUIRE( TypeCheck<InventoryEntry>::check(t1
                                                  = move(t_movable)) );
    }

    SUBCASE( "InventoryEntry::getName returns string by value" )
    {
        [[maybe_unused]] string && rr(t1.getName());  // By-value check
        REQUIRE( TypeCheck<string>::check(t1.getName()) );
    }

    SUBCASE( "InventoryEntry::getQuantity returns int by value" )
    {
        [[maybe_unused]] int && rr(t1.getQuantity());  // By-value check
        REQUIRE( TypeCheck<int>::check(t1.getQuantity()) );
    }

    SUBCASE( "InventoryEntry::empty returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1.empty());  // By-value check
        REQUIRE( TypeCheck<bool>::check(t1.empty()) );
    }

    SUBCASE( "InventoryEntry::toString returns string by value" )
    {
        [[maybe_unused]] string && rr(t1.toString());  // By-value check
        REQUIRE( TypeCheck<string>::check(t1.toString()) );
    }

    SUBCASE( "InventoryEntry::operator++ [pre] returns by ref" )
    {
        [[maybe_unused]] InventoryEntry & r(++t1);  // By-ref check
        REQUIRE( TypeCheck<InventoryEntry>::check(++t1) );
    }

    SUBCASE( "InventoryEntry::operator++ [post] returns by value" )
    {
        [[maybe_unused]] InventoryEntry && rr(t1++);  // by-value check
        REQUIRE( TypeCheck<InventoryEntry>::check(t1++) );
    }

    SUBCASE( "InventoryEntry::operator-- [pre] returns by ref" )
    {
        [[maybe_unused]] InventoryEntry & r(--t1);  // By-ref check
        REQUIRE( TypeCheck<InventoryEntry>::check(--t1) );
    }

    SUBCASE( "InventoryEntry::operator-- [post] returns by value" )
    {
        [[maybe_unused]] InventoryEntry && rr(t1--);  // by-value check
        REQUIRE( TypeCheck<InventoryEntry>::check(t1--) );
    }

    SUBCASE( "operator== returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1 == t2);  // by-value check
        REQUIRE( TypeCheck<bool>::check(t1 == t2) );
    }

    SUBCASE( "operator!= returns bool by value" )
    {
        [[maybe_unused]] bool && rr(t1 != t2);  // by-value check
        REQUIRE( TypeCheck<bool>::check(t1 != t2) );
    }

    SUBCASE( "operator<< returns ostream by ref" )
    {
        ostringstream ostr;
        [[maybe_unused]] ostream & r(ostr << t1);  // By-reference check
        REQUIRE( TypeCheck<ostream>::check(ostr << t1) );
    }
}


TEST_CASE( "Functions are const-correct (passes if it compiles)" )
{
    SUBCASE( "Calling functions on a const InventoryEntry object" )
    {
        const InventoryEntry tc1;

        [[maybe_unused]] string s1 = tc1.getName();
                                     // InventoryEntry::getName
        [[maybe_unused]] int w = tc1.getQuantity();
                                     // InventoryEntry::getQuantity
        [[maybe_unused]] bool b = tc1.empty();
                                     // InventoryEntry::empty
        [[maybe_unused]] string s2 = tc1.toString();
                                     // InventoryEntry::toString

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }

    SUBCASE( "Taking const InventoryEntry arguments" )
    {
        const InventoryEntry tc1;
        const InventoryEntry tc2;

        InventoryEntry t3 = tc1;     // Copy ctor
        t3 = tc1;                    // Copy assn

        [[maybe_unused]] bool b1 = (tc1 == tc2);
                                     // op==
        [[maybe_unused]] bool b2 = (tc1 != tc2);
                                     // op!=
        ostringstream ostr;
        ostr << tc1;                 // op<<

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }

    SUBCASE( "Taking const string arguments" )
    {
        const string s;

        InventoryEntry t(s, 0);       // Data ctor
        t.setName(s);                // InventoryEntry::setName

        REQUIRE( 0 == 0 );           // Section passes if it compiles
    }
}


TEST_CASE( "Default-cted InventoryEntry object: blank name, 0 count" )
{
    InventoryEntry t1;

    REQUIRE( t1.getName() == "NOT SPECIFIED" );
    REQUIRE( t1.getQuantity() == 0 );
    REQUIRE( t1.empty() );

    SUBCASE( "Set name" )
    {
        t1.setName("abc");

        REQUIRE( t1.getName() == "abc" );
        REQUIRE( t1.getQuantity() == 0 );
        REQUIRE( t1.empty() );
    }

    SUBCASE( "Set quantity" )
    {
        t1.setQuantity(20);

        REQUIRE( t1.getName() == "NOT SPECIFIED" );
        REQUIRE( t1.getQuantity() == 20 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set name, quantity" )
    {
        t1.setName("def");
        t1.setQuantity(30);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getQuantity() == 30 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set quantity, name" )
    {
        t1.setQuantity(40);
        t1.setName("ghi");

        REQUIRE( t1.getName() == "ghi" );
        REQUIRE( t1.getQuantity() == 40 );
        REQUIRE_FALSE( t1.empty() );
    }
}


TEST_CASE( "Data-cted InventoryEntry object" )
{
    InventoryEntry t1("xyz", 100);

    REQUIRE( t1.getName() == "xyz" );
    REQUIRE( t1.getQuantity() == 100 );
    REQUIRE_FALSE( t1.empty() );

    SUBCASE( "Set name" )
    {
        t1.setName("abc");

        REQUIRE( t1.getName() == "abc" );
        REQUIRE( t1.getQuantity() == 100 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set quantity" )
    {
        t1.setQuantity(20);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getQuantity() == 20 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set name, quantity" )
    {
        t1.setName("def");
        t1.setQuantity(30);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getQuantity() == 30 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Set quantity, name" )
    {
        t1.setQuantity(40);
        t1.setName("ghi");

        REQUIRE( t1.getName() == "ghi" );
        REQUIRE( t1.getQuantity() == 40 );
        REQUIRE_FALSE( t1.empty() );
    }
}


TEST_CASE( "Copied InventoryEntry objects" )
{
    SUBCASE( "Copy-cted InventoryEntry object" )
    {
        InventoryEntry t1("xyz", 100);
        InventoryEntry t2 = t1;

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getQuantity() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 100 );
        REQUIRE_FALSE( t2.empty() );

        t2.setName("abc");
        t2.setQuantity(10);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getQuantity() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getQuantity() == 10 );
        REQUIRE_FALSE( t2.empty() );

        t1.setName("def");
        t1.setQuantity(20);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getQuantity() == 20 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getQuantity() == 10 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Copy-assigned InventoryEntry object" )
    {
        InventoryEntry t1("xyz", 100);
        InventoryEntry t2;
        t2 = t1;

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getQuantity() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 100 );
        REQUIRE_FALSE( t2.empty() );

        t2.setName("abc");
        t2.setQuantity(10);

        REQUIRE( t1.getName() == "xyz" );
        REQUIRE( t1.getQuantity() == 100 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getQuantity() == 10 );
        REQUIRE_FALSE( t2.empty() );

        t1.setName("def");
        t1.setQuantity(20);

        REQUIRE( t1.getName() == "def" );
        REQUIRE( t1.getQuantity() == 20 );
        REQUIRE_FALSE( t1.empty() );
        REQUIRE( t2.getName() == "abc" );
        REQUIRE( t2.getQuantity() == 10 );
        REQUIRE_FALSE( t2.empty() );
    }
}


TEST_CASE( "String conversions" )
{
    InventoryEntry t1;
    InventoryEntry t2("xyz", 100);
    InventoryEntry t3("", 0);

    SUBCASE( "InventoryEntry::toString" )
    {
        REQUIRE( t1.toString() == "NOT SPECIFIED (0)" );
        REQUIRE( t2.toString() == "xyz (100)" );
        REQUIRE( t3.toString() == " (0)" );
    }

    SUBCASE( "operator<<(ostream,InventoryEntry)" )
    {
        ostringstream ostr1;
        ostr1 << t1;
        REQUIRE( ostr1.str() == "NOT SPECIFIED (0)" );
        ostringstream ostr2;
        ostr2 << t2;
        REQUIRE( ostr2.str() == "xyz (100)" );
        ostringstream ostr3;
        ostr3 << t3;
        REQUIRE( ostr3.str() == " (0)" );
    }
}


TEST_CASE( "Increment & decrement" )
{
    InventoryEntry t1;
    InventoryEntry t2("xyz", 10);

    SUBCASE( "Increment ordinary object" )
    {
        InventoryEntry t3 = (++t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 11 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t3.getName() == "xyz" );
        REQUIRE( t3.getQuantity() == 11 );
        REQUIRE_FALSE( t3.empty() );

        InventoryEntry t4 = (t2++);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 12);
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t4.getName() == "xyz" );
        REQUIRE( t4.getQuantity() == 11 );
        REQUIRE_FALSE( t4.empty() );

        ++(++t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 14 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Increment object with zero count" )
    {
        ++t1;
        REQUIRE( t1.getName() == "NOT SPECIFIED" );
        REQUIRE( t1.getQuantity() == 1 );
        REQUIRE_FALSE( t1.empty() );

        t1++;
        REQUIRE( t1.getName() == "NOT SPECIFIED" );
        REQUIRE( t1.getQuantity() == 2 );
        REQUIRE_FALSE( t1.empty() );
    }

    SUBCASE( "Decrement ordinary object" )
    {
        InventoryEntry t3 = (--t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 9 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t3.getName() == "xyz" );
        REQUIRE( t3.getQuantity() == 9 );
        REQUIRE_FALSE( t3.empty() );

        InventoryEntry t4 = (t2--);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 8 );
        REQUIRE_FALSE( t2.empty() );
        REQUIRE( t4.getName() == "xyz" );
        REQUIRE( t4.getQuantity() == 9 );
        REQUIRE_FALSE( t4.empty() );

        --(--t2);
        REQUIRE( t2.getName() == "xyz" );
        REQUIRE( t2.getQuantity() == 6 );
        REQUIRE_FALSE( t2.empty() );
    }

    SUBCASE( "Decrement object with zero count" )
    {
        --t1;
        REQUIRE( t1.getName() == "NOT SPECIFIED" );
        REQUIRE( t1.getQuantity() == 0 );
        REQUIRE( t1.empty() );

        t1--;
        REQUIRE( t1.getName() == "NOT SPECIFIED" );
        REQUIRE( t1.getQuantity() == 0 );
        REQUIRE( t1.empty() );
    }
}


TEST_CASE( "Equality & inequality" )
{
    InventoryEntry t1("abc", 10);  // Base value
    InventoryEntry t2("abc", 10);  // Same
    InventoryEntry t3("def", 10);  // Different name
    InventoryEntry t4("abc", 20);  // Different count
    InventoryEntry t5("def", 20);  // Different name & count

    SUBCASE( "Equality" )
    {
        REQUIRE( t1 == t1 );
        REQUIRE( t1 == t2 );
        REQUIRE( t2 == t1 );
        REQUIRE_FALSE( t1 == t3 );
        REQUIRE_FALSE( t3 == t1 );
        REQUIRE_FALSE( t1 == t4 );
        REQUIRE_FALSE( t4 == t1 );
        REQUIRE_FALSE( t1 == t5 );
        REQUIRE_FALSE( t5 == t1 );
    }

    SUBCASE( "Inequality" )
    {
        REQUIRE_FALSE( t1 != t1 );
        REQUIRE_FALSE( t1 != t2 );
        REQUIRE_FALSE( t2 != t1 );
        REQUIRE( t1 != t3 );
        REQUIRE( t3 != t1 );
        REQUIRE( t1 != t4 );
        REQUIRE( t4 != t1 );
        REQUIRE( t1 != t5 );
        REQUIRE( t5 != t1 );
    }
}


TEST_CASE( "Large values" )
{
    const size_t bigname_len = 1000001;
    string bigname(bigname_len, 'x');
        // We make this into a long string

    int bigcount = 2147483641;
        // Almost greatest 32-bit signed value

    ostringstream ostr;
    ostr << bigname << " (" << bigcount << ")";
    string bigstringform = ostr.str();
        // String form of InventoryEntry(bigname, bigcount)

    SUBCASE( "Construction from large values" )
    {
        InventoryEntry t1(bigname, bigcount);

        REQUIRE( t1.getName() == bigname );
        REQUIRE( t1.getQuantity() == bigcount );
        REQUIRE_FALSE( t1.empty() );

        // Check size & prefix first, to avoid enormous error messages
        REQUIRE( t1.toString().size() == bigstringform.size() );
        REQUIRE( t1.toString().substr(0,20)
                   == bigstringform.substr(0,20) );
        REQUIRE( t1.toString() == bigstringform );
    }

    SUBCASE( "Set functions, passing large values" )
    {
        InventoryEntry t1;
        t1.setName(bigname);
        t1.setQuantity(bigcount);

        REQUIRE( t1.getName() == bigname );
        REQUIRE( t1.getQuantity() == bigcount );
        REQUIRE_FALSE( t1.empty() );

        // Check size & prefix first, to avoid enormous error messages
        REQUIRE( t1.toString().size() == bigstringform.size() );
        REQUIRE( t1.toString().substr(0,20)
                   == bigstringform.substr(0,20) );
        REQUIRE( t1.toString() == bigstringform );
    }
}


TEST_CASE( "Same-object tests" )
{
    SUBCASE("Copy assignment returns *this")
    {
        InventoryEntry t1;
        InventoryEntry t2;
        InventoryEntry & r(t1 = t2);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("Move assignment returns *this")
    {
        InventoryEntry t1;
        InventoryEntry t_movable;
        InventoryEntry & r(t1 = move(t_movable));
        REQUIRE( &r == &t1 );
    }

    SUBCASE("pre-increment returns *this")
    {
        InventoryEntry t1;
        InventoryEntry & r(++t1);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("pre-decrement returns *this")
    {
        InventoryEntry t1;
        InventoryEntry & r(--t1);
        REQUIRE( &r == &t1 );
    }

    SUBCASE("post-increment returns copy")
    {
        InventoryEntry t1;
        InventoryEntry && rr1(t1++);
        InventoryEntry && rr2(t1++);
        REQUIRE( &rr1 != &t1 );
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("post-decrement returns copy")
    {
        InventoryEntry t1;
        InventoryEntry && rr1(t1--);
        InventoryEntry && rr2(t1--);
        REQUIRE( &rr1 != &t1 );
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("getName returns copy")
    {
        InventoryEntry t1;
        string && rr1(t1.getName());
        string && rr2(t1.getName());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("getQuantity returns copy")
    {
        InventoryEntry t1;
        int && rr1(t1.getQuantity());
        int && rr2(t1.getQuantity());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("empty returns copy")
    {
        InventoryEntry t1;
        bool && rr1(t1.empty());
        bool && rr2(t1.empty());
        REQUIRE( &rr1 != &rr2 );
    }

    SUBCASE("operator<< returns original stream")
    {
        ostringstream ostr;
        InventoryEntry t1;
        ostream & r(ostr << t1);
        REQUIRE( &r == &ostr );
    }
}


// *********************************************************************
// Main Program
// *********************************************************************


// userPause
// Wait for user to press ENTER: read all chars through first newline.
void userPause()
{
    std::cout.flush();
    while (std::cin.get() != '\n') ;
}


// Main program
// Run all tests. Prompt for ENTER before exiting.
int main(int argc,
         char *argv[])
{
    doctest::Context dtcontext;
                             // Primary doctest object
    int dtresult;            // doctest return code; for return by main

    // Handle command line
    dtcontext.applyCommandLine(argc, argv);
    dtresult = 0;            // doctest flags no command-line errors
                             //  (strange but true)

    if (!dtresult)           // Continue only if no command-line error
    {
        // Run test suites
        cout << "BEGIN tests for " << test_suite_name << "\n" << endl;
        dtresult = dtcontext.run();
        cout << "END tests for " << test_suite_name << "\n" << endl;
    }

    // If we want to do something else here, then we need to check
    // context.shouldExit() first.

    // Wait for user
    std::cout << "Press ENTER to quit ";
    userPause();

    // Program return value is return code from doctest
    return dtresult;
}

