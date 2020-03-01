#include "../includes/insertion.h"

Insertion::Insertion(){}

void Insertion::setGraph(Graph *graph)
{
    this->graph = graph;
}

std::vector<Client> Insertion::move(std::vector<Client>& route, int i, int j)
{
    std::vector<Client> newRoute;
    for (int k = 0; k < i; ++k)
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

int Insertion::getMovement(std::vector<Client>& route, int currentDistance)
{
    int bestDistance = currentDistance;
    int aux = 0; 
    int before, after;

    for (int i = 1; i < route.size()-1; ++i)
    {
        aux = 0;
        for (int j = i+1; j < route.size()-1; ++j)
        {
            std::vector<Client> newRoute = move(route, i, j);

            if(j - i == 1)
            {
                before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] + 
                         graph->getMatrix()[route[i].getID()][route[j-aux].getID()] +  
                         graph->getMatrix()[route[j].getID()][route[j+1].getID()];   

                after = graph->getMatrix()[newRoute[i].getID()][newRoute[i-1].getID()] + 
                        graph->getMatrix()[newRoute[i].getID()][newRoute[j].getID()] +
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j+1].getID()];
                
                ++aux;
            }
            else
            {
                before = graph->getMatrix()[route[i].getID()][route[i-1].getID()] + 
                         graph->getMatrix()[route[i].getID()][route[j-aux].getID()] +  
                         graph->getMatrix()[route[j].getID()][route[j+1].getID()];   
    
                after = graph->getMatrix()[newRoute[i].getID()][newRoute[i-1].getID()] + 
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j-1].getID()] +
                        graph->getMatrix()[newRoute[j].getID()][newRoute[j+1].getID()];

                ++aux;
            }

            if(after < before)
            {
                bestDistance += (after-before);
                route = newRoute;
                i = 1;
            }

        }
        
    }

    return bestDistance;
    
}

void Insertion::printSolution(std::vector<Vehicle*> v)
{
    std::vector<Client> r;
    int totalCost = 0;
    std::cout << "\nINSERTION: \n";
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