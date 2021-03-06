#include "../includes/reinsertion.h"

Reinsertion::Reinsertion(){}

void Reinsertion::setGraph(Graph *graph)
{
    this->graph = graph;
}

std::vector<Client> Reinsertion::move(std::vector<Client>& route, int i, int j)
{
    std::vector<Client> newRoute;
    newRoute.push_back(route[0]);
    
    for (int k = 1; k < i; ++k)
    {
        newRoute.push_back(route[k]);
    }

    for (int k = i+1; k <= j; ++k)
    {
        newRoute.push_back(route[k]);
    }

    newRoute.push_back(route[i]);

    // Adiciona o restante
    for (int k = j+1; k < route.size(); ++k)
    {
        newRoute.push_back(route[k]);
    }
    
    return newRoute;
}

int Reinsertion::getMovement(std::vector<Client>& route, int currentDistance)
{

    int bestDistance = currentDistance;
    int before, after;

    for (int i = 1; i < route.size()-1; ++i)
    {
        for (int j = i+1; j < route.size()-1; ++j)
        {
            std::vector<Client> newRoute = move(route, i, j);

            if(j - i == 1)
            {
                before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] + 
                         graph->getMatrix()[route[i].getID()][route[i+1].getID()] +  
                         graph->getMatrix()[route[j].getID()][route[j+1].getID()];   

                after = graph->getMatrix()[newRoute[i].getID()][newRoute[i-1].getID()] + 
                        graph->getMatrix()[newRoute[i].getID()][newRoute[i+1].getID()] +
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j+1].getID()];
                
            }
            else
            {

                before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] + 
                         graph->getMatrix()[route[i].getID()][route[i+1].getID()] +  
                         graph->getMatrix()[route[j].getID()][route[j+1].getID()];   

                after = graph->getMatrix()[newRoute[i].getID()][newRoute[i-1].getID()] + 
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j-1].getID()] +
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j+1].getID()];
            }

            if(after < before)
            {
                bestDistance += (after-before);
                route = newRoute;
            }

        }
        
    }
    return bestDistance;
}