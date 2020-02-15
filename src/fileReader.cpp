#include "../includes/fileReader.h"

int dimension;
int capacity;
std::fstream f;
Model *model = new Model();

/* 
   Ler a dimensão e capacidade do veículo.
   Para pegar apenas o número, lemos a linha
   e separamos a linha em tokens 
*/
void readDimensionAndCapacity()
{
    std::string str;

    for (int i = 0; i < 2; ++i)
    {
        getline(f, str);
        char *token = strtok((char *)str.c_str(), " "); // token = Dimension
        token = strtok(NULL, " "); // token = valor

        if(i == 0)
        {
            dimension = std::stoi(token);
            model->setDimension(dimension);
        }
        else if(i == 1)
        {
            capacity = std::stoi(token);
            Vehicle *vehicle = new Vehicle(capacity);
        }
    }
}

// Pula linhas desnecessárias
void skipLine(int lines)
{
    std::string s;
    for (int i = 0; i < lines; ++i)
    {
        getline(f, s);
    }
    
}

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
        std::cout << clientID;
        f >> clientDemand;
        Client client = Client(clientID, clientDemand);
        model->addClients(&client);
    }
}

void readMatrix()
{

    Graph *graph = new Graph(dimension);
    std::string s;
    int distance;

    for(int i = 0; i < dimension; ++i)
    {
        getline(f, s);
        std::stringstream ss(s);
        for (int j = 0; j < dimension; ++j)
        {
            while (ss >> distance)
            {
                graph->addEdges(i, j, distance);
            }
        }
        
    }
}

// Abre o arquivo e lê os dados
void readFile(std::string fileName)
{
    f.open(fileName);

    if(f.is_open())
    {
        skipLine(1);
        readDimensionAndCapacity();
        skipLine(1);
        setClients();
        skipLine(3);
        readMatrix();
    }
}