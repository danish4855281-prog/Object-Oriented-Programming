#include "Truck.h"

Truck::Truck(const string& model, double dailyRate, double payloadCapacity)
    : Vehicle(model, dailyRate), payloadCapacity(payloadCapacity) {}

double Truck::getPayloadCapacity() const { return payloadCapacity; }

// Pricing: +20% surcharge
double Truck::calculateCost(int days) const {
    return getDailyRate() * days * 1.20;
}

string Truck::getType() const { return "Truck"; }
