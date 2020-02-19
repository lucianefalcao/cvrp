#ifndef VEHICLE_H
#define VEHICLE_H

#include <vector>
#include <iostream>

#include "client.h"

// Talvez tornar route um vetor de referências

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
    void setCarga();
    void calculateCarga(int carga);
    void printRoute();

    int getCapacity();
    int getCurrentLocation();

    bool fits(int demand);
};


#endif