#ifndef __DIVYANGCONCESSION
#define __DIVYANGCONCESSION
#include <string>
#include <map>
// #include "bookingcategory.hpp"

using namespace std;

// A singleton class to store the concession of all the disabled types
class DivyangConcession
{
private:
    // hidden constructor and destructior
    DivyangConcession(){};
    ~DivyangConcession(){};
    // maps pair<string, string>  to a double which is concession
    // first string in booking class and second is disability name
    static map<pair<string, string>, double> sConcession;
    // // static DivyangConcession concession;

public:
    static const DivyangConcession &Concession();
    const double getConcession(const string &bClass, const string &disablity) const;
    // friend ostream &operator<<(ostream &os, const DivyangConcession &f);
    // unit test for the class
    // ###################################################################################

    void UnitTest(const string clas, const string disability, const double conces)
    {
        Concession();

        assert(getConcession(clas, disability) == conces);
        cout << "Success in Railways Unit Testing" << endl;
    }
    // ###################################################################################
};


const DivyangConcession &DivyangConcession::Concession() // COncession
{
    static DivyangConcession concession;
    if (sConcession.size() == 0)        // if not initialized till not then initialize
    {
        sConcession.insert(make_pair(make_pair("ACFirstClass", "Blind"), 0.50));
        sConcession.insert(make_pair(make_pair("ExecutiveChairCar", "Blind"), 0.75));
        sConcession.insert(make_pair(make_pair("AC2Tier", "Blind"), 0.50));
        sConcession.insert(make_pair(make_pair("FirstClass", "Blind"), 0.75));
        sConcession.insert(make_pair(make_pair("AC3Tier", "Blind"), 0.75));
        sConcession.insert(make_pair(make_pair("ACChairCar", "Blind"), 0.75));
        sConcession.insert(make_pair(make_pair("Sleeper", "Blind"), 0.75));
        sConcession.insert(make_pair(make_pair("SecondSitting", "Blind"), 0.75));

        sConcession.insert(make_pair(make_pair("ACFirstClass", "Orthopedic"), 0.50));
        sConcession.insert(make_pair(make_pair("ExecutiveChairCar", "Orthopedic"), 0.75));
        sConcession.insert(make_pair(make_pair("AC2Tier", "Orthopedic"), 0.50));
        sConcession.insert(make_pair(make_pair("FirstClass", "Orthopedic"), 0.75));
        sConcession.insert(make_pair(make_pair("AC3Tier", "Orthopedic"), 0.75));
        sConcession.insert(make_pair(make_pair("ACChairCar", "Orthopedic"), 0.75));
        sConcession.insert(make_pair(make_pair("Sleeper", "Orthopedic"), 0.75));
        sConcession.insert(make_pair(make_pair("SecondSitting", "Orthopedic"), 0.75));

        sConcession.insert(make_pair(make_pair("ACFirstClass", "Cancer"), 0.50));
        sConcession.insert(make_pair(make_pair("ExecutiveChairCar", "Cancer"), 0.75));
        sConcession.insert(make_pair(make_pair("AC2Tier", "Cancer"), 0.50));
        sConcession.insert(make_pair(make_pair("FirstClass", "Cancer"), 0.75));
        sConcession.insert(make_pair(make_pair("AC3Tier", "Cancer"), 1.00));
        sConcession.insert(make_pair(make_pair("ACChairCar", "Cancer"), 1.00));
        sConcession.insert(make_pair(make_pair("Sleeper", "Cancer"), 1.00));
        sConcession.insert(make_pair(make_pair("SecondSitting", "Cancer"), 1.00));

        sConcession.insert(make_pair(make_pair("ACFirstClass", "TB"), 0.00));
        sConcession.insert(make_pair(make_pair("ExecutiveChairCar", "TB"), 0.00));
        sConcession.insert(make_pair(make_pair("AC2Tier", "TB"), 0.00));
        sConcession.insert(make_pair(make_pair("FirstClass", "TB"), 0.75));
        sConcession.insert(make_pair(make_pair("AC3Tier", "TB"), 0.00));
        sConcession.insert(make_pair(make_pair("ACChairCar", "TB"), 0.00));
        sConcession.insert(make_pair(make_pair("Sleeper", "TB"), 0.75));
        sConcession.insert(make_pair(make_pair("SecondSitting", "TB"), 0.75));
    }
    return concession;
}
// return the concession 
const double DivyangConcession::getConcession(const string &bClass, const string &disablity) const
{
    // DivyangConcession::Concession();
    return sConcession[make_pair(bClass, disablity)];
}
// initializing the map
map<pair<string, string>, double> DivyangConcession::sConcession;

#endif