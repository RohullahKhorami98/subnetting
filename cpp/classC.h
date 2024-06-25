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
    std::vector<std::string> getSubnetBinary();
    std::vector<std::string> getNetworkBinary();
    void printVector(std::vector<std::string> vectorArray, std::string message);
    int getNumberOfbits();
    std::vector<std::string>getNetworkCombinations();
    std::string getZeros(int zeros);
    std::string getOnes(int ones);
    std::vector<std::string> getBroadCombinations();
    std::string getSubnetMask();
    std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>> combineNetworkCombinations();
    void print2DVector(std::vector<std::vector<std::string>> vectorArray, std::string message);
    std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>>binaryToDecimal();
    std::vector<std::vector<std::vector<std::string>>> useAbleIPs();
    void printResult();
};

#endif // CLASSC_H
