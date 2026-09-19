#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
    string model;
    double dailyRate;
    bool   available;

public:
    Vehicle(const string& model, double dailyRate);
    virtual ~Vehicle() = default;

    string getModel()     const;
    double getDailyRate() const;
    bool   isAvailable()  const;
    void   setAvailable(bool status);

    virtual double calculateCost(int days) const = 0;
    virtual string getType() const = 0;
};
