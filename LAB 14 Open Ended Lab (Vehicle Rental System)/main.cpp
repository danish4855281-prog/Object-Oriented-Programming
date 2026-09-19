#include <iostream>
#include "Car.h"
#include "Truck.h"
#include "Motorbike.h"
#include "Customer.h"
#include "RentalSystem.h"
using namespace std;

int main() {
    // Vehicles created on stack — passed to system (Aggregation)
    Car       car1("Toyota Corolla", 5000.0, 5);
    Motorbike mb1 ("Honda CB150",    1500.0, 150);
    Truck     tr1 ("Isuzu NPR",      8000.0, 3.5);

    // Customers created on stack — passed to system (Aggregation)
    Customer cust1("Ali Khan",   101);
    Customer cust2("Sara Ahmed", 102);

    RentalSystem system;

    system.addVehicle(&car1);
    system.addVehicle(&mb1);
    system.addVehicle(&tr1);

    system.addCustomer(&cust1);
    system.addCustomer(&cust2);

    cout << "\n======= Vehicle Rental System =======\n\n";

    // Rental 1 — Car, 3 days ? PKR 15,000
    system.rentVehicle(101, "Toyota Corolla", 3);

    // Rental 2 — Motorbike, 10 days ? PKR 13,500 (10% discount)
    system.rentVehicle(102, "Honda CB150", 10);

    // Error: Ali already has active rental
    try {
        system.rentVehicle(101, "Isuzu NPR", 5);
    } catch (const exception& e) {
        cout << "[BLOCKED]  " << e.what() << "\n";
    }

    // Error: Honda CB150 already rented
    try {
        system.rentVehicle(102, "Honda CB150", 2);
    } catch (const exception& e) {
        cout << "[BLOCKED]  " << e.what() << "\n";
    }

    // Return — Ali returns Car (record closed, not deleted)
    system.returnVehicle(101, "Toyota Corolla");

    // Summary
    system.printSummary();

    return 0;
}
