#include "Booking.h"
#include <iostream>

using namespace std;

Booking::Booking() {
    bookingId = 0;
    passengerId = 0;
    rideId = 0;
    status = "Pending";
}

Booking::Booking(int id, int passenger, int ride) {
    bookingId = id;
    passengerId = passenger;
    rideId = ride;
    status = "Pending";
}

int Booking::getBookingId() const {
    return bookingId;
}

int Booking::getPassengerId() const {
    return passengerId;
}

int Booking::getRideId() const {
    return rideId;
}

string Booking::getStatus() const {
    return status;
}

void Booking::confirmBooking() {
    status = "Confirmed";
}

void Booking::displayBooking() const {
    cout << "\nBooking ID: " << bookingId << endl;
    cout << "Passenger ID: " << passengerId << endl;
    cout << "Ride ID: " << rideId << endl;
    cout << "Status: " << status << endl;
}