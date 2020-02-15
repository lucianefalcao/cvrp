#ifndef MODEL_H
#define MODEL_H

#include <vector>

// TODO: mudar o vetor de client para ser uma referência.

#include "client.h"

class Model
{
private:
    int dimension;
    std::vector<Client> clients;
public:
    Model();
    void addClients(Client *client);
    void setDimension(int dimension);
    int getDimension();
    std::vector<Client> getClients();
};


#endif