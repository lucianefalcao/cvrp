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
    Graph(int numberOfVertices);
    ~Graph();
    void addEdges(int, int, int);
};


#endif