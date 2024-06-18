#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classC.h"
#include <bitset>
#include <limits>
using namespace std;

subnetClassC::subnetClassC(std::string subnet, std::string network, int numberOfHosts) {
    this->subnet = subnet;
    this->network = network;
    this->numberOfHosts = numberOfHosts;
}

std::vector<std::string> subnetClassC::splitInput(std::string textToSplit){
    std::vector<int> splitedInput; 
    std::vector<std::string> binary;
    stringstream streamText(textToSplit);
    std::string temp;
    while (std::getline(streamText, temp , '.'))
    {
        splitedInput.push_back(std::stoi(temp));
    }
    for(int i = 0; i < splitedInput.size(); i++){
        std::bitset<8> bits(splitedInput[i]);
        binary.push_back(bits.to_string());
    }
    return binary;
}
std::vector<std::vector<std::string>> subnetClassC::toBinary(){
    std::string subnet = this->subnet;
    std::string network = this->network;
    std::vector<std::string> subnetArray = splitInput(subnet);
    std::vector<std::string> networkArray = splitInput(network);

    std::vector<std::vector<std::string>> binary;
    binary.push_back(subnetArray);
    binary.push_back(networkArray);

    return binary;
}