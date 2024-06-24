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
    std::vector<std::string> combinations = classC.getCombinations();
    classC.printVector(combinations, "Combinations: ");
    return 0;
}
