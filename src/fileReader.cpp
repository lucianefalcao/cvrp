#include "../includes/fileReader.h"

int dimension;
int capacity;
float timeMedia = 0.0;
std::chrono::duration<float> sum;
std::fstream f;
Model *model = new Model();
Graph *graph = new Graph();
Vehicle *vehicle = new Vehicle();
Client *client = NULL;
TwoOpt *opt = new TwoOpt();

/* 
    Ler o id e a demanda do client e cria uma
    nova instância de cliente e adiciona em um
    vector
 */
void setClients()
{
    int clientID, clientDemand;

    for(int i = 0; i < dimension; ++i)
    {
        f >> clientID;
        f >> clientDemand;
        client = new Client(clientID, clientDemand);
        model->addClients(client);
    }
}

void readMatrix()
{
    graph->setNumberOfClients(dimension);
    graph->initializeMatrix();

    std::string s;
    int distance;

    graph->addEdges(0, 0);

    for(int i = 0; i < dimension; ++i)
    {
        getline(f, s);
        std::stringstream ss(s);
        while (ss >> distance)
        {
            graph->addEdges(i, distance);
        } 
    }
}

// Abre o arquivo e lê os dados
void readFile(std::string fileName, int iterations)
{

    std::string aux;

    f.open(fileName);

    if(f.is_open())
    {
        f >> aux; // NAME
        f >> aux; // name
        f >> aux; // DIMENSION
        f >> dimension;
        f >> aux; // CAPACITY
        f >> capacity;
        f >> aux; // DEMAND_SECTION:

        model->setDimension(dimension);
        setClients();

        f >> aux; // blank
        f >> aux; // EDGE_WEIGHT_SECTION

        readMatrix();
        Heuristic *h = new Heuristic();
        h->setModel(model);
        h->setGraph(graph);
        h->createVehicle(capacity);

        h->nearestNeighboor(iterations);
    }
}