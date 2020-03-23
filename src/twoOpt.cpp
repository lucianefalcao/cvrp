#include "../includes/twoOpt.h"

TwoOpt::TwoOpt() {}

void TwoOpt::setGraph(Graph *graph)
{
    this->graph = graph;
}

std::vector<Client> TwoOpt::change(std::vector<Client>& route, int i, int j)
{
    std::vector<Client> newRoute;
    newRoute.push_back(route[0]);

    for(int k = 1; k < i; ++k)
    {   
        newRoute.push_back(route[k]);
    }

    // Adiciona na ordem reversa
    for (int k = j; k >= i; --k)
    {
        newRoute.push_back(route[k]);
    }

    // Adiciona o restante
    for (int k = j+1; k < route.size(); ++k)
    {
        newRoute.push_back(route[k]);
    }

    return newRoute;
    
}

int TwoOpt::getMovement(std::vector<Client>& route, int currentDistance)
{
    int bestDistance = currentDistance;

    for(int i = 1; i < route.size()-1; ++i)
    {
         for (int j = i+1; j < route.size()-1; ++j)
         {
            std::vector<Client> newRoute = change(route, i, j);

            // Calcula o custo das arestas antes
            int before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] +  // *
                         graph->getMatrix()[route[i].getID()][route[i+1].getID()] +
                         graph->getMatrix()[route[j].getID()][route[j-1].getID()] + 
                         graph->getMatrix()[route[j].getID()][route[j+1].getID()];   // *
            // Calcula o custo das arestas depois
            int after = graph->getMatrix()[newRoute[i].getID()][newRoute[i-1].getID()] + 
                        graph->getMatrix()[newRoute[i].getID()][newRoute[i+1].getID()] +
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j-1].getID()] + 
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j+1].getID()];

            if(after < before)
            {
                bestDistance += (after-before);
                route = newRoute; 
            }
         } 
    }
    return bestDistance;
}