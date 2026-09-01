#include "User.h"
#include <iostream>

using namespace std;

User::User() {
    userId = 0;
    name = "";
    phone = "";
}

User::User(int id, string userName, string userPhone) {
    userId = id;
    name = userName;
    phone = userPhone;
}

int User::getUserId() const {
    return userId;
}

string User::getName() const {
    return name;
}

string User::getPhone() const {
    return phone;
}

void User::displayUser() const {
    cout << "User ID: " << userId << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
}