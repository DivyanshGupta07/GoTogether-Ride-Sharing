#ifndef BOOKING_H
#define BOOKING_H

#include <string>
using namespace std;

class Booking {
private:
    int bookingId;
    int passengerId;
    int rideId;
    string status;

public:
    Booking();
    Booking(int id, int passenger, int ride);

    int getBookingId() const;
    int getPassengerId() const;
    int getRideId() const;
    string getStatus() const;

    void confirmBooking();
    void displayBooking() const;
};

#endif