#include "../includes/graph.h"

Graph::Graph(){}

void Graph::addEdges(int a, int w)
{
    this->matrix_adj[a].push_back(w);
}

void Graph::setNumberOfClients(int numberOfClients)
{
    this->numberOfVertices = numberOfClients;
}

void Graph::initializeMatrix()
{
    this->matrix_adj.resize(this->numberOfVertices);
}

std::vector<std::vector<int>> Graph::getMatrix()
{
    return this->matrix_adj;
}