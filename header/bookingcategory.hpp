#ifndef __BookingCategory1
#define __BookingCategory1
#include <string>
#include <map>
#include "divyangconcession.hpp"

using namespace std;

template <typename T>
class DivyangType;
template <typename T>
class NormalType;

// ABstract base class for all booking category
class BookingCategory
{
    const string &name_;        // name of category

protected:
    // initializing bookingcategory
    BookingCategory(const string &name) : name_(name) {}
    virtual ~BookingCategory() {}

public:
    // returns name of the booking category
    virtual const string &getName() const = 0;
    // return the concession for the booking category
    // takes name of booking class as input
    virtual const double getConcession(const string &s) const = 0;

    // Unit test for all the booking categories
    // ---------------------------------------------------------------------------//
    static void UnitTB(const BookingCategory &, const bool t);
    static void UnitCancer(const BookingCategory &, const bool t);
    static void UnitOrthopedic(const BookingCategory &, const bool t);
    static void UnitBlind(const BookingCategory &, const bool t);
    static void UnitSeniorCitizenF(const BookingCategory &, const bool t);
    static void UnitSeniorCitizenM(const BookingCategory &, const bool t);
    static void UnitGeneral(const BookingCategory &, const bool t);
    static void UnitLadies(const BookingCategory &, const bool t);
    static void UnitTatkal(const BookingCategory &, const bool t);
    static void UnitPremiumTatkal(const BookingCategory &, const bool t);
    // ---------------------------------------------------------------------------//

    // print the booking category on console
    friend ostream &operator<<(ostream &os, const BookingCategory &f)
    {
        os << f.getName() << " ";
        return os;
    }
};
// ###################################################################################

// DIvyang derived for BookingCategory it is also an abstract class
class Divyang : public BookingCategory
{
    const string &name_;

    struct TBType
    {
    };
    struct OrthopedicType
    {
    };
    struct CancerType
    {
    };
    struct BlindType
    {
    };

protected:
    // constructor hidden from outside world
    Divyang(const string &name) : BookingCategory(name), name_(name) {}

    virtual ~Divyang() {}

public:
    // returns name of the booking category
    const string &getName() const { return name_; }
    // return the concession for the booking category
    // takes name of booking class as input
    virtual const double getConcession(const string &bClass) const = 0;


    // checks if the provided BookingCategory is of the respective Disability
    static bool isTB(const BookingCategory &);
    static bool isOrthopedic(const BookingCategory &);
    static bool isCancer(const BookingCategory &);
    static bool isBlind(const BookingCategory &);


    // typedefs to ease the writing of code and giving proper namespaces
    typedef DivyangType<TBType> TB;
    typedef DivyangType<OrthopedicType> Orthopedic;
    typedef DivyangType<CancerType> Cancer;
    typedef DivyangType<BlindType> Blind;
};
// ###################################################################################

class Normal : public BookingCategory
{
    const string &name_;
    struct GeneralType
    {
    };
    struct LadiesType
    {
    };
    struct SeniorCitizenMType
    {
    };
    struct SeniorCitizenFType
    {
    };
    struct TatkalType
    {
    };
    struct PremiumTatkalType
    {
    };

protected:
//  constructor hidden from outside world
    Normal(const string &name) : BookingCategory(name), name_(name) {}
    virtual ~Normal() {}

public:
    // returns name of the booking category
    const string &getName() const { return name_; }
    // return the concession for the booking category
    // takes name of booking class as input
    virtual const double getConcession(const string &bClass) const = 0;

    // checks if the provided BookingCategory is of the respective Disability
    static bool isGeneral(const BookingCategory &b);
    static bool isLadies(const BookingCategory &b);
    static bool isSeniorCitizenM(const BookingCategory &b);
    static bool isSeniorCitizenF(const BookingCategory &b);
    static bool isTatkal(const BookingCategory &b);
    static bool isPremiumTatkal(const BookingCategory &b);

    // typedefs to ease the writing of code and giving proper namespaces
    typedef NormalType<GeneralType> General;
    typedef NormalType<LadiesType> Ladies;
    typedef NormalType<SeniorCitizenMType> SeniorCitizenM;
    typedef NormalType<SeniorCitizenFType> SeniorCitizenF;
    typedef NormalType<TatkalType> Tatkal;
    typedef NormalType<PremiumTatkalType> PremiumTatkal;
};
// ###################################################################################

// a concrete template class for non disabled booking category
template <typename T>
class NormalType : public Normal
{
    static const string sName; // name of booking category
    static const double sConcession;    // concession factor for the booking category

    NormalType(const string &name = NormalType<T>::sName) : Normal(name) {}

    ~NormalType() {}

public:

    // create a static object of respective type so it saves memory as only
    // one instance is availabel all the tiem
    static const NormalType<T> &Type()
    {
        static const NormalType<T> theObject;
        return theObject;
    }
    // return the concession for the respective class 
    const double getConcession(const string &bClass) const
    {
        return sConcession;
    }

    static int a;
};
// ###################################################################################

// a concrete template class for disabled booking category
template <typename T>
class DivyangType : public Divyang
{
    static const string sName;       // name of booking category
    static const double sConcession; // concession factor for the booking category

    DivyangType(const string &name = DivyangType<T>::sName) : Divyang(name) {}
    ~DivyangType() {}

public:
    // create a static object of respective type so it saves memory as only
    // one instance is availabel all the tiem
    static const DivyangType<T> &Type()
    {
        static const DivyangType<T> theObject;
        return theObject;
    }
    // return the concession for the respective class
    const double getConcession(const string &bClass) const
    {
        return DivyangConcession::Concession().getConcession(bClass, sName);
    }
};

// ###################################################################################

// Implementation of function to check if the Booking Category of the respective type
// for Normal BOoking Type
inline bool Normal::isGeneral(const BookingCategory &g)
{
    return &g == &Normal::General::Type();
}
inline bool Normal::isLadies(const BookingCategory &g)
{
    return &g == &Normal::Ladies::Type();
}
inline bool Normal::isSeniorCitizenM(const BookingCategory &g)
{
    return &g == &Normal::SeniorCitizenM::Type();
}
inline bool Normal::isSeniorCitizenF(const BookingCategory &g)
{
    return &g == &Normal::SeniorCitizenF::Type();
}
inline bool Normal::isTatkal(const BookingCategory &g)
{
    return &g == &Normal::Tatkal::Type();
}
inline bool Normal::isPremiumTatkal(const BookingCategory &g)
{
    return &g == &Normal::PremiumTatkal::Type();
}
// for Divyang BOoking Type
inline bool Divyang::isTB(const BookingCategory &g)
{
    return &g == &Divyang::TB::Type();
}
inline bool Divyang::isOrthopedic(const BookingCategory &g)
{
    return &g == &Divyang::Orthopedic::Type();
}
inline bool Divyang::isCancer(const BookingCategory &g)
{
    return &g == &Divyang::Cancer::Type();
}
inline bool Divyang::isBlind(const BookingCategory &g)
{
    return &g == &Divyang::Blind::Type();
}
// ###################################################################################

// Initializing all the static variables
template <>
const double Normal::General::sConcession = 0;
template <>
const double Normal::SeniorCitizenM::sConcession = 0.4;
template <>
const double Normal::SeniorCitizenF::sConcession = 0.5;
template <>
const double Normal::Ladies::sConcession = 0;
template <>
const double Normal::Tatkal::sConcession = 0;
template <>
const double Normal::PremiumTatkal::sConcession = 0;

template <>
const string Normal::General::sName = "General";
template <>
const string Normal::SeniorCitizenM::sName = "SeniorCitizenMale";
template <>
const string Normal::SeniorCitizenF::sName = "SeniorCitizenFemale";
template <>
const string Normal::PremiumTatkal::sName = "PremiumTatkal";
template <>
const string Normal::Ladies::sName = "Ladies";
template <>
const string Normal::Tatkal::sName = "Tatkal";
template <>
const string Divyang::TB::sName = "TB";
template <>
const string Divyang::Cancer::sName = "Cancer";
template <>
const string Divyang::Orthopedic::sName = "Orthopedic";
template <>
const string Divyang::Blind::sName = "Blind";
// ###################################################################################

// Implementation of unit test function for all the template classes
void BookingCategory::UnitGeneral(const BookingCategory &b, const bool t)
{
    assert(Normal::isGeneral(b) == t);
    assert(b.getName() == "General");
    cout << "UnitGeneral Successful" <<endl;
}
void BookingCategory::UnitLadies(const BookingCategory &b, const bool t)
{
    assert(Normal::isLadies(b) == t);
    assert(b.getName() == "Ladies");
    cout << "UnitLadies Successful" << endl;
}
void BookingCategory::UnitSeniorCitizenM(const BookingCategory &b, const bool t)
{
    assert(Normal::isSeniorCitizenM(b) == t);
    assert(b.getName() == "SeniorCitizenM");
    cout << "UnitSeniorCitizenM Successful" << endl;
}
void BookingCategory::UnitSeniorCitizenF(const BookingCategory &b, const bool t)
{
    assert(Normal::isSeniorCitizenF(b) == t);
    assert(b.getName() == "SeniorCitizenF");
    cout << "UnitSeniorCitizenF Successful" << endl;
}
void BookingCategory::UnitTatkal(const BookingCategory &b, const bool t)
{
    assert(Normal::isTatkal(b) == t);
    assert(b.getName() == "Tatkal");
    cout << "UnitTatkal Successful" << endl;
}
void BookingCategory::UnitPremiumTatkal(const BookingCategory &b, const bool t)
{
    assert(Normal::isPremiumTatkal(b) == t);
    assert(b.getName() == "PremiumTatkal");
    cout << "UnitPremiumTatkal Successful" << endl;
}

void BookingCategory::UnitTB(const BookingCategory &b, const bool t)
{
    assert(Divyang::isTB(b) == t);
    assert(b.getName() == "TB");
    cout << "UnitTB Successful" << endl;
}
void BookingCategory::UnitCancer(const BookingCategory &b, const bool t)
{
    assert(Divyang::isCancer(b) == t);
    assert(b.getName() == "Cancer");
    cout << "UnitCancer Successful" << endl;
}
void BookingCategory::UnitOrthopedic(const BookingCategory &b, const bool t)
{
    assert(Divyang::isOrthopedic(b) == t);
    assert(b.getName() == "Orthopedic");
    cout << "UnitOrthopedic Successful" << endl;
}
void BookingCategory::UnitBlind(const BookingCategory &b, const bool t)
{
    assert(Divyang::isBlind(b) == t);
    assert(b.getName() == "Blind");
    cout << "UnitBlind Successful" << endl;
}
// ###################################################################################

#endif
