#include "../includes/vehicle.h"

Vehicle::Vehicle()
{
    setCurrentLocation(0); // começa no depósito
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

void Vehicle::setCarga()
{
    this->carga = capacity;
}

void Vehicle::calculateCarga(int carga)
{
    this->carga -= carga;
}

bool Vehicle::fits(int demand)
{
    /* 
    se o caminho ainda tiver capacidade 
    atualiza a carga
    */
   
    return (carga-demand) >= 0;
}

void Vehicle::printRoute()
{
    std::cout << '\n';
    for (int i = 0; i < route.size(); ++i)
    {
        std::cout << route[i].getID() << " -> ";
    }
    
}