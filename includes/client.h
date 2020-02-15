#ifndef CLIENT_H
#define CLIENT_H

class Client
{
private:
    int id;
    int demand;
public:
    Client(int id, int demand);
    int getID();
    int getDemand();
};


#endif