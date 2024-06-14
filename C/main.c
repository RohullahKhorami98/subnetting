#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/classC.h"



int main() {
    char subnet[] = "255.255.255.0";
    char network[] = "192.168.1.0";
    int numberOfHosts = 4;
    tobinary(subnet, network, numberOfHosts);
    return 0;
}