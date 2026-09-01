#ifndef RIDE_H
#define RIDE_H

#include <string>
using namespace std;

class Ride {
private:
    int rideId;
    int driverId;
    string source;
    string destination;
    string travelTime;
    int totalSeats;
    int availableSeats;

public:
    Ride();
    Ride(int id, int driver, string from, string to,
         string time, int seats);

    int getRideId() const;
    int getDriverId() const;
    string getSource() const;
    string getDestination() const;
    string getTravelTime() const;
    int getAvailableSeats() const;

    bool bookSeat();
    void displayRide() const;
};

#endif