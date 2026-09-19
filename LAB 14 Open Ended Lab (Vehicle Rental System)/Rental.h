#pragma once
#include "Vehicle.h"
#include "Customer.h"

class Rental {
private:
    Customer* customer;   // aggregated — not owned
    Vehicle*  vehicle;    // aggregated — not owned
    int       days;
    double    cost;
    bool      active;

public:
    Rental(Customer* customer, Vehicle* vehicle, int days);

    Customer* getCustomer() const;
    Vehicle*  getVehicle()  const;
    int       getDays()     const;
    double    getCost()     const;
    bool      isActive()    const;

    void closeRental();   // mark closed, do NOT delete
};
