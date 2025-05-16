#include "Date.h"
#include <iostream>
#include <string>

void Date :: set(int month_, int day_, int year_, int hour_)
{
    month = month_;
    day = day_;
    year = year_;
    hour = hour_;    
}
bool Date :: operator<(const Date & rhs)
{
    return (year < rhs.year) || (year == rhs.year && month < rhs.month) || 
        (year == rhs.year && month == rhs.month && day < rhs.day) || 
        (year == rhs.year && month == rhs.month && day == rhs.day && hour < rhs.hour);
}
bool Date :: operator==(const Date & rhs)
{
    return (month == rhs.month && day == rhs.day && year == rhs.year && hour == rhs.hour);
}

bool Date::operator<=(const Date &rhs)
{
    return (*this == rhs) || (*this < rhs);
}

int Date::operator-(const Date &rhs)
{

     // calc hours from years
     int hoursFromYears = (year - rhs.year) * 365 * 24;
    
     // calc hours from months
     const int monthDays[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
     int hoursFromMonths = (monthDays[month - 1] - monthDays[rhs.month - 1]) * 24;
     
     // calc hours from days
     int hoursFromDays = (day - rhs.day) * 24;
     
     // Add direct hour difference
     int hourDiff = hour - rhs.hour;
     
     // Sum all differences
     return hoursFromYears + hoursFromMonths + hoursFromDays + hourDiff;
}

void Date::print()
{
    //print(): Prints the date in the format ”Month dd, yyyy, hh:00”. For example, “March 12, 2103, 23:00”.
    string monthString;
    if(month == 1)
    monthString = "January";
    if(month == 2)
    monthString = "February";
    if(month == 3)
    monthString = "March";
    if(month == 4)
    monthString = "April";
    if(month == 5)
    monthString = "May";
    if(month == 6)
    monthString = "June";
    if(month == 7)
    monthString = "July";
    if(month == 8)
    monthString = "August";
    if(month == 9)
    monthString = "September";
    if(month == 10)
    monthString = "October";
    if(month == 11)
    monthString = "November";
    if(month == 12)
    monthString = "December";

    cout << monthString << " " << day << ", " << year << ", " << hour << ":00";
}
