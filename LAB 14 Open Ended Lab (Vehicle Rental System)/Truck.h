#pragma once
#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double payloadCapacity;   // tonnes

public:
    Truck(const string& model, double dailyRate, double payloadCapacity);

    double getPayloadCapacity()        const;
    double calculateCost(int days)     const override;
    string getType()                   const override;
};
