#ifndef __EXCEPTION
#define __EXCEPTION

#include <exception>

using namespace std;
// ###################################################################################
// abstract class for all the exception in date
class Bad_Date : public exception
{
private:
    /* data */
public:
    virtual const char *what() const throw() = 0;
};
// if format is wrong
class Bad_Format : public Bad_Date
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Date is not in correct format";
    }
};

// Year Out of Range
class Bad_Year : public Bad_Date
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Year Out of Range";
    }
};
// Month Out of Range
class Bad_Month : public Bad_Date
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Month Out of Range.";
    }
};
// Day Out of Range
class Bad_Day : public Bad_Date
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Day Out of Range.";
    }
};
// ###################################################################################
// abstract base class for all the exception in passenger class
class Bad_Passenger : public exception
{
private:
    /* data */
public:
    virtual const char *what() const throw() = 0;
};
// Passenger name not valid
class Bad_PassengerName : public Bad_Passenger
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Passenger name not valid.";
    }
};
// error in disability of Passenger
class Bad_PassengerDisability : public Bad_Passenger
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "There is an error in disability of Passenger.";
    }
};
// DOB of Passenger is not correct
class Bad_PassengerDOB : public Bad_Passenger
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "DOB of Passenger is not correct.";
    }
};
// Mobile of Passenger is not valid
class Bad_PassengerMobile : public Bad_Passenger
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Mobile of Passenger is not valid.";
    }
};
// Aadhar of Passenger is not valid
class Bad_PassengerAadhar : public Bad_Passenger
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Aadhar of Passenger is not valid.";
    }
};
// ###################################################################################
// abstract base class for all the exception in Bookings
class Bad_Booking : public exception
{
private:
    /* data */
public:
    virtual const char *what() const throw() = 0;
};
// Travel Date is not valid
class Bad_BookingDate : public Bad_Booking
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Travel Date is not valid.";
    }
};
// From and To Stations cannot be same.
class Bad_BookingStaion : public Bad_Booking
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "From and To Stations cannot be same.";
    }
};
// Passenger information and category do not match
class Bad_BookingInfo : public Bad_Booking
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "Passenger information and category do not match.";
    }
};
// ###################################################################################

// The Master data for railways is not correct
class Bad_Railways : public exception
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "The Master data for railways is not correct.";
    }
};
// ###################################################################################
// This not correct station 
class Bad_Station : public exception
{
private:
    /* data */
public:
    virtual const char *what() const throw()
    {
        return "This not correct station";
    }
};
// ###################################################################################

#endif