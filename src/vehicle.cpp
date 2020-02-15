#include "../includes/vehicle.h"

Vehicle::Vehicle(int capacity)
{
    this->capacity = capacity;
}

int Vehicle::getCapacity()
{
    return capacity;
}