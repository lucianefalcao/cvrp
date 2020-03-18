#include "../includes/vehicle.h"

// TODO: criar função para calcular custos

Vehicle::Vehicle()
{
    setCurrentLocation(0); // começa no depósito
    this->cost = 0;
}

int Vehicle::getCapacity()
{
    return capacity;
}

void Vehicle::setCapacity(int capacity)
{
    this->capacity = capacity;
}

int Vehicle::getCurrentLocation()
{
    return this->currentLocation;
}

void Vehicle::setCurrentLocation(int loc)
{
    this->currentLocation = loc;
}

void Vehicle::addClientToRoute(Client client)
{
    this->route.push_back(client);
}

int Vehicle::getLoad()
{
    return load;
}

void Vehicle::setLoad(int capacity)
{
    this->load = capacity;
}

void Vehicle::setCost(int cost)
{
    this->cost = cost;
}

void Vehicle::setRoute(std::vector<Client> r)
{
    this->route = r;
}

void Vehicle::addCost(int cost)
{
    this->cost += cost;
}

int Vehicle::getCost()
{
    return cost;
}

void Vehicle::calculateLoad(int load)
{
    this->load -= load;
}

bool Vehicle::CheckDelivery(int demand)
{
    /* 
    se o caminho ainda tiver capacidade 
    atualiza a carga
    */
   
    return (load-demand) >= 0;
}

std::vector<Client> Vehicle::getRoute()
{
    return route;
}



int Vehicle::getTotalCost(std::vector<Vehicle*> v)
{
    int totalCost = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        totalCost += v[i]->getCost();
    }
    
    return totalCost;
}