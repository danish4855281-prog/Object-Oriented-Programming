#include "Customer.h"

Customer::Customer(const string& name, int customerID)
    : name(name), customerID(customerID), hasActiveRental(false) {}

string Customer::getName()            const { return name; }
int    Customer::getCustomerID()      const { return customerID; }
bool   Customer::getHasActiveRental() const { return hasActiveRental; }

void Customer::setHasActiveRental(bool status) { hasActiveRental = status; }
