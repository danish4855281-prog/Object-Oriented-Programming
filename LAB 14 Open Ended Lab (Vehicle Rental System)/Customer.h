#pragma once
#include <string>
using namespace std;

class Customer {
private:
    string name;
    int    customerID;
    bool   hasActiveRental;

public:
    Customer(const string& name, int customerID);

    string getName()            const;
    int    getCustomerID()      const;
    bool   getHasActiveRental() const;
    void   setHasActiveRental(bool status);
};
