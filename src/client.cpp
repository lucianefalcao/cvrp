#include "../includes/client.h"

Client::Client(int id, int demand)
{
    this->id = id;
    this->demand = demand;
    this->wasVisited = false;
}

int Client::getID()
{
    return id;
}

int Client::getDemand()
{
    return demand;
}

bool Client::inRoute()
{
    return wasVisited;
}

void Client::setInRoute()
{
    wasVisited = true;
}