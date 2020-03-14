#include "../includes/swap.h"

Swap::Swap(){}

void Swap::setGraph(Graph *graph)
{
    this->graph = graph;
}

void Swap::getMovement(std::vector<Client>& routeA, std::vector<Client>& routeB, int *Acost, int *Bcost, int capacity, int *loadA, int *loadB)
{

    // TODO: implementar para pegar todas as rotas -> usando for v.size()
    int beforeA, beforeB, afterA, afterB;
    bool change = false;

    for (int i = 1; i < routeA.size()-1; ++i)
    {
        for (int j = 1; j < routeB.size()-1; ++j)
        {

            if(routeB[j].getDemand() <= (routeA[i].getDemand() + capacity - (capacity - *loadA))
               && routeA[i].getDemand() <= (routeB[j].getDemand() + capacity - (capacity - *loadB)))
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
                    *loadA = routeA[i].getDemand() + capacity - (capacity - *loadA);
                    *loadB = routeB[j].getDemand() + capacity - (capacity - *loadB);
                }
                else
                {
                    std::swap(routeA[i], routeB[j]);
                }
            } 
        }   
    }
}

void Swap::printSolution(std::vector<Vehicle*> v)
{
    int Acost, Bcost;
    std::vector<Client> a, b;
    int c = v[0]->getCapacity();
    int totalCost = 0;
    std::cout << "\nSWAP: \n";

    for (int k = 0; k < v.size(); ++k)
    {
        Acost = v[k]->getCost(); 
        a = v[k]->getRoute(); // rota a
        int loadA = v[k]->getLoad();
        for (int l = k+1; l < v.size(); ++l)
        {
            Bcost = v[l]->getCost();
            b = v[l]->getRoute(); // rota b
            int loadB = v[l]->getLoad();
            getMovement(a, b, &Acost, &Bcost, c, &loadA, &loadB);
            v[k]->setRoute(a);
            v[l]->setRoute(b);
            v[k]->setCost(Acost);
            v[l]->setCost(Bcost);
            v[k]->setLoad(loadA);
            v[l]->setLoad(loadB);
        }
        
    }


    for (int i = 0; i < v.size(); ++i)
    {
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