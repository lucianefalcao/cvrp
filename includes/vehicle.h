#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>

#include "client.h"

class Vehicle
{
private:
    int capacity;
    int currentLocation;
    int carga;

    std::vector<Client> route;

public:
    Vehicle();

    void setCurrentLocation(int currentLocation);
    void setCapacity(int capacity);
    void addClientToRoute(Client client);
    void setCarga(int carga);

    int getCapacity();
    int getCurrentLocation();

    bool fits(int demand);
};


#endif