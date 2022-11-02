// rpneval.h  UNFINISHED
// Glenn G. Chappell
// 2022-11-02
//
// For CS 311 Fall 2022
// Header for rpnEval: Reverse Polish Notation evaluation
// Example application of a Stack
// There is no associated source file.

#ifndef FILE_RPNEVAL_H_INCLUDED
#define FILE_RPNEVAL_H_INCLUDED

#include <string>
// For std::string
#include <stack>
// For std::stack
#include <cctype>
// For std::isdigit
#include <stdexcept>
// For std::domain_error
// For std::out_of_range
// For std::overflow_error


// Note on "inline"
//
// Marking a function "inline" makes it unavailable to the linker. Thus,
// defining the function in multiple source files does not violate the
// One Definition Rule. As a result, we may define the function in a
// header. If all functions in a header-source pair are inline, then no
// source file is needed.
//
// Member functions defined inside a class definition are implicitly
// inline. Global functions must be explicitly marked.


// isInteger
// Given a string, returns true if it represents an integer, that is, if
// it consists of one or more ASCII digits preceded by an optional sign
// ('+', '-').
// No-Throw Guarantee
inline
bool isInteger(const std::string & str) noexcept
{
    if (str.empty())
        return false;
    char c = str.front();
    if (!std::isdigit(c) && c != '+' && c != '-')
        return false;

    for (size_t i = 1; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }

    // Now either we have an integer, or we have "+" or "-"
    return std::isdigit(str.back());
}


// isBinop
// Given a string, returns true if it consists of a single arithmetic
// binary-operation character ('+', '-', '*', '/').
// No-Throw Guarantee
inline
bool isBinop(const std::string & str) noexcept
{
    if (str.size() != 1)
        return false;
    char c = str.front();
    return c == '+' || c == '-' || c == '*' || c == '/';
}


// rpnEval
// Do a single step in RPN expression evaluation.
// Given a stack<int> and a string, interpret the string as a command,
// and use it to operate on the stack.
//   c, C: clear stack.
//   <integer>: push value on stack.
//   +, -, *, /: binary arithmetic operator.
//     Operands taken from top 2 stack items; stack underflow throws.
//     "/" is integer division; x/0 throws.
//     Result is left in top item on stack.
//   Unknown command: throws.
// May throw std::bad_alloc on out-of-memory, std::domain_error on
// unknown command, std::out_of_range on stack underflow, and
// std::overflow_error on division by zero.
// Basic Guarantee
inline
void rpnEval(std::stack<int> & s,
             const std::string & token)
{
    // TODO: WRITE THIS!!!
}


#endif  //#ifndef FILE_RPNEVAL_H_INCLUDED

