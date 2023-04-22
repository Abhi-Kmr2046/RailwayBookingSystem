#ifndef __BOOKING
#define __BOOKING
#include <string>
#include <vector>

#include <string.h>
#include <assert.h>
#include <cmath>

#include "date.hpp"
#include "gender.hpp"
#include "Passenger.hpp"
#include "exceptions.hpp"
#include "railways.hpp"
#include "station.hpp"
#include "BookingClass.hpp"
#include "bookingcategory.hpp"
#include "tatkal.hpp"
// const Date Date::Today = Date::isValidDate("09/04/2021");

using namespace std;

// Booking class to store information about one booking
class Booking
{
private:
    const int PNR_;    // PNR to uniquily identify a booking
    double baseFare_;  // base fare
    double finalFare_; // final fare

    bool bookingStatus_; // booking status of ticket

    const Station fromStation_;
    const Station toStation_;
    const Date traveldate_;
    const BookingClass &bClass_;       // reference of the singleton object of any of the Booking Class
    const BookingCategory &bCategory_; // reference of the singleton object of any of the Booking Category

    const Passenger passenger_;        // A passenger object
    static int sPNR;                   // count of number of tickets booked
    static const double sBaseFareRate; // base Fare rate for the fare calculation


    // hiddent constructor
    Booking(
        const Station &from,
        const Station &to,
        const Date &date,
        const BookingClass &bClass,
        const BookingCategory &bCat,
        const Passenger &pas,
        const int PNR,
        const double baseFare,
        const double finalFare,
        const bool bookingstatus);
    Booking &
    operator=(const Booking &) { return *this; }

public:
    static vector<Booking> sBookingList; // vector of all the booking
    // Static BookTictet function which return a booking object is ll the information provides is valid
    static const Booking BookTicket(const Station &from, const Station &to, const Date &date, const BookingClass &bClass, const BookingCategory &bCat, const Passenger &pas);
    // Printing the booking info
    friend ostream &operator<<(ostream &os, const Booking &f);
    // Unit Test for Booking
    static void UnitTest(const Station &from, const Station &to, const Date &date, const BookingClass &bClass, const BookingCategory &bCat, const Passenger &pas, const double fare);

    ~Booking() {}
};

// Implementaion of Booking constructor
Booking::Booking(
    const Station &from,
    const Station &to,
    const Date &date,
    const BookingClass &bClass,
    const BookingCategory &bCat,
    const Passenger &pas,
    const int PNR,
    const double baseFare,
    const double finalFare,
    const bool bookingstatus) : fromStation_(from),
                                toStation_(to),
                                traveldate_(date),
                                bClass_(bClass),
                                bCategory_(bCat),
                                passenger_(pas),
                                PNR_(PNR),
                                baseFare_(baseFare),
                                finalFare_(finalFare),
                                bookingStatus_(bookingstatus)

{
}

// implementation of bookticket function
const Booking Booking::BookTicket(
    const Station &from,

    const Station &to,
    const Date &date,
    const BookingClass &bClass,
    const BookingCategory &bCat,
    const Passenger &pas)
{
    try
    {
        // travel date is not more than one year ahead and is not in past

        if ((Date::getDifference(Date::Today, date) > 365) || Date::getDifference(Date::Today, date) < 0)
        {

        cout << Date::getDifference(Date::Today, date) << endl;
            throw Bad_BookingDate();
        }
        // From station and to station canot be same
        if (from == to)
        {
            throw Bad_BookingStaion();
        }

        // initializing the singleton objects
        Railways::IndianRailways();
        TatkalCharges::Charges();

        double distance = Railways::IndianRailways().getDistacne(from, to);
        double base = sBaseFareRate * distance;
        double fare = base * bClass.getLoadFactor(); // getLoadFactor will return the loadfactor of bClass
        double concessionalFare = fare * (1 - bCat.getConcession(bClass.getName()));

        double tatkalCharge = 0;
        // Calcuation of tatkal charges based on the conditions
        if (Normal::isTatkal(bCat))
        {
            // Tatkal applies only when distance is greater than minDIs
            if (distance >= TatkalCharges::Charges().getCharge(bClass.getName(), "minDis"))
            {
                double t1 = TatkalCharges::Charges().getFarePercent(bClass.getName()) * concessionalFare / 100;
                // appluing condition given for tatkal
                if (t1 >= TatkalCharges::Charges().getCharge(bClass.getName(), "minCharges"))
                {
                    if (t1 >= TatkalCharges::Charges().getCharge(bClass.getName(), "maxCharges"))
                    {
                        tatkalCharge = TatkalCharges::Charges().getCharge(bClass.getName(), "maxCharges");
                    }
                    else
                    {
                        tatkalCharge = t1;
                    }
                }
            }
        }
        // Calcuation of Premiumtatkal charges based on the conditions
        else if (Normal::isPremiumTatkal(bCat))
        {
            // PremiumTatkal applies only when distance is greater than minDIs

            if (distance >= TatkalCharges::Charges().getCharge(bClass.getName(), "minDis"))
            {
                double t1 = 2 * TatkalCharges::Charges().getFarePercent(bClass.getName()) * concessionalFare / 100;
                if (t1 >= 2 * TatkalCharges::Charges().getCharge(bClass.getName(), "minCharges"))
                {
                    // appluing condition given for Premiumtatkal

                    if (t1 >= 2 * TatkalCharges::Charges().getCharge(bClass.getName(), "maxCharges"))
                    {
                        tatkalCharge = 2 * TatkalCharges::Charges().getCharge(bClass.getName(), "maxCharges");
                    }
                    else
                    {
                        tatkalCharge = t1;
                    }
                }
            }
        }
        // cout << tatkalCharge << endl;

        double finalFare = concessionalFare + tatkalCharge + bClass.getReservationCharge();
        // cout << finalFare << endl;
        int PNR = ++Booking::sPNR; // sPNR is increased  and alloted to PNR for particular booking
        Booking b = Booking(from, to, date, bClass, bCat, pas, PNR, round(base), round(finalFare), true);
        // cout << finalFare<<endl;
        sBookingList.push_back(b);
        return b;
    }
    catch (const Bad_Booking &e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }
}
// print booking information on console
ostream &operator<<(ostream &os, const Booking &f)
{
    os << "Booking: " << f.PNR_ << " "
       << "\n";
    os << "From Station: " << f.fromStation_ << "\n";
    os << "To Station: " << f.toStation_ << "\n";
    os << "Travel Date: " << f.traveldate_ << "\n";
    os << "Fare: " << f.finalFare_ << "\n";
    os << "Booking Class: " << f.bClass_ << "\n";
    os << "Booking Category: " << f.bCategory_ << "\n";
    os << "Passenger: \n"
       << f.passenger_ << "\n";

    os << "-----------------------------------\n";

    return os;
}
// ###################################################################################
// Unit Test for Booking
void Booking::UnitTest(const Station &from, const Station &to, const Date &date, const BookingClass &bClass, const BookingCategory &bCat, const Passenger &pas, const double fare)
{
    try
    {
        Booking b = Booking::BookTicket(from, to, date, bClass, bCat, pas);
        assert(fare == b.finalFare_);
        cout << "Unit Test for Booking Successful" << endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
}
// ###################################################################################

int Booking::sPNR = 0;                     // count of number of tickets booked
const double Booking::sBaseFareRate = 0.5; // base fare rate

vector<Booking>
    Booking::sBookingList; // initializing to store list of all the bookings

#endif