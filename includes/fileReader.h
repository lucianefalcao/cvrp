#ifndef FILEREADER_H
#define FILEREADER_H

#include "client.h"
#include "heuristic.h"

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

void readFile(std::string, int);
void readDimensionAndCapacity();
void skipLine(int lines);
void setClients();
void readMatrix();

#endif