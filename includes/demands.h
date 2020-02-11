#ifndef DEMANDS_H
#define DEMANDS_H

class Demands
{
private:
    int clientID;
    int clientDemand;
public:
    Demands(int clientID, int clientDemand);
    int getClientID();
    int getClientDemand();
};


#endif