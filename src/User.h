#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    int userId;
    string name;
    string phone;

public:
    User();
    User(int id, string userName, string userPhone);

    int getUserId() const;
    string getName() const;
    string getPhone() const;

    void displayUser() const;
};

#endif