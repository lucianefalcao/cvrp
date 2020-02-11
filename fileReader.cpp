#include "includes/fileReader.h"

int dimension;
int capacity;
std::fstream f;
std::vector<Demands> demands;

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
            dimension = std::stoi(token);
        else if(i == 1)
            capacity = std::stoi(token);
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
   Ler as demandas e adiciona a um vetor de 
   Demandas, criando uma nova instância 
*/
void readDemands()
{
    int clientID, clientDemand;

    for(int i = 0; i < dimension; ++i)
    {
        f >> clientID;
        std::cout << clientID;
        f >> clientDemand;
        demands.push_back(Demands(clientID, clientDemand));
    }
}

void readMatrix()
{
    int matrix[dimension][dimension];

    std::string str;

    for (int i = 0; i < 16; ++i)
    {

        getline(f, str);
        std::stringstream ss(str);

        int vertice;

        for (int j = i+1; i < 16; )
        {
            
            matrix[i][j-1] = 0;

            while (ss >> vertice)
            {
                matrix[i][j] = vertice;
                matrix[j][i] = vertice;
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
        readDemands();
        skipLine(2);
        readMatrix();
    }
}