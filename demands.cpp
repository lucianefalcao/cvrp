#include "includes/demands.h"

Demands::Demands(int clientID, int clientDemand)
{
    this->clientID = clientID;
    this->clientDemand = clientDemand;
}

int Demands::getClientID()
{
    return this->clientID;
}

int Demands::getClientDemand()
{
    return this->clientDemand;
}