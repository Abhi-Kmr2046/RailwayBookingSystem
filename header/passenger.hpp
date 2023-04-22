#ifndef __PASSENGER
#define __PASSENGER
#include <string>
#include <string.h>
#include <assert.h>
#include <regex>
#include "date.hpp"
#include "gender.hpp"
#include "exceptions.hpp"

//  a name class to store name information of the passenger
class Name
{
private:
    const string fName, mName, lName;
    // constructor is hidden
    Name(string fName, string lName, string mName = "");

public:
    // checks if name is in correct format and then returns the name object
    static Name isValidName(string fName, string lName = "", string mName = "");
    // ###################################################################################
    static void UnitTest(string fName, string lName, string mName)
    {
        try
        {
            Name n = isValidName(fName, mName, lName);
            assert(n.fName == fName);
            assert(n.mName == mName);
            assert(n.lName == lName);
            cout << " Success in Name Unit Testing " << endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    // ###################################################################################

    // implementaiton of << operatior to print passenger name on console
    friend ostream &operator<<(ostream &os, const Name &n);
    ~Name(){};
};

// implementation of constructor
Name::Name(string fName, string lName, string mName) : fName(fName), mName(mName), lName(lName)
{
}
// checks if name is in correct format and then returns the name object
Name Name::isValidName(string fName, string lName, string mName)
{
    // checks condition of name and throws exception if it not in correct format
    try
    {
        if (fName.empty() && lName.empty())
        {
            throw Bad_PassengerName();
        }
    }
    catch (const Bad_Passenger &e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
    // mName is optional
    if (mName.empty())
        return Name(fName, lName);
    return Name(fName, lName, mName);
}
// implementaiton of << operatior to print passenger name on console
ostream &operator<<(ostream &os, const Name &n)
{
    os << n.fName << " " << n.mName << " " << n.lName;
    return os;
}

// Passenger class storing all the information about Passenger
class Passenger
{
    Passenger &operator=(const Passenger &) { return *this; }
    // hidden passenger constructor
    Passenger(
        const Name name,
        const Date dob,
        const Gender &gender,
        const string aadhar,
        const string mobile,
        const string disability_type,
        const string disability_id);

public:
    // information of the passenger
    const Name name;
    const Date dateOfBirth;
    const Gender &gender;
    const string aadhar;
    const string mobileNumber;
    const string disabilty_type;
    const string disabilty_ID;

    // checks if passenger details is in correct format and then returns the passenger object
    static Passenger isValidPassenger(
        const Name name,
        const Date dob,
        const Gender &gender,
        const string aadhar,
        const string mobile,
        const string disability_type,
        const string disability_id);
    // ###################################################################################
    // unit testing for passenger
    static void UnitTest(
        const Name name,
        const Date dob,
        const Gender &gender,
        const string aadhar,
        const string mobile,
        const string disability_type,
        const string disability_id);
    // ###################################################################################

    ~Passenger(){};
    // implementaiton of << operatior to print passenger details on console
    friend ostream &operator<<(ostream &os, const Passenger &f);
};
// implementaion of passenger constructor
Passenger::Passenger(
    const Name name,
    const Date dob,
    const Gender &gender,
    const string aadhar,
    const string mobile,
    const string disability_type,
    const string disability_id) : name(name),
                                  dateOfBirth(dob),
                                  gender(gender),
                                  aadhar(aadhar),
                                  mobileNumber(mobile),
                                  disabilty_type(disability_type),
                                  disabilty_ID(disability_id)
{
}

// checks if passenger details is in correct format and then returns the passenger object
// throws relevant exception
Passenger Passenger::isValidPassenger(
    const Name name,
    const Date dob,
    const Gender &gender,
    const string aadhar,
    const string mobile,
    const string disability_type = "",
    const string disability_id = "")
{
    try
    {
        regex phone_re("^[0-9]{10}$");
        regex aadhar_re("^[0-9]{12}$");
        // match phone number format
        if (!regex_match(mobile, phone_re))
        {
            // // cout<<mobile<<endl;
            throw Bad_PassengerMobile();
        }
        // match aadhar number format
        if (!regex_match(aadhar, aadhar_re))
        {
            throw Bad_PassengerAadhar();
        }
        // dob should be in past
        if (Date::getDifference(Date::Today, dob) >= 0)
        {
            throw Bad_PassengerDOB();
        }
        // correct disability is provided
        if (disability_type.empty() && !disability_id.empty())
        {
            // // cout << disability_type << endl;
            throw Bad_PassengerDisability();
        }
        if (!disability_type.empty() && disability_id.empty())
        {
            // // cout << disability_type << endl;
            throw Bad_PassengerDisability();
        }
        if (!disability_type.empty() && ((disability_type != "TB") &&
                                         (disability_type != "Orthopedic") &&
                                         (disability_type != "Cancer") &&
                                         (disability_type != "Blind")))
        {
            // // cout << disability_type << endl;
            throw Bad_PassengerDisability();
        }
        return Passenger(name, dob, gender, aadhar, mobile, disability_type, disability_id);
    }
    catch (const Bad_Passenger &e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
}
// implementaiton of << operatior to print passenger details on console
ostream &operator<<(ostream &os, const Passenger &f)
{
    os << f.gender.GetTitle() << " "
       << f.name << "\n"
       << f.dateOfBirth << "\n"
       << f.gender.GetName() << "\n"
       << f.aadhar << "\n"
       << f.disabilty_type << "\n"
       << f.disabilty_ID << endl;
    // os << "-----------------------------------\n";

    return os;
}

void Passenger::UnitTest(
    const Name name,
    const Date dob,
    const Gender &gender,
    const string aadhar,
    const string mobile,
    const string disability_type,
    const string disability_id)
{
    try
    {
        Passenger p = isValidPassenger(name,
                                       dob,
                                       gender,
                                       aadhar,
                                       mobile,
                                       disability_type,
                                       disability_id);
        // cout << p << endl;
        cout << "Unit Testing of Passenger is successful" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}

#endif