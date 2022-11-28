// hash_function.cpp
// Glenn G. Chappell
// 2022-11-27
//
// For CS 311 Fall 2022
// Demo of a typical hash function for integers
// Hashing code is based on MurmrHash3 by Austin Appleby 2008 (public
//  domain)
// http://github.com/aappleby/smhasher

#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <string>
using std::string;
using std::getline;
#include <sstream>
using std::istringstream;
#include <cstdint>
using std::uint32_t;


// hashFunc
// An integer hash function. Takes and returns uint32_t.
//
// Based on MurmurHash3 by Austin Appleby 2008 (public domain)
// http://github.com/aappleby/smhasher
//
// Does not throw (No-Throw Guarantee)
uint32_t hashFunc(uint32_t key)
{
    const uint32_t salt = 0xdeadbeefU;  // Value chosen by GGC
    uint32_t h = key * 0xcc9e2d51U;
    h = (h << 15) | (h >> 17);
    h *= 0x1b873593U;
    h ^= salt;
    h = (h << 13) | (h >> 19);
    h = (h * 5) + 0xe6546b64U;
    h ^= 4 ^ (h >> 16);
    h *= 0x85ebca6bU;
    h ^= h >> 13;
    h *= 0xc2b2ae35U;
    return h ^ (h >> 16);
}


// printBinary
// Given a 32-bit integer, prints it in binary to cout. No trailing
// newline is printed.
//
// Does not throw (No-Throw Guarantee)
void printBinary(uint32_t value)
{
    uint32_t mask = 0x80000000U;
    while (mask != 0)
    {
        if ((value & mask) != 0)
            cout << '1';
        else
            cout << '0';
        mask >>= 1;
    }
}


// getIput
// Input an integer or "q". On fatal error or input beginning with Q/q,
// return false. On non-fatal error, print message and retry. On
// successful integer input, set n to integer that was read and return
// true.
//
// Does not throw (No-Throw Guarantee)
bool getInput(const string & prompt,  // Print this before doing input
              uint32_t & n)           // Number we input
{
    while (true)
    {
        bool founderror = false;
        cout << prompt;
        string line;
        getline(cin, line);
        if (!cin)
        {
            if (cin.eof())      // End of file
                return false;   // Fatal error
            cin.clear();
            cin.ignore();
            founderror = true;  // Bad input; retry
        }
        else
        {
            if (line.size() > 0 && (line[0] == 'q' || line[0] == 'Q'))
                return false;
            istringstream is(line);
            is >> n;
            if (!is)
                founderror = true;  // Bad read from string; retry
        }

        if (!founderror)
            break;
        cout << "\n";
        cout << "Try again; please type an integer or \"q\" to quit"
             << endl;
    }

    return true;  // Successful input of integer
}


// Main program
// Repeatedly input a number n and print all n-Queen solutions.
// Terminates on fatal error in input or n <= 0.
int main()
{
    // Print explanation
    cout << "Hash Function Demo\n\n";
    cout << "Each integer you type will be hashed. The hash function\n";
    cout << "input (your integer) and output will be printed, in\n";
    cout << "both decimal and 32-bit binary.\n\n";

    while (true)
    {
        // Prompt & input
        uint32_t inval;
        bool good = getInput("Integer to hash (\"q\" to quit)? ",
                             inval);
        if (!good)
            break;

        // Apply hash function
        uint32_t outval = hashFunc(inval);

        // Print values in decimal & binary
        cout << "\n";
        cout << "Decimal: " << inval << " -> " << outval << "\n";
        cout << "Binary:  ";
        printBinary(inval);
        cout << " -> ";
        printBinary(outval);
        cout << "\n\n";
    }
}

