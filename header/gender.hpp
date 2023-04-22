#ifndef __GENDER
#define __GENDER
#include <string>

using namespace std;

template <typename T>
class GenderTypes;

// Abstract base class for all the gender 
class Gender
{
    const string &name_;

    struct MaleType
    {
    };
    struct FemaleType
    {
    };

protected:
    // hidden constructor  
    Gender(const string &name) : name_(name) {}

public:
    virtual ~Gender() {}
    const string &GetName() const { return name_; }     // return the name fo gender
    virtual const string GetTitle() const = 0;          // returns salutaion of gender
    static bool IsMale(const Gender &);                 // checks if Gender Reference if Male
    static bool IsFemale(const Gender &);               // checks if Gender Reference if Female

    // ###################################################################################
    // unit tests for gender class
    static void UnitTestIsMale(const Gender &g, const bool b)
    {
        assert(IsMale(g) == b);
        cout << "Success in IsMale unit testing" << endl;
    }
    static void UnitTestIsFemale(const Gender &g, const bool b)
    {
        assert(IsFemale(g) == b);
        cout << "Success in IsFemale unit testing" << endl;
    }
    // ###################################################################################
    // typedefs to ease the writing of code and giving proper namespaces
    typedef GenderTypes<MaleType> Male;
    typedef GenderTypes<FemaleType> Female;
};

// Template for concrete gender singleton object
template <typename T>
class GenderTypes : public Gender
{
    static const string sName;      // name of gender
    static const string sSalutation;    // salutation of gender
    // hidden constructor
    GenderTypes(const string &name = GenderTypes<T>::sName) : Gender(name) {}
    ~GenderTypes() {}

public:
    // create a static object of respective type so it saves memory as only
    // one instance is availabel all the tiem
    static const GenderTypes<T> &Type()
    {
        static const GenderTypes<T> theObject;
        return theObject;
    }
    // return the salutaion for the gender
    const string GetTitle() const
    {
        return GenderTypes<T>::sSalutation;
    }
    static int a;
};
// implementation of the functions
inline bool Gender::IsMale(const Gender &g) { return &g == &Gender::Male::Type(); }
inline bool Gender::IsFemale(const Gender &g) { return &g == &Gender::Female::Type(); }

// Initialization of static variables

// Names defined as static constants
template <>
const string Gender::Male::sName = "Male";
template <>
const string Gender::Female::sName = "Female";
// Salutations defined as static constants
template <>
const string Gender::Male::sSalutation = "Mr.";
template <>
const string Gender::Female::sSalutation = "Ms.";
#endif