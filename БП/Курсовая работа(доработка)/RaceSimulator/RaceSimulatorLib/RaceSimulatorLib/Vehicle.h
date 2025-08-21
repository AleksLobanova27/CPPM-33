#pragma once
#include <string>
#include <vector>

class Vehicle {
protected:
    std::string name;
    double speed;
    bool isGround;

public:
    Vehicle(const std::string& name, double speed, bool isGround);
    virtual ~Vehicle() = default;

    virtual double calculateTime(double distance) const = 0;

    std::string getName() const;
    double getSpeed() const;
    bool getIsGround() const;
};