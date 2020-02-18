#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

class Graph
{
private:
    std::vector<std::vector<int>> marix_adj; 
    int numberOfVertices;
public:
    Graph();

    void addEdges(int, int);
    void setNumberOfClients(int numberOfClients);
    void initializeMatrix();
    std::vector<std::vector<int>> getMatrix();

};


#endif