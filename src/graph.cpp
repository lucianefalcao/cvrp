#include "../includes/graph.h"

Graph::Graph(int numberOfVertices)
{
    this->numberOfVertices = numberOfVertices;
    marix_adj.resize(numberOfVertices);
}

void Graph::addEdges(int a, int b, int w)
{
    this->marix_adj[a].push_back(w);
}