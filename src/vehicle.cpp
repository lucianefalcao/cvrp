#include "../includes/vehicle.h"

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

void Vehicle::setLoad()
{
    this->load = capacity;
}

void Vehicle::setCost(int cost)
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

void Vehicle::printRoute(std::vector<Vehicle*> v)
{
    int totalCost = 0;
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << "\nCaminhão " << i+1 << ": ";
        for(int j = 0; j < v[i]->getRoute().size()-1; ++j)
        {
            std::cout << v[i]->getRoute()[j].getID() << " -> ";
        }
        std::cout << "0\n";
        std::cout << "Clientes atendidos: " << v[i]->getRoute().size()-2 << '\n';
        std::cout << "Custo da rota: " << v[i]->getCost() << "\n";
        // std::cout << "\n";
        totalCost += v[i]->getCost();
    }
    std:: cout << '\n';
    std::cout << "Custo total: "<< totalCost << "\n";
    
}