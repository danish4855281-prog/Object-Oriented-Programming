#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
private:
    int numSeats;

public:
    Car(const string& model, double dailyRate, int numSeats);

    int    getNumSeats()              const;
    double calculateCost(int days)    const override;
    string getType()                  const override;
};
