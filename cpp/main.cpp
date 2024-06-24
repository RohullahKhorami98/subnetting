#include <iostream>
#include <string>
#include <vector>
#include "classC.h"
using namespace std;


int main() {
    std::string subnet = "255.255.255.0";
    std::string network = "192.168.1.1";
    int numberOfHosts = 4;
    //std::cin >> subnet >> network >> numberOfHosts;
    subnetClassC classC(subnet, network, numberOfHosts);
    std::vector<std::string> networkbinray = classC.getNetworkBinary();
    std::vector<std::string> subnetbinary = classC.getSubnetBinary();
    classC.printVector(subnetbinary, "Subnet: ");
    classC.printVector(networkbinray , "Network: ");
    std::cout << "Number of bits: " << classC.getNumberOfbits() << std::endl;
    std::vector<std::string> networkCombinations = classC.getNetworkCombinations();
    classC.printVector(networkCombinations, "Network Combinations: ");
    std::cout << "Last zeros: " << classC.getZeros(8) << std::endl;
    std::cout << "Last ones: " << classC.getOnes(8) << std::endl;
    std::vector<std::string> broadCombinations = classC.getBroadCombinations();
    classC.printVector(broadCombinations, "Broad Combinations: ");
    std::cout<<"Subnet Mask: " << classC.getSubnetMask()<<std::endl;
    vector<vector<std::string>> firstRange = classC.combineNetworkCombinations().first;
    vector<vector<std::string>> secondRange = classC.combineNetworkCombinations().second;
    classC.print2DVector(firstRange, "first_range: ");
    classC.print2DVector(secondRange, "second_range: ");
    vector<vector<std::string>> firstInteger = classC.binaryToDecimal().first;
    vector<vector<std::string>> secondInteger = classC.binaryToDecimal().second;
    classC.print2DVector(firstInteger, "First Integer: ");
    classC.print2DVector(secondInteger, "Second Integer: ");
    classC.useAbleIPs();
    classC.printResult();
    return 0;
}
