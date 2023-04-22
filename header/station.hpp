#ifndef __STATION
#define __STATION
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <assert.h>
#include <exception>
#include "exceptions.hpp"

using namespace std;

// station class
// stores names of station
class Station
{
private:
    string name_;

    Station(const string name) : name_(name){}; // constructor
public:
    string getName() const { return name_; } // returns name of the station
    double getDistance(const Station &from); // returns distance from another station
    static Station createStation(const string &s)
    {
        try
        {
            // if correct statio name is not provied
            if (s != "Mumbai" && s != "Delhi" && s != "Banglore" && s != "Kolkata" && s != "Chennai")
                throw Bad_Station();
            Station st = Station(s);
            return st;
        }
        catch (const Bad_Station &e)
        {
            std::cerr << e.what() << '\n';
            abort();
        }
    }
    // prints name of station
    friend ostream &operator<<(ostream &os, const Station &f)
    {
        os << f.name_;
        return os;
    }
    // ###################################################################################
    // unit test for station
    static void UnitTest(const string name1)
    {
        Station s1 = Station("Mumbai");
        assert(name1 == s1.getName());

        cout << "Success in Station Unit Testing" << endl;
    }
    // ###################################################################################
    // check if two station are equal
    bool operator==(const Station &rhs) const
    {
        if (name_ == rhs.name_)
        {
            return true;
        }
        return false;
    }

    ~Station(){};
};

#endif