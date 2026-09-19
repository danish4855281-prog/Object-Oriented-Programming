#pragma once
#include <vector>
#include <string>
#include "Vehicle.h"
#include "Customer.h"
#include "Rental.h"
using namespace std;

class RentalSystem {
private:
    vector<Vehicle*>  vehicles;    // aggregated — not owned
    vector<Customer*> customers;   // aggregated — not owned
    vector<Rental*>   rentals;     // composed   — owned

    Vehicle*  findVehicle(const string& model) const;
    Customer* findCustomer(int customerID)     const;

public:
    RentalSystem() = default;
    ~RentalSystem();   // deletes only composed Rental* objects

    void addVehicle(Vehicle* v);
    void addCustomer(Customer* c);

    void rentVehicle(int customerID, const string& vehicleModel, int days);
    void returnVehicle(int customerID, const string& vehicleModel);

    void printSummary() const;
};
