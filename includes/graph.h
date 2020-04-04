#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include<algorithm>

class Graph
{
private:
    std::vector<std::vector<int>> matrix_adj;
    int numberOfVertices;
public:
    Graph();
    ~Graph();

    void addEdges(int, int);
    void setNumberOfClients(int numberOfClients);
    void initializeMatrix();
    
    std::vector<std::vector<int>> getMatrix();
};


#endif