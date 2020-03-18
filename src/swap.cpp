#include "../includes/swap.h"

Swap::Swap(){}

void Swap::setGraph(Graph *graph)
{
    this->graph = graph;
}

void Swap::getMovement(std::vector<Client>& routeA, std::vector<Client>& routeB, int *Acost, int *Bcost, int *loadA, int *loadB)
{

    // TODO: implementar para pegar todas as rotas -> usando for v.size()
    int beforeA, beforeB, afterA, afterB;
    bool change = false;

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
                    change = true;
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

int Swap::buildSolution(std::vector<Vehicle*> v)
{
    int Acost, Bcost;
    int totalCost = 0;
    std::vector<Client> a, b;

    for (int k = 0; k < v.size(); ++k)
    {
        Acost = v[k]->getCost(); // custo da rota A
        a = v[k]->getRoute(); // rota A
        int loadA = v[k]->getLoad(); // Capacidade restante do veículo A
        for (int l = k+1; l < v.size(); ++l)
        {
            Bcost = v[l]->getCost(); // custo da rota B
            b = v[l]->getRoute(); // rota B
            int loadB = v[l]->getLoad(); // Capacidade restante do veículo B
            getMovement(a, b, &Acost, &Bcost, &loadA, &loadB);
            // Atualiza os valores dos veículos A e B 
            v[k]->setRoute(a);
            v[l]->setRoute(b);
            v[k]->setCost(Acost);
            v[l]->setCost(Bcost);
            v[k]->setLoad(loadA);
            v[l]->setLoad(loadB);
        }

        totalCost += v[k]->getCost();
    }

    return totalCost;
}