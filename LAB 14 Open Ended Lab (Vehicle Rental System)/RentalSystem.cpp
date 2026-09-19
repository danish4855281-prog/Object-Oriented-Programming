#include "RentalSystem.h"
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Only delete COMPOSED rentals — vehicles/customers not owned
RentalSystem::~RentalSystem() {
    for (Rental* r : rentals) delete r;
}

void RentalSystem::addVehicle(Vehicle* v)   { vehicles.push_back(v); }
void RentalSystem::addCustomer(Customer* c) { customers.push_back(c); }

Vehicle* RentalSystem::findVehicle(const string& model) const {
    for (Vehicle* v : vehicles)
        if (v->getModel() == model) return v;
    return nullptr;
}

Customer* RentalSystem::findCustomer(int id) const {
    for (Customer* c : customers)
        if (c->getCustomerID() == id) return c;
    return nullptr;
}

void RentalSystem::rentVehicle(int customerID,
                                const string& vehicleModel,
                                int days) {
    Customer* cust = findCustomer(customerID);
    if (!cust)
        throw runtime_error("Customer ID " + to_string(customerID) + " not found.");

    if (cust->getHasActiveRental())
        throw runtime_error(cust->getName() + " already has an active rental.");

    Vehicle* veh = findVehicle(vehicleModel);
    if (!veh)
        throw runtime_error("Vehicle \"" + vehicleModel + "\" not found.");

    if (!veh->isAvailable())
        throw runtime_error("\"" + vehicleModel + "\" is currently rented out.");

    // COMPOSITION: RentalSystem creates and owns this Rental
    Rental* rental = new Rental(cust, veh, days);
    rentals.push_back(rental);

    veh->setAvailable(false);
    cust->setHasActiveRental(true);

    cout << fixed << setprecision(2);
    cout << "[RENTED]   " << cust->getName()
         << " rented " << veh->getType()
         << " \"" << veh->getModel() << "\""
         << " for " << days << " day(s)."
         << "  Cost: PKR " << rental->getCost() << "\n";
}

void RentalSystem::returnVehicle(int customerID,
                                  const string& vehicleModel) {
    Customer* cust = findCustomer(customerID);
    if (!cust)
        throw runtime_error("Customer ID " + to_string(customerID) + " not found.");

    for (Rental* r : rentals) {
        if (r->isActive()
            && r->getCustomer() == cust
            && r->getVehicle()->getModel() == vehicleModel) {

            r->closeRental();                     // mark closed, not deleted
            r->getVehicle()->setAvailable(true);
            cust->setHasActiveRental(false);

            cout << "[RETURNED] " << cust->getName()
                 << " returned \"" << vehicleModel << "\".\n";
            return;
        }
    }
    throw runtime_error("No active rental found for \""
                        + vehicleModel + "\".");
}

void RentalSystem::printSummary() const {
    cout << fixed << setprecision(2);
    cout << "\n============================================\n";
    cout << "       VEHICLE RENTAL SYSTEM SUMMARY\n";
    cout << "============================================\n";

    cout << "\n[Active Rentals]\n";
    bool anyActive = false;
    for (const Rental* r : rentals) {
        if (r->isActive()) {
            anyActive = true;
            cout << "  Customer : " << r->getCustomer()->getName()
                 << " (ID: " << r->getCustomer()->getCustomerID() << ")\n"
                 << "  Vehicle  : " << r->getVehicle()->getType()
                 << " - " << r->getVehicle()->getModel() << "\n"
                 << "  Days     : " << r->getDays() << "\n"
                 << "  Cost     : PKR " << r->getCost() << "\n"
                 << "  ----------\n";
        }
    }
    if (!anyActive) cout << "  (No active rentals)\n";

    cout << "\n[Closed Rentals — History]\n";
    bool anyClosed = false;
    for (const Rental* r : rentals) {
        if (!r->isActive()) {
            anyClosed = true;
            cout << "  " << r->getCustomer()->getName()
                 << " | " << r->getVehicle()->getModel()
                 << " | " << r->getDays() << " days"
                 << " | PKR " << r->getCost() << " [CLOSED]\n";
        }
    }
    if (!anyClosed) cout << "  (No closed rentals)\n";

    int available = 0, rented = 0;
    for (const Vehicle* v : vehicles) {
        if (v->isAvailable()) ++available;
        else                  ++rented;
    }

    cout << "\n[Fleet Status]\n";
    cout << "  Total Vehicles : " << vehicles.size() << "\n";
    cout << "  Available      : " << available << "\n";
    cout << "  Rented         : " << rented << "\n";
    cout << "============================================\n\n";
}
