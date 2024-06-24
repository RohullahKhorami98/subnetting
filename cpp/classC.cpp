#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classC.h"
#include <bitset>
#include <limits>
#include <math.h>
#include <cmath>
using namespace std;

subnetClassC::subnetClassC(std::string subnet, std::string network, int numberOfHosts) {
    this->subnet = subnet;
    this->network = network;
    this->numberOfHosts = numberOfHosts;
}
/**
 * Split the input string into a vector of integers and convert them to binary
 * and put them in a 2D vector
 */
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
/**
 * Convert the subnet and network to binary and put them in a 2D vector
 * and change the last element to 00000000
 */
std::vector<std::vector<std::string>> subnetClassC::toBinary(){
    std::string subnet = this->subnet;
    std::string network = this->network;
    std::vector<std::string> subnetArray = splitInput(subnet);
    std::vector<std::string> networkArray = splitInput(network);
    subnetArray.back() = "00000000";
    networkArray.back() = "00000000";
    std::vector<std::vector<std::string>> binary;
    binary.push_back(subnetArray);
    binary.push_back(networkArray);

    return binary;
}
/**
 * Get the subnet in binary from the 2D vector
 */
std::vector<std::string> subnetClassC::getSubnetBinary() {
    std::vector <std::string> subnet = toBinary()[1];
    return subnet;
}

/**
 * Get the network in binary from the 2D vector
 */
std::vector<std::string> subnetClassC::getNetworkBinary() {
    std::vector <std::string> network = toBinary()[0];
    return network;
}

void subnetClassC::printVector(std::vector<std::string> vectorArray, std::string message) {
    std::cout << message;
    for(int i = 0; i < vectorArray.size(); i++){
        std::cout << vectorArray[i]<< " ";
    }
    std::cout << std::endl;
}

/**
 * Get the number of bits using 2 ^ x = number of subnets in class C
 *  x = log2(number of subnets in class C), 
 * for example we want 4 subnets , how many bits should we use ?
 * x = log2(4) = 2 
 * Example 2 = we want 8 subnets , how many bits should we use ?
 * x = log2(8) = 3
 */
int subnetClassC::getNumberOfbits() {
    int bits = log2(this->numberOfHosts);
    return bits;
}

/**
 * Get the combinations of the last bits
 * for example if we have 4 subnets
 * 00000000
 * 00000001
 * 00000010
 * 00000011 
 * We count the number of combinations using pow(2, bits)
 * pow(2, 2) = 4
 * pow(2, 3) = 8
 * and created a vector with the last bits
 * we loop from 0 to pow(2, bits) and change the ith value to binary
 * and put it in the vector
 */
std::vector<std::string> subnetClassC::getCombinations() {
    std::string combos[2] = {"1","0"};
    int bits = getNumberOfbits();
    std::vector<std::string> combinations;
   int totalCombinations = pow(2, bits);
    for (int i = 0; i < totalCombinations; ++i) {
        std::bitset<8> binary(i);
        std::string binaryString = binary.to_string(); 
        std::string lastBits = binaryString.substr(8 - bits); 
        combinations.push_back(lastBits);
    }
    return combinations;
}