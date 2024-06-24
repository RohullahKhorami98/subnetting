#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include "classC.h"
#include <bitset>
#include <limits>
#include <math.h>
#include <cmath>
#include <utility>
using namespace std;
/**
 * Constructor of the class with the subnet, the network and the number of hosts
 */
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
    std::vector <std::string> subnet = toBinary()[0];
    return subnet;
}

/**
 * Get the network in binary from the 2D vector
 */
std::vector<std::string> subnetClassC::getNetworkBinary() {
    std::vector <std::string> network = toBinary()[1];
    return network;
}
/**
 * Print the vector
 */
void subnetClassC::printVector(std::vector<std::string> vectorArray, std::string message) {
    std::cout << message <<std::endl;
    for(int i = 0; i < vectorArray.size(); i++){
        std::cout << vectorArray[i]<< " ";
    }
    std::cout << std::endl;
}
/**
 * Print the 2D vector
 */
void subnetClassC::print2DVector(std::vector<std::vector<std::string>> vectorArray, std::string message) {
    std::cout << message <<std::endl;
    for(int i = 0; i < vectorArray.size(); i++){
        for(int j = 0; j < vectorArray[i].size(); j++){
            std::cout << vectorArray[i][j] << " ";
        }
        std::cout << std::endl;
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
 * Get the zeros using the number of bits
 */
std::string subnetClassC::getZeros(int zeros) {
    std::string zerosString = "";
    for(int i = 0; i < zeros; i++){
        zerosString += "0";
    }
    return zerosString;
}
/**
 * Get the ones using the number of bits
 */
std::string subnetClassC::getOnes(int ones) {
    std::string onesString = "";
    for(int i = 0; i< ones; i++){
        onesString += "1";
    }
    return onesString;
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
std::vector<std::string> subnetClassC::getNetworkCombinations() {
    int bits = getNumberOfbits();
    std::vector<std::string> combinations;
   int totalCombinations = pow(2, bits);
    for (int i = 0; i < totalCombinations; ++i) {
        std::bitset<8> binary(i);
        std::string binaryString = binary.to_string(); 
        std::string lastBits = binaryString.substr(8 - bits) + getZeros(8-bits); 
        combinations.push_back(lastBits);
    }
    return combinations;
}
/**
 * Get the combinations of the last bits
 * for example if we have 4 subnets
 * 00111111
 * 10111111
 * 01111111
 * 11111111
 * We count the number of combinations using pow(2, bits)
 * pow(2, 2) = 4
 * pow(2, 3) = 8
 * and created a vector with the last bits
 * we loop from 0 to pow(2, bits) and change the ith value to binary
 * and put it in the vector
 */
std::vector<std::string> subnetClassC::getBroadCombinations() {
    int bits = getNumberOfbits();
    std::vector<std::string> combinations;
    int totalCombinations = pow(2, bits);
    for (int i = 0; i < totalCombinations; ++i) {
        std::bitset<8> binary(i);
        std::string binaryString = binary.to_string(); 
        std::string lastBits = binaryString.substr(8 - bits) + getOnes(8-bits); 
        combinations.push_back(lastBits);
    }
    return combinations;
}

/**
 * Get the subnet mask using the number of bits in the subnet 
 */
std::string subnetClassC::getSubnetMask(){
    int bits = getNumberOfbits();
    std::string ones = getOnes(bits);
    std::vector<std::string> subnet = getSubnetBinary();
    std::string lastElement = ones+getZeros(8-bits);
    subnet.back() = lastElement;
    std::string subnetMask = "";
    for(int i = 0; i < subnet.size(); i++){
        int temp = std::stoi(subnet[i],nullptr,2);
        std::string tempmask = std::to_string(temp);
        subnetMask += tempmask;
        if (i < subnet.size() - 1) {
            subnetMask += ".";
        }
    }
    return subnetMask;
}

/**
 * Get the network and broadcast ranges
 * We combine the last bits of the network and broadcast
 * and put them in a 2D vector
 * We return the 2D vector
 * we use std::make_pair to return the 2D vector
 */
std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>> subnetClassC::combineNetworkCombinations() {
    std::vector<std::string> networkCombinations = getNetworkCombinations();
    std::vector<std::string> broadCombinations = getBroadCombinations();
    std::vector<std::string> networkAddress = getNetworkBinary();
    std::vector<std::string> broadAddress = getNetworkBinary();
    std::vector<std::vector<std::string>> networkRanges;
    std::vector<std::vector<std::string>> broadRanges;
    for(int i = 0; i<networkCombinations.size(); i++){
        std::vector tempNetwork = networkAddress;
        tempNetwork.back() = networkCombinations[i];
        networkRanges.push_back(tempNetwork);

        std::vector tempBroad = broadAddress;
        tempBroad.back() = broadCombinations[i];
        broadRanges.push_back(tempBroad);
    }

    return std::make_pair(networkRanges, broadRanges);
}
/**
 * Using pair and 2D vector to convert binary to Integer and return pair of 2D array
 */
std::pair<std::vector<std::vector<std::string>>, std::vector<std::vector<std::string>>> subnetClassC::binaryToDecimal() {
   std::vector<std::vector<std::string>> networkRanges = combineNetworkCombinations().first;
   std::vector<std::vector<std::string>> broadRanges = combineNetworkCombinations().second;
   std::vector<std::vector<std::string>> networkInteger;
   std::vector<std::vector<std::string>> boardInteger;
   for(const auto& element: networkRanges){
        std::vector<std::string>networkTemp;
       for(const auto& element2 : element){
            int temp = std::stoi(element2, nullptr, 2);
            networkTemp.push_back(std::to_string(temp));
       }
       networkInteger.push_back(networkTemp);
   }
   for(const auto& element: broadRanges){
        std::vector<std::string>boardTemp;
       for(const auto& element2 : element){
            int temp = std::stoi(element2, nullptr, 2);
            boardTemp.push_back(std::to_string(temp));
       }
       boardInteger.push_back(boardTemp);
   }
   return std::make_pair(networkInteger,boardInteger);
}
/**
 * Returning a 2D array where all useable ip address are included
 *  
 */
std::vector<std::vector<std::string>> subnetClassC::useAbleIPs(){
    std::vector<std::vector<std::string>> netWorkInteger = binaryToDecimal().first;
    std::vector<std::vector<std::string>> broadCostInteger = binaryToDecimal().second;
    std::vector<std::vector<std::string>> ipAddresses;
    for(int i = 0; i<netWorkInteger.size(); i++){
        int start = std::stoi(netWorkInteger[i].back());
        int end = std::stoi(broadCostInteger[i].back());
        std::cout<<"start: "<< start << " end: "<<end <<std::endl;
        int count = start+1;
        std::vector<std::string> tempVector = netWorkInteger[i];
        while (count<end)
        {
            tempVector.back() = std::to_string(count);
            ipAddresses.push_back(tempVector);
            count++;
        }
    }
    return ipAddresses;
}

/**
 * Printing the last Result
 * We print the useable ip address
 */

void subnetClassC::printResult(){
    std::vector<std::vector<std::string>> ips = useAbleIPs();
    std::cout<<ips.size();
}