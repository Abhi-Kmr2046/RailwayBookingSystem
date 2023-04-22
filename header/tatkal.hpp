#ifndef __TATKAL
#define __TATKAL
#include <string>
#include <map>
#include "bookingcategory.hpp"

using namespace std;

// Singleton TatkalCharges class
class TatkalCharges
{
private:
    TatkalCharges(){};
    ~TatkalCharges(){};
    static map<pair<string, string>, double> sTatkalInfo;
    static map<string, double> sTatkalFarePercent;

    // static DivyangConcession concession;

public:
    static const TatkalCharges &Charges();
    // Get tatkal info line mincharge, maxCharge, minDis
    static const double getCharge(const string &bClass, const string &disablity);
    // get fare percent of the booking category
    static const double getFarePercent(const string &bClass);

    // friend ostream &operator<<(ostream &os, const DivyangConcession &f);
    // ###################################################################################
    void UnitTest(const string cl, const string term, const double conces, const double fare)
    {
        Charges();
        assert(Charges().getCharge(cl, term) == conces);
        assert(Charges().getFarePercent(cl) == fare);

        cout << "Success in Tatkal Unit Testing" << endl;
    }
    // ###################################################################################
};

const TatkalCharges &TatkalCharges::Charges() // Indian Railways
{
    static TatkalCharges c;
    if (sTatkalInfo.size() == 0)    // if class not initialized 
    {

        // hardcoding for fare percent for different classes and term pairs
        sTatkalInfo.insert(make_pair(make_pair("ACFirstClass", "minCharges"), 400));
        sTatkalInfo.insert(make_pair(make_pair("ExecutiveChairCar", "minCharges"), 400));
        sTatkalInfo.insert(make_pair(make_pair("AC2Tier", "minCharges"), 400));
        sTatkalInfo.insert(make_pair(make_pair("FirstClass", "minCharges"), 400));
        sTatkalInfo.insert(make_pair(make_pair("AC3Tier", "minCharges"), 300));
        sTatkalInfo.insert(make_pair(make_pair("ACChairCar", "minCharges"), 120));
        sTatkalInfo.insert(make_pair(make_pair("Sleeper", "minCharges"), 100));
        sTatkalInfo.insert(make_pair(make_pair("SecondSitting", "minCharges"), 10));

        sTatkalInfo.insert(make_pair(make_pair("ACFirstClass", "maxCharges"), 500));
        sTatkalInfo.insert(make_pair(make_pair("ExecutiveChairCar", "maxCharges"), 500));
        sTatkalInfo.insert(make_pair(make_pair("AC2Tier", "maxCharges"), 500));
        sTatkalInfo.insert(make_pair(make_pair("FirstClass", "maxCharges"), 500));
        sTatkalInfo.insert(make_pair(make_pair("AC3Tier", "maxCharges"), 400));
        sTatkalInfo.insert(make_pair(make_pair("ACChairCar", "maxCharges"), 225));
        sTatkalInfo.insert(make_pair(make_pair("Sleeper", "maxCharges"), 200));
        sTatkalInfo.insert(make_pair(make_pair("SecondSitting", "maxCharges"), 15));

        sTatkalInfo.insert(make_pair(make_pair("ACFirstClass", "minDis"), 500));
        sTatkalInfo.insert(make_pair(make_pair("ExecutiveChairCar", "minDis"), 250));
        sTatkalInfo.insert(make_pair(make_pair("AC2Tier", "minDis"), 500));
        sTatkalInfo.insert(make_pair(make_pair("FirstClass", "minDis"), 500));
        sTatkalInfo.insert(make_pair(make_pair("AC3Tier", "minDis"), 500));
        sTatkalInfo.insert(make_pair(make_pair("ACChairCar", "minDis"), 250));
        sTatkalInfo.insert(make_pair(make_pair("Sleeper", "minDis"), 500));
        sTatkalInfo.insert(make_pair(make_pair("SecondSitting", "minDis"), 100));
    }
    if (sTatkalFarePercent.size() == 0)
    {
        // hardcoding for fare percent for different classes
        sTatkalFarePercent.insert(make_pair("ACFirstClass", 30));
        sTatkalFarePercent.insert(make_pair("ExecutiveChairCar", 30));
        sTatkalFarePercent.insert(make_pair("AC2Tier", 30));
        sTatkalFarePercent.insert(make_pair("FirstClass", 30));
        sTatkalFarePercent.insert(make_pair("AC3Tier", 30));
        sTatkalFarePercent.insert(make_pair("ACChairCar", 30));
        sTatkalFarePercent.insert(make_pair("Sleeper", 30));
        sTatkalFarePercent.insert(make_pair("SecondSitting", 10));

    }
    return c;
}
// Get tatkal info line mincharge, maxCharge, minDis 
const double TatkalCharges::getCharge(const string &bClass, const string &term)
{
    return sTatkalInfo[make_pair(bClass, term)];
}
// get fare percent of the booking category
const double TatkalCharges::getFarePercent(const string &bClass)
{
    return sTatkalFarePercent[bClass];
}

// initialiing static variables
map<pair<string, string>, double> TatkalCharges::sTatkalInfo;
map<string,double> TatkalCharges::sTatkalFarePercent;

#endif