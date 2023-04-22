
#ifndef __DATEHPP
#define __DATEHPP

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include <assert.h>
#include "exceptions.hpp"

using namespace std;

class Date
{
    // Date class
    // stores date, month, year as 3 integers
    // convets date to dd/mmm/yy while printing
private:
    int date_, year_, month_num_;       // date year month in integers
    string month_;                      // month in string
    static vector<string> Month;        // a static vector of Month to map between integer month and string month
    // Range of year which we are condidering
    static const int MAX_VALID_YR = 2099;
    static const int MIN_VALID_YR = 2000;
    static vector<int> monthDays; // list of number of days in month
    // check if the given year is leap year
    static bool isLeap(int year);
    // count cumber of leap lears
    static int countLeapYears(Date d);
    // hidden initializer
    Date(int date, int month, int year);
    // extract integers from the string provided
    static void splitDate(string s, int &day, int &month, int &year);

public:
    // ! Staitc const for todays date, can be extended to take system date if 
    // ! I have assumed the that it will be enough for the assignment
    static const Date Today;        
    // Check if given date valid and returns a date object if it is
    // throws exceptions if not
    static Date isValidDate(string date);
    // number of days between two given dates
    static int getDifference(const Date &d1, const Date &d2);
    // get date month and year of the date object
    int getDate() const;
    string getMonth() const;
    int getMonthNum() const;
    int getYear() const;
    // print date in dd/mmm/yy format
    friend ostream &operator<<(ostream &os, const Date &d);

    // ###################################################################################
    // ! Unit tests for the Date Class
    static void UnitTest_date(string dat, int day, int month, int year)
    {
        try
        {
            Date d = isValidDate(dat);
            assert(d.getDate() == day);
            assert(d.getMonth() == Month[month - 1]);
            assert(d.getYear() == year);
            cout << "Success in Date Unit Testing" << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
        
    }
    static void UnitTest_getdiff(Date &d1, Date &d2, int count)
    {
        try
        {
            assert(Date::getDifference(d1, d2) == count);
            cout << "Success in Date getDifference Unit Testing" << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    static void UnitTest_isLeap(int &year, bool leap)
    {
        try
        {
            assert(Date::isLeap(year) == leap);
            cout << "Success in Date isleap Unit Testing" << endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // ###################################################################################

    ~Date(){};
};
// initializing month vector to map integer and string 
vector<string> Date::Month{
    "Jan",
    "Feb",
    "Mar",
    "Apr",
    "May",
    "Jun",
    "Jul",
    "Aug",
    "Sep",
    "Oct",
    "Nov",
    "Dec",
};
// number of days in month of given index
vector<int> Date::monthDays{31, 28, 31, 30, 31, 30,
                            31, 31, 30, 31, 30, 31};

// check if the year is leap year
bool Date::isLeap(int year)
{
    return (((year % 4 == 0) &&
             (year % 100 != 0)) ||
            (year % 400 == 0));
}
// check if date is valid
Date Date::isValidDate(string date)
{
    // // regex date_re("(^(((0[1-9]|1[0-9]|2[0-8])[\\/](0[1-9]|1[012]))|((29|30|31)[\\/](0[13578]|1[02]))|((29|30)[\\/](0[4,6,9]|11)))[\\/](19|[2-9][0-9])\\d\\d$)|(^29[\\/]02[\\/](19|[2-9][0-9])(00|04|08|12|16|20|24|28|32|36|40|44|48|52|56|60|64|68|72|76|80|84|88|92|96)$)");
    // regex for dd//mm//yyyy format
    regex date_re("^(0?[1-9]|[12][0-9]|3[01])[\\/\\-](0?[1-9]|1[012])[\\/\\-]\\d{4}$");

    int d, m, y;
    // check if date is valid else throw proper exception
    try
    {
        if (regex_match(date, date_re))
        {
            splitDate(date, d, m, y);
        }
        else
        {
            throw Bad_Format();
        }
        if (y > MAX_VALID_YR ||
            y < MIN_VALID_YR) // year within range
            throw Bad_Year();
        if (m < 1 || m > 12)
            throw Bad_Month(); // month withing range
        if (d < 1 || d > 31)
            throw Bad_Day(); // date not greater than 31

        if (m == 2) // for Feb
        {
            if (isLeap(y))
            {
                if (d > 29)
                    throw Bad_Day();
            }
            else
            {
                if (d > 28)
                    throw Bad_Day();
            }
        }

        if (m == 4 || m == 6 ||
            m == 9 || m == 11)
        {
            if (d > 30) // months with 30 days
                throw Bad_Day();
        }

        return Date(d, m, y);       // return the Date object 
    }
    catch (const Bad_Date &e)
    {   
        // abort the program when wrong input is provided
        // can be handled differently according to requirements
        std::cerr << e.what() << '\n';
        abort();
    }
}
// date constructor
Date::Date(int date, int month, int year)
{
    date_ = date;
    month_num_ = month;
    month_ = Month[month - 1];
    year_ = year;
}
// defining the function 
int Date::getDate() const { return date_; }
string Date::getMonth() const { return month_; }
int Date::getMonthNum() const { return month_num_; }
int Date::getYear() const { return year_; }

// print date in DD/MMM/YY format
ostream &operator<<(ostream &os, const Date &d)
{
    os << d.date_ << "/" << d.month_ << "/" << d.year_ % 100;
    return os;
}
// count number of leap years
int Date::countLeapYears(Date d)
{
    int years = d.year_;

    if (d.month_num_ <= 2)
        years--;

    return years / 4 - years / 100 + years / 400;
}
// definition of function to extract integer date month and year
void Date::splitDate(string s, int &day, int &month, int &year)
{
    char c;
    stringstream(s) >> day >> c >> month >> c >> year;
}

// difference between two dates
int Date::getDifference(const Date &d1, const Date &d2)
{
    long int n1 = d1.year_ * 365 + d1.date_;

    // Add days for months in given date
    for (int i = 0; i < d1.month_num_ - 1; i++)
        n1 += monthDays[i];

    // Since every leap year is of 366 days,
    // Add a day for every leap year
    n1 += countLeapYears(d1);

    // SIMILARLY, COUNT TOTAL NUMBER OF
    // DAYS BEFORE 'dt2'

    long int n2 = d2.year_ * 365 + d2.date_;
    for (int i = 0; i < d2.month_num_ - 1; i++)
        n2 += monthDays[i];
    n2 += countLeapYears(d2);

    // return difference between two counts
    return (n2 - n1);
}

#endif
