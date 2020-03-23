#include "../includes/vehicle.h"


Vehicle::Vehicle()
{ 
    this->cost = 0;
}

void Vehicle::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Vehicle::getCapacity()
{
    return capacity;
}

void Vehicle::addClientToRoute(Client client)
{
    this->route.push_back(client);
}

void Vehicle::setLoad(int capacity)
{
    this->load = capacity;
}

int Vehicle::getLoad()
{
    return load;
}

void Vehicle::calculateLoad(int load)
{
    this->load -= load;
}

void Vehicle::setCost(int cost)
{
    this->cost = cost;
}

void Vehicle::addCost(int cost)
{
    this->cost += cost;
}

int Vehicle::getCost()
{
    return cost;
}

void Vehicle::setRoute(std::vector<Client> r)
{
    this->route = r;
}

std::vector<Client> Vehicle::getRoute()
{
    return route;
}

bool Vehicle::CheckDelivery(int demand)
{  
    return (load-demand) >= 0;
}