#include "Vehicle.h"

Vehicle::Vehicle(const string& model, double dailyRate)
    : model(model), dailyRate(dailyRate), available(true) {}

string Vehicle::getModel()     const { return model; }
double Vehicle::getDailyRate() const { return dailyRate; }
bool   Vehicle::isAvailable()  const { return available; }

void Vehicle::setAvailable(bool status) { available = status; }
