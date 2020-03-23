#ifndef VND_H
#define VND_H

#include "twoOpt.h"
#include "swap.h"
#include "reinsertion.h"
#include "vehicle.h"
#include "graph.h"

class LocalSearch
{
private:
    TwoOpt *opt;
    Swap *swap;
    Reinsertion *reinsertion;
    Graph *graph;
public:
    LocalSearch(Graph *graph);
    ~LocalSearch();
    void intraVND(std::vector<Client>& route, int*);
    void interVND(std::vector<Client>& routeA, std::vector<Client>& routeB, int *Acost, int *Bcost, int *loadA, int *loadB);
    void set2OPT();
    void setSwap();
    void setReinsertion();
};




#endif