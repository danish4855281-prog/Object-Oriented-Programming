#include "Motorbike.h"

Motorbike::Motorbike(const string& model, double dailyRate, int engineCC)
    : Vehicle(model, dailyRate), engineCC(engineCC) {}

int Motorbike::getEngineCC() const { return engineCC; }

// Pricing: 10% discount if days > 7
double Motorbike::calculateCost(int days) const {
    double cost = getDailyRate() * days;
    if (days > 7) cost *= 0.90;
    return cost;
}

string Motorbike::getType() const { return "Motorbike"; }
