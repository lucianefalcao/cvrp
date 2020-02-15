#include "../includes/graph.h"

Graph::Graph(){}

void Graph::addEdges(int a, int w)
{
    this->marix_adj[a].push_back(w);
}

void Graph::setNumberOfClients(int numberOfClients)
{
    this->numberOfVertices = numberOfClients;
}

void Graph::initializeMatrix()
{
    this->marix_adj.resize(this->numberOfVertices);
}

std::vector<std::vector<int>> Graph::getMatrix()
{
    return this->marix_adj;
}