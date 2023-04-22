#ifndef __BookingClass
#define __BookingClass
#include <string>

using namespace std;

template <typename T>
class BookingClassType;

// an abstract base class for booking class
class BookingClass
{
    const string &name_;

    struct ACFirstClassType
    {
    };
    struct ExecutiveChairCarType
    {
    };
    struct AC2TierType
    {
    };
    struct FirstClassType
    {
    };
    struct AC3TierType
    {
    };
    struct ACChairCarType
    {
    };
    struct SleeperClassType
    {
    };
    struct SecondSittingType
    {
    };

protected:
    // initializer for the class
    BookingClass(const string &name) : name_(name) {}
    virtual ~BookingClass() {}

public:
    // returns name of the class
    const string &getName() const { return name_; }
    // virtual const string GetTitle() const = 0;
    // return the load factor for tha respective booking class
    virtual const double getLoadFactor() const = 0;
    // return the Reservation for tha respective booking class
    virtual const double getReservationCharge() const = 0;

    // functions to check if the Booking Class reference of the the respective type
    static bool isACFirstClass(const BookingClass &);
    static bool isExecutiveChairCar(const BookingClass &);
    static bool isAC2Tier(const BookingClass &);
    static bool isFirstClass(const BookingClass &);
    static bool isAC3Tier(const BookingClass &);
    static bool isACChairCar(const BookingClass &);
    static bool isSleeper(const BookingClass &);
    static bool isSecondSitting(const BookingClass &);

    // Declaration of unit test for all the classes
    static bool UnitTestACFirstClass(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestExecutiveChairCar(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestAC2Tier(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestFirstClass(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestAC3Tier(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestACChairCar(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestSleeper(const BookingClass &, const bool b, const double lf, const double rc);
    static bool UnitTestSecondSitting(const BookingClass &, const bool b, const double lf, const double rc);

    // print name of booking class
    friend ostream &operator<<(ostream &os, const BookingClass &f)
    {
        os << f.getName() << " ";
        return os;
    }

    // typedefs to ease the writing of code and giving proper namespaces
    typedef BookingClassType<ACFirstClassType> ACFirstClass;
    typedef BookingClassType<ExecutiveChairCarType> ExecutiveChairCar;
    typedef BookingClassType<AC2TierType> AC2Tier;
    typedef BookingClassType<FirstClassType> FirstClass;
    typedef BookingClassType<AC3TierType> AC3Tier;
    typedef BookingClassType<ACChairCarType> ACChairCar;
    typedef BookingClassType<SleeperClassType> Sleeper;
    typedef BookingClassType<SecondSittingType> SecondSitting;
};

template <typename T>
class BookingClassType : public BookingClass
{
    static const string sName;
    static const double sFareLoadFactor;
    // static const double sMinTatkalCharge;
    // static const double sMaxTatkalCharge;
    static const double sReservation;

    BookingClassType(const string &name = BookingClassType<T>::sName) : BookingClass(name) {}
    ~BookingClassType() {}

public:
    static const BookingClassType<T> &Type()
    {
        static const BookingClassType<T> theObject;
        return theObject;
    }
    // const string GetTitle() const
    // {
    //     return BookingClassType<T>::sName;
    // }
    const double getLoadFactor() const
    {
        return BookingClassType<T>::sFareLoadFactor;
    }
    const double getReservationCharge() const
    {
        return BookingClassType<T>::sReservation;
    }

    static int a;
};

// ###################################################################################

// Implementation of function to check if the Booking Class of the respective type

inline bool BookingClass::isACFirstClass(const BookingClass &g)
{
    return &g == &BookingClass::ACFirstClass::Type();
}
inline bool BookingClass::isExecutiveChairCar(const BookingClass &g)
{
    return &g == &BookingClass::ExecutiveChairCar::Type();
}
inline bool BookingClass::isAC2Tier(const BookingClass &g)
{
    return &g == &BookingClass::AC2Tier::Type();
}
inline bool BookingClass::isFirstClass(const BookingClass &g)
{
    return &g == &BookingClass::FirstClass::Type();
}
inline bool BookingClass::isAC3Tier(const BookingClass &g)
{
    return &g == &BookingClass::AC3Tier::Type();
}
inline bool BookingClass::isACChairCar(const BookingClass &g)
{
    return &g == &BookingClass::ACChairCar::Type();
}
inline bool BookingClass::isSleeper(const BookingClass &g)
{
    return &g == &BookingClass::Sleeper::Type();
}
inline bool BookingClass::isSecondSitting(const BookingClass &g)
{
    return &g == &BookingClass::SecondSitting::Type();
}
// ###################################################################################
// Implementation of unit test function for all the classes
inline bool BookingClass::UnitTestACFirstClass(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isACFirstClass(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);

    cout << "Success in ACFirstClass UnitTesting" << endl;
}
inline bool BookingClass::UnitTestExecutiveChairCar(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isExecutiveChairCar(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in ExecutiveChairCar UnitTesting" << endl;
}
inline bool BookingClass::UnitTestAC2Tier(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isAC2Tier(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in AC2Tier UnitTesting" << endl;
}
inline bool BookingClass::UnitTestFirstClass(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isFirstClass(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in FirstClass UnitTesting" << endl;
}
inline bool BookingClass::UnitTestAC3Tier(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isAC3Tier(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in AC3Tier UnitTesting" << endl;
}
inline bool BookingClass::UnitTestACChairCar(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isACChairCar(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in ACChairCar UnitTesting" << endl;
}
inline bool BookingClass::UnitTestSleeper(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isSleeper(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in Sleeper UnitTesting" << endl;
}
inline bool BookingClass::UnitTestSecondSitting(const BookingClass &g, const bool b, const double lf, const double rc)
{
    assert(isSecondSitting(g) == b);
    assert(g.getLoadFactor() == lf);
    assert(g.getReservationCharge() == rc);
    cout << "Success in SecondSitting UnitTesting" << endl;
}

// ###################################################################################
// Initializing all the static variables for all the template classes
// initializing sName
template <>
const string BookingClass::ACFirstClass::sName = "ACFirstClass";
template <>
const string BookingClass::ExecutiveChairCar::sName = "ExecutiveChairCar";
template <>
const string BookingClass::AC2Tier::sName = "AC2Tier";
template <>
const string BookingClass::FirstClass::sName = "FirstClass";
template <>
const string BookingClass::AC3Tier::sName = "AC3Tier";
template <>
const string BookingClass::ACChairCar::sName = "ACChairCar";
template <>
const string BookingClass::Sleeper::sName = "Sleeper";
template <>
const string BookingClass::SecondSitting::sName = "SecondSitting";

// initializing Load Factors
template <>
const double BookingClass::ACFirstClass::sFareLoadFactor = 6.50;
template <>
const double BookingClass::ExecutiveChairCar::sFareLoadFactor = 5.00;
template <>
const double BookingClass::AC2Tier::sFareLoadFactor = 4.00;
template <>
const double BookingClass::FirstClass::sFareLoadFactor = 3.00;
template <>
const double BookingClass::AC3Tier::sFareLoadFactor = 2.50;
template <>
const double BookingClass::ACChairCar::sFareLoadFactor = 2.00;
template <>
const double BookingClass::Sleeper::sFareLoadFactor = 1.00;
template <>
const double BookingClass::SecondSitting::sFareLoadFactor = 0.60;

// template <>
// const double BookingClass::ACFirstClass::sMinTatkalCharge = 400.00;
// template <>
// const double BookingClass::ExecutiveChairCar::sMinTatkalCharge = 400.00;
// template <>
// const double BookingClass::AC2Tier::sMinTatkalCharge = 400.00;
// template <>
// const double BookingClass::FirstClass::sMinTatkalCharge = 400.00;
// template <>
// const double BookingClass::AC3Tier::sMinTatkalCharge = 300.00;
// template <>
// const double BookingClass::ACChairCar::sMinTatkalCharge = 125.00;
// template <>
// const double BookingClass::Sleeper::sMinTatkalCharge = 100.00;
// template <>
// const double BookingClass::SecondSitting::sMinTatkalCharge = 10.00;

// template <>
// const double BookingClass::ACFirstClass::sMaxTatkalCharge = 500.0;
// template <>
// const double BookingClass::ExecutiveChairCar::sMaxTatkalCharge = 500.00;
// template <>
// const double BookingClass::AC2Tier::sMaxTatkalCharge = 500.00;
// template <>
// const double BookingClass::FirstClass::sMaxTatkalCharge = 500.00;
// template <>
// const double BookingClass::AC3Tier::sMaxTatkalCharge = 400.00;
// template <>
// const double BookingClass::ACChairCar::sMaxTatkalCharge = 225.00;
// template <>
// const double BookingClass::Sleeper::sMaxTatkalCharge = 200.00;
// template <>
// const double BookingClass::SecondSitting::sMaxTatkalCharge = 15.00;

template <>
const double BookingClass::ACFirstClass::sReservation = 60;
template <>
const double BookingClass::ExecutiveChairCar::sReservation = 60;
template <>
const double BookingClass::AC2Tier::sReservation = 50;
template <>
const double BookingClass::FirstClass::sReservation = 50;
template <>
const double BookingClass::AC3Tier::sReservation = 40;
template <>
const double BookingClass::ACChairCar::sReservation = 40;
template <>
const double BookingClass::Sleeper::sReservation = 20;
template <>
const double BookingClass::SecondSitting::sReservation = 15;

#endif