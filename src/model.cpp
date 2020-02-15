#include "../includes/model.h"

Model::Model(){}

void Model::setDimension(int dimension)
{
    this->dimension = dimension;
}

void Model::addClients(Client *client)
{
    this->clients.push_back(*client);
}