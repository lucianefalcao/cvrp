#include "../includes/client.h"

Client::Client(int id, int demand)
{
    this->id = id;
    this->demand = demand;
}

int Client::getID()
{
    return id;
}

int Client::getDemand()
{
    return demand;
}