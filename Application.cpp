#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <exception>
#include "header/date.hpp"
#include "header/gender.hpp"
#include "header/railways.hpp"
#include "header/station.hpp"
#include "header/passenger.hpp"
#include "header/BookingClass.hpp"
#include "header/bookingcategory.hpp"
#include "header/divyangconcession.hpp"
#include "header/Booking.hpp"
#include <bits/stdc++.h>

using namespace std;
const Date Date::Today = Date::isValidDate("09/04/2021");
const string Railways::path = "station.txt";

void BookingApplication()
{

    // Initisialising all the passengers

    Passenger p1 = Passenger::isValidPassenger(Name::isValidName("Abhishek", "", "Sah"), Date::isValidDate("05/06/2000"), Gender::Male::Type(), "842233101212", "6261171632", "Blind", "12345");
    Passenger p2 = Passenger::isValidPassenger(Name::isValidName("Abcd", "", "Raj"), Date::isValidDate("05/06/2000"), Gender::Female::Type(), "842233101212", "6261171632", "Cancer", "12345");
    Passenger p3 = Passenger::isValidPassenger(Name::isValidName("Raunak", "Ravi", "Kishore"), Date::isValidDate("05/06/2000"), Gender::Male::Type(), "842233101212", "6261171632", "TB", "12345");
    Passenger p4 = Passenger::isValidPassenger(Name::isValidName("Kishore", "Raunak", ""), Date::isValidDate("05/06/2000"), Gender::Female::Type(), "842233101212", "6261171632", "Orthopedic", "12345");
    Passenger p5 = Passenger::isValidPassenger(Name::isValidName("", "Ram", "Raj"), Date::isValidDate("05/06/2000"), Gender::Male::Type(), "842233101212", "6261171632");

    Booking b1 = Booking::BookTicket(Station::createStation("Delhi"), Station::createStation("Mumbai"), Date::isValidDate("24/05/2021"), BookingClass::ACFirstClass::Type(), Divyang::Blind::Type(), p1);

    Booking b2 = Booking::BookTicket(Station::createStation("Mumbai"), Station::createStation("Delhi"), Date::isValidDate("24/05/2021"), BookingClass::ExecutiveChairCar::Type(), Divyang::Blind::Type(), p1);

    Booking b3 = Booking::BookTicket(Station::createStation("Kolkata"), Station::createStation("Banglore"), Date::isValidDate("24/05/2021"), BookingClass::ACFirstClass::Type(), Divyang::Cancer::Type(), p2);

    Booking b4 = Booking::BookTicket(Station::createStation("Banglore"), Station::createStation("Kolkata"), Date::isValidDate("24/05/2021"), BookingClass::ACFirstClass::Type(), Divyang::TB::Type(), p3);

    Booking b5 = Booking::BookTicket(Station::createStation("Chennai"), Station::createStation("Delhi"), Date::isValidDate("24/05/2021"), BookingClass::ACChairCar::Type(), Divyang::Orthopedic::Type(), p4);

    Booking b6 = Booking::BookTicket(Station::createStation("Delhi"), Station::createStation("Chennai"), Date::isValidDate("24/05/2021"), BookingClass::SecondSitting::Type(), Normal::General::Type(), p5);

    Booking b7 = Booking::BookTicket(Station::createStation("Delhi"), Station::createStation("Mumbai"), Date::isValidDate("24/05/2021"), BookingClass::Sleeper::Type(), Normal::SeniorCitizenF::Type(), p5);

    Booking b8 = Booking::BookTicket(Station::createStation("Mumbai"), Station::createStation("Chennai"), Date::isValidDate("24/05/2021"), BookingClass::ExecutiveChairCar::Type(), Normal::SeniorCitizenM::Type(), p5);

    Booking b9 = Booking::BookTicket(Station::createStation("Chennai"), Station::createStation("Mumbai"), Date::isValidDate("24/05/2021"), BookingClass::ACChairCar::Type(), Normal::Tatkal::Type(), p5);
    Booking b10 = Booking::BookTicket(Station::createStation("Delhi"), Station::createStation("Kolkata"), Date::isValidDate("24/05/2021"), BookingClass::AC3Tier::Type(), Normal::PremiumTatkal::Type(), p5);

    Booking b11 = Booking::BookTicket(Station::createStation("Kolkata"), Station::createStation("Delhi"), Date::isValidDate("24/05/2021"), BookingClass::AC2Tier::Type(), Normal::Ladies::Type(), p5);

    for (auto it = Booking::sBookingList.begin(); it < Booking::sBookingList.end(); ++it)
    {
        cout << (*it) << endl;
    }
}

int main()
{

    BookingApplication();
    return 0;
}