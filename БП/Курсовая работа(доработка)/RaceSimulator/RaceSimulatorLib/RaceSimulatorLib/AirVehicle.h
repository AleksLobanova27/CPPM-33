#pragma once
#include "Vehicle.h"

class MagicCarpet : public Vehicle {
public:
    MagicCarpet();
    double calculateTime(double distance) const override;
};

class Eagle : public Vehicle {
public:
    Eagle();
    double calculateTime(double distance) const override;
};

class Broom : public Vehicle {
public:
    Broom();
    double calculateTime(double distance) const override;
};