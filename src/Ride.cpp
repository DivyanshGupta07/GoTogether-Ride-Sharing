#include "Ride.h"
#include <iostream>

using namespace std;

Ride::Ride() {
    rideId = 0;
    driverId = 0;
    source = "";
    destination = "";
    travelTime = "";
    totalSeats = 0;
    availableSeats = 0;
}

Ride::Ride(int id, int driver, string from, string to,
           string time, int seats) {

    rideId = id;
    driverId = driver;
    source = from;
    destination = to;
    travelTime = time;
    totalSeats = seats;
    availableSeats = seats;
}

int Ride::getRideId() const {
    return rideId;
}

int Ride::getDriverId() const {
    return driverId;
}

string Ride::getSource() const {
    return source;
}

string Ride::getDestination() const {
    return destination;
}

string Ride::getTravelTime() const {
    return travelTime;
}

int Ride::getAvailableSeats() const {
    return availableSeats;
}

bool Ride::bookSeat() {
    if (availableSeats > 0) {
        availableSeats--;
        return true;
    }

    return false;
}

void Ride::displayRide() const {
    cout << "\nRide ID: " << rideId << endl;
    cout << "Driver ID: " << driverId << endl;
    cout << "From: " << source << endl;
    cout << "To: " << destination << endl;
    cout << "Travel Time: " << travelTime << endl;
    cout << "Available Seats: " << availableSeats
         << "/" << totalSeats << endl;
}