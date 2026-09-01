#include <iostream>
#include <vector>
#include <limits>
#include "User.h"
#include "Ride.h"
#include "Booking.h"

using namespace std;

void showHeader() {
    cout << "\n";
    cout << "====================================================\n";
    cout << "           GOTOGHER - RIDE SHARING SYSTEM           \n";
    cout << "====================================================\n";
}

void showMenu() {
    cout << "\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|                 MAIN MENU                        |\n";
    cout << "+--------------------------------------------------+\n";
    cout << "|  1. View Available Rides                         |\n";
    cout << "|  2. Search & Match Ride                          |\n";
    cout << "|  3. Book a Ride                                  |\n";
    cout << "|  4. View User Profile                            |\n";
    cout << "|  5. View Booking                                 |\n";
    cout << "|  6. Exit                                         |\n";
    cout << "+--------------------------------------------------+\n";
    cout << " Enter your choice: ";
}

void viewRides(const vector<Ride>& rides) {
    cout << "\n";
    cout << "================ AVAILABLE RIDES ==================\n";

    bool found = false;

    for (const Ride& ride : rides) {
        if (ride.getAvailableSeats() > 0) {
            ride.displayRide();
            cout << "----------------------------------------------------\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No rides are currently available.\n";
    }
}

int findMatchingRide(
    const vector<Ride>& rides,
    const string& source,
    const string& destination
) {
    for (int i = 0; i < (int)rides.size(); i++) {
        if (rides[i].getSource() == source &&
            rides[i].getDestination() == destination &&
            rides[i].getAvailableSeats() > 0) {

            return i;
        }
    }

    return -1;
}

int main() {

    // -----------------------------------------
    // Sample Users
    // -----------------------------------------
    User driver(101, "Kartik", "9876543210");
    User passenger(201, "Divyansh", "9876501234");

    // -----------------------------------------
    // Sample Rides
    // -----------------------------------------
    vector<Ride> rides;

    rides.push_back(
        Ride(
            1,
            driver.getUserId(),
            "Delhi",
            "Noida",
            "09:00 AM",
            3
        )
    );

    rides.push_back(
        Ride(
            2,
            driver.getUserId(),
            "Delhi",
            "Gurgaon",
            "10:30 AM",
            2
        )
    );

    rides.push_back(
        Ride(
            3,
            driver.getUserId(),
            "Noida",
            "Greater Noida",
            "12:00 PM",
            3
        )
    );

    // -----------------------------------------
    // Booking storage
    // -----------------------------------------
    vector<Booking> bookings;

    int bookingCounter = 5001;
    int choice;

    showHeader();

    cout << "\nWelcome to GoTogether!\n";
    cout << "Smart and simple ride sharing for everyone.\n";

    // -----------------------------------------
    // Main Menu Loop
    // -----------------------------------------
    do {

        showMenu();

        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(
                numeric_limits<streamsize>::max(),
                '\n'
            );

            cout << "\nInvalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {

        // -----------------------------------------
        // OPTION 1
        // -----------------------------------------
        case 1:

            showHeader();
            viewRides(rides);

            break;

        // -----------------------------------------
        // OPTION 2
        // -----------------------------------------
        case 2: {

            showHeader();

            string source;
            string destination;

            cout << "\nEnter Source: ";
            cin >> source;

            cout << "Enter Destination: ";
            cin >> destination;

            int index = findMatchingRide(
                rides,
                source,
                destination
            );

            cout << "\n";

            if (index != -1) {

                cout << "******** MATCH FOUND ********\n";
                rides[index].displayRide();
                cout << "******************************\n";

            } else {

                cout << "No matching ride found.\n";
                cout << "Please try another route.\n";
            }

            break;
        }

        // -----------------------------------------
        // OPTION 3
        // -----------------------------------------
        case 3: {

            showHeader();

            string source;
            string destination;

            cout << "\nEnter Source: ";
            cin >> source;

            cout << "Enter Destination: ";
            cin >> destination;

            int index = findMatchingRide(
                rides,
                source,
                destination
            );

            if (index == -1) {

                cout << "\nNo suitable ride available.\n";

            } else {

                cout << "\nMatching Ride:\n";
                rides[index].displayRide();

                cout << "\nDo you want to book this ride? (1 = Yes, 0 = No): ";

                int confirm;
                cin >> confirm;

                if (confirm == 1) {

                    if (rides[index].bookSeat()) {

                        Booking newBooking(
                            bookingCounter++,
                            passenger.getUserId(),
                            rides[index].getRideId()
                        );

                        newBooking.confirmBooking();

                        bookings.push_back(newBooking);

                        cout << "\n";
                        cout << "+------------------------------------------+\n";
                        cout << "|       BOOKING SUCCESSFUL                 |\n";
                        cout << "+------------------------------------------+\n";

                        cout << "Booking ID: "
                             << newBooking.getBookingId()
                             << "\n";

                        cout << "Passenger: "
                             << passenger.getName()
                             << "\n";

                        cout << "Ride ID: "
                             << rides[index].getRideId()
                             << "\n";

                        cout << "Status: Confirmed\n";

                        cout << "+------------------------------------------+\n";

                        cout << "\nUpdated Ride:\n";
                        rides[index].displayRide();

                    } else {

                        cout << "\nSorry! No seats available.\n";
                    }

                } else {

                    cout << "\nBooking cancelled.\n";
                }
            }

            break;
        }

        // -----------------------------------------
        // OPTION 4
        // -----------------------------------------
        case 4:

            showHeader();

            cout << "\nPASSENGER PROFILE\n";
            cout << "-----------------------------\n";

            passenger.displayUser();

            cout << "-----------------------------\n";

            break;

        // -----------------------------------------
        // OPTION 5
        // -----------------------------------------
        case 5:

            showHeader();

            if (bookings.empty()) {

                cout << "\nNo bookings found.\n";

            } else {

                cout << "\nYOUR BOOKINGS\n";
                cout << "=============================\n";

                for (const Booking& booking : bookings) {

                    booking.displayBooking();

                    cout << "-----------------------------\n";
                }
            }

            break;

        // -----------------------------------------
        // OPTION 6
        // -----------------------------------------
        case 6:

            cout << "\n";
            cout << "====================================================\n";
            cout << "       Thank you for using GoTogether!             \n";
            cout << "       Safe Journey!                                \n";
            cout << "====================================================\n";

            break;

        // -----------------------------------------
        // INVALID OPTION
        // -----------------------------------------
        default:

            cout << "\nInvalid choice!\n";
            cout << "Please select an option from 1 to 6.\n";
        }

    } while (choice != 6);

    return 0;
}