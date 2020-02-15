#ifndef MODEL_H
#define MODEL_H

#include <vector>


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
};


#endif