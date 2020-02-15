#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
private:
    int numberOfVertices;
    std::vector<std::vector<int>> *matrix;
public:
    Graph(int);
    ~Graph();
};


#endif 