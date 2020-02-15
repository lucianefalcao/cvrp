#ifndef CLIENT_H
#define CLIENT_H

class Client
{
private:
    int id;
    int demand;
    bool wasVisited;
public:
    Client(int id, int demand);

    void setInRoute();

    int getID();
    int getDemand();

    bool inRoute();
};


#endif