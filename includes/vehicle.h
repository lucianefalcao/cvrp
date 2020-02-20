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
    int load;
    int cost;
    std::vector<Client> route;

public:
    Vehicle();

    void setCurrentLocation(int currentLocation);
    void setCapacity(int capacity);
    void addClientToRoute(Client client);
    void setLoad();
    void setCost(int cost);
    void calculateLoad(int load);
    void printRoute(std::vector<Vehicle*> v);

    int getCapacity();
    int getCurrentLocation();
    int getCost();

    bool CheckDelivery(int demand);

    std::vector<Client> getRoute();
};


#endif