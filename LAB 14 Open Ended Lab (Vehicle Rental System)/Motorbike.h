#pragma once
#include "Vehicle.h"

class Motorbike : public Vehicle {
private:
    int engineCC;

public:
    Motorbike(const string& model, double dailyRate, int engineCC);

    int    getEngineCC()               const;
    double calculateCost(int days)     const override;
    string getType()                   const override;
};
