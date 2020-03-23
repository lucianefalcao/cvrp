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
    int load;
    int cost;
    std::vector<Client> route;

public:
    Vehicle();

    void setCapacity(int capacity);
    void setLoad(int);
    void setRoute(std::vector<Client>);
    void setCost(int cost);
    void addClientToRoute(Client client);
    void addCost(int);
    void calculateLoad(int load);

    int getCapacity();
    int getCost();
    int getLoad();

    bool CheckDelivery(int demand);

    std::vector<Client> getRoute();
};


#endif