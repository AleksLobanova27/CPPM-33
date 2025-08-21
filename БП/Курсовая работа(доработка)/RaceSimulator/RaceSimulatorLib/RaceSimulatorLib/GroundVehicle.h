#pragma once
#include "Vehicle.h"

class Camel : public Vehicle {
public:
    Camel();
    double calculateTime(double distance) const override;
};

class FastCamel : public Vehicle {
public:
    FastCamel();
    double calculateTime(double distance) const override;
};

class Centaur : public Vehicle {
public:
    Centaur();
    double calculateTime(double distance) const override;
};

class AllTerrainBoots : public Vehicle {
public:
    AllTerrainBoots();
    double calculateTime(double distance) const override;
};