#include "../includes/swap.h"

Swap::Swap(){}

void Swap::setGraph(Graph *graph)
{
    this->graph = graph;
}

void Swap::getMovementInter(std::vector<Client>& routeA, std::vector<Client>& routeB, int *Acost, int *Bcost, int *loadA, int *loadB)
{

    // TODO: implementar para pegar todas as rotas -> usando for v.size()
    int beforeA, beforeB, afterA, afterB;

    for (int i = 1; i < routeA.size()-1; ++i)
    {
        for (int j = 1; j < routeB.size()-1; ++j)
        {

            if((routeB[j].getDemand() <= (routeA[i].getDemand() + *loadA))
               && routeA[i].getDemand() <= (routeB[j].getDemand() + *loadB))
            {
                beforeA = graph->getMatrix()[routeA[i].getID()][routeA[i-1].getID()] +  
                          graph->getMatrix()[routeA[i].getID()][routeA[i+1].getID()];  

                beforeB = graph->getMatrix()[routeB[j].getID()][routeB[j-1].getID()] + 
                          graph->getMatrix()[routeB[j].getID()][routeB[j+1].getID()];

                std::swap(routeA[i], routeB[j]);

                afterA = graph->getMatrix()[routeA[i].getID()][routeA[i-1].getID()] + 
                         graph->getMatrix()[routeA[i].getID()][routeA[i+1].getID()];
            
                afterB = graph->getMatrix()[routeB[j].getID()][routeB[j-1].getID()] + 
                         graph->getMatrix()[routeB[j].getID()][routeB[j+1].getID()];
                
                if((afterA < beforeA) && (afterB < beforeB))
                {
                    *Acost -= beforeA - afterA;
                    *Bcost -= beforeB - afterB;
                    *loadA = routeA[i].getDemand() + *loadA;
                    *loadB = routeB[j].getDemand() + *loadB;
                }
                else
                {
                    std::swap(routeA[i], routeB[j]);
                }
            } 
        }   
    }
}

int Swap::getMovementIntra(std::vector<Client>& route, int currentDistance)
{
    int bestDistance = currentDistance;

    for (int i = 1; i < route.size()-1; ++i)
    {
        for (int j = i+1; j < route.size()-1; ++j)
        {
                int before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] +  // *
                             graph->getMatrix()[route[i].getID()][route[i+1].getID()] +
                             graph->getMatrix()[route[j].getID()][route[j-1].getID()] + 
                             graph->getMatrix()[route[j].getID()][route[j+1].getID()];   // *

                std::swap(route[i], route[j]);
                
                int after = graph->getMatrix()[route[i].getID()][route[i-1].getID()] + 
                            graph->getMatrix()[route[i].getID()][route[i+1].getID()] +
                            graph->getMatrix()[route[j].getID()][route[j-1].getID()] + 
                            graph->getMatrix()[route[j].getID()][route[j+1].getID()];

                if(after < before)
                {
                    bestDistance += after-before; 
                }
                else
                {
                    std::swap(route[i], route[j]);
                }
        }   
    }
    return bestDistance;
}