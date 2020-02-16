#include "../includes/vehicle.h"

Vehicle::Vehicle()
{
    setCurrentLocation(0); // começa no depósito
    this->carga = 0; // começa sem carga
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

void Vehicle::setCarga(int carga)
{
    this->carga += carga;
}

bool Vehicle::fits(int demand)
{
    /* 
    se o caminho ainda tiver capacidade 
    atualiza a carga
    */
   
    return (carga + demand) <= capacity;
}