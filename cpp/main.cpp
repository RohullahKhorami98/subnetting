#include <iostream>
#include <string>
#include <vector>
#include "classC.h"
using namespace std;


int main() {
    std::string subnet;
    std::string network;
    int numberOfHosts;
    std::cout << "Enter the network address: "<<std::endl;
    std::cin >> network;
    std::cout << "Enter the subnet: "<<std::endl;
    std::cin >> subnet;
    std::cout << "Enter the number of subnets: "<<std::endl;
    std::cin >> numberOfHosts;
    subnetClassC classC(subnet, network, numberOfHosts);
    classC.printResult();
    return 0;
}
