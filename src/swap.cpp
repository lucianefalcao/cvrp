#include "../includes/swap.h"

Swap::Swap(){}

void Swap::setGraph(Graph *graph)
{
    this->graph = graph;
}

int Swap::getMovement(std::vector<Client>& route, int currentDistance)
{
    int bestDistance = currentDistance;
    bool change = false;

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
                    change = true;
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

void Swap::printSolution(std::vector<Vehicle*> v)
{
    std::vector<Client> r;
    int totalCost = 0;
    std::cout << "\nSWAP: \n";
    for (int i = 0; i < v.size(); ++i)
    {
        r = v[i]->getRoute();
        v[i]->setCost(getMovement(r, v[i]->getCost()));
        v[i]->setRoute(r);
        std::cout << "\nCaminhão " << i+1 << ": ";
        for(int j = 0; j < v[i]->getRoute().size()-1; ++j)
        {
            std::cout << v[i]->getRoute()[j].getID() << " -> ";
        }
        std::cout << "0\n";
        std::cout << "Custo da rota: " << v[i]->getCost() << "\n";
        totalCost += v[i]->getCost();
    }
    std:: cout << '\n';
    std::cout << "Custo total: "<< totalCost << "\n";
}