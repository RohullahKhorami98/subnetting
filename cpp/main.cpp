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
    std::vector<std::vector<std::string>> binary = classC.toBinary();
    for (int i = 0; i < binary.size(); i++) {
        for (int j = 0; j < binary[i].size(); j++) {
            std::cout << binary[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
