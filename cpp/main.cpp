#include <iostream>
#include <string>
#include <vector>
#include "classC.h"
using namespace std;


int main() {
    std::string subnet;
    std::string network;
    int numberOfHosts;
    std::cin >> subnet >> network >> numberOfHosts;
    subnetClassC classC(subnet, network, numberOfHosts);
    std::vector<std::string> networkbinray = classC.getNetworkBinary();
    std::vector<std::string> subnetbinary = classC.getSubnetBinary();
    classC.printVector(subnetbinary, "Subnet: ");
    classC.printVector(networkbinray , "Network: ");
    return 0;
}
