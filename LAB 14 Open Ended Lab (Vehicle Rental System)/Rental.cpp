#include "Rental.h"

// Cost locked at construction via runtime polymorphism
Rental::Rental(Customer* customer, Vehicle* vehicle, int days)
    : customer(customer), vehicle(vehicle),
      days(days), active(true) {
    cost = vehicle->calculateCost(days);   // polymorphic call
}

Customer* Rental::getCustomer() const { return customer; }
Vehicle*  Rental::getVehicle()  const { return vehicle; }
int       Rental::getDays()     const { return days; }
double    Rental::getCost()     const { return cost; }
bool      Rental::isActive()    const { return active; }

void Rental::closeRental() { active = false; }
