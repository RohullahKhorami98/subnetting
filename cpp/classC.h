#ifndef CLASSC_H
#define CLASSC_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classC.h"
#include <bitset>
#include <limits>
using namespace std;

class subnetClassC {
private:
    std::string subnet;
    std::string network;
    int numberOfHosts;
public:
    subnetClassC(std::string subnet, std::string network, int numberOfHosts);
    std::vector<std::vector<std::string>> toBinary();
    std::vector<std::string> splitInput(std::string textToSplit);
};

#endif // CLASSC_H
