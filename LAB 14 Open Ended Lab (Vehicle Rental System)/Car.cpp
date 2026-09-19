#include "Car.h"

Car::Car(const string& model, double dailyRate, int numSeats)
    : Vehicle(model, dailyRate), numSeats(numSeats) {}

int Car::getNumSeats() const { return numSeats; }

// Pricing: no surcharge, no discount
double Car::calculateCost(int days) const {
    return getDailyRate() * days;
}

string Car::getType() const { return "Car"; }
