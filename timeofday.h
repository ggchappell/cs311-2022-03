// timeofday.h  UNFINISHED
// Glenn G. Chappell
// 2022-09-02
//
// For CS 311 Fall 2022
// Header for class TimeOfDay
// Time of day: hours, minutes, seconds

#ifndef FILE_TIMEOFDAY_H_INCLUDED
#define FILE_TIMEOFDAY_H_INCLUDED

#include <ostream>  // For std::ostream


// *********************************************************************
// class TimeOfDay - Class definition
// *********************************************************************


// class TimeOfDay
// Time of day: hours, minutes, seconds.
class TimeOfDay {

// ***** TimeOfDay: Ctors, dctor, op= *****
public:

    // Default ctor
    // Set time to midnight.
    TimeOfDay()
        :_secs(0)
    {}

    // Ctor from hours, minutes, seconds
    // Set time to given # of hours, minutes, seconds past midnight.
    TimeOfDay(int hh,
              int mm,
              int ss)
    {
        setTime(hh, mm, ss);
    }

// ***** TimeOfDay: General public operators *****
public:

    // op++ [pre]
    // Move time one second forward.
    TimeOfDay & operator++()
    {}

    // op++ [post]
    // Move time one second forward.
    TimeOfDay operator++(int dummy)
    {}

    // op-- [pre]
    // Move time one second backward.
    TimeOfDay & operator--()
    {}

    // op-- [post]
    // Move time one second backward.
    TimeOfDay operator--(int dummy)
    {}

// ***** TimeOfDay: General public functions *****
public:

    // getTime
    // Return hours, minutes, seconds in reference parameters.
    // Function defined in source file.
    void getTime(int & hh,
                 int & mm,
                 int & ss) const;

    // setTime
    // Set time to given # of hours, minutes, seconds past midnight.
    // Function defined in source file.
    void setTime(int hh,
                 int mm,
                 int ss);

// ***** TimeOfDay: Data members *****
private:

    int _secs;  // Seconds past midnight (range 0 .. 24*60*60-1)

};  // End class TimeOfDay


// *********************************************************************
// class TimeOfDay - Declarations of associated global operators
// *********************************************************************


// operator<< (ostream,TimeOfDay)
// Prints given TimeOfDay object as "hh:mm:ss", with hh padded on the
// left with blanks, and mm, ss padded on the left with zeroes.
// Function defined in source file.
std::ostream & operator<<(std::ostream & str,
                          const TimeOfDay & obj);


#endif  //#ifndef FILE_TIMEOFDAY_H_INCLUDED

