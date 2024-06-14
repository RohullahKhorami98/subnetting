#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void tobinary(char* subnet, char* network, int numberOfHosts){
    int subsize = strlen(subnet);
    int netsize = strlen(network);

    int binarysize = (subsize + netsize + numberOfHosts);
    char *sub_binary = (char *)malloc((binarysize+1) * sizeof(char));
    char *net_binary = (char *)malloc((binarysize+1)*sizeof(char));
    char delim = '.';
    char *subptr = strtok(subnet, &delim);
    char *netptr = strtok(network, &delim);

    if( sub_binary == NULL || net_binary == NULL){
        printf("Error");
        exit(1);
    }
    int countsub = 0;
    int countnet = 0;
    while (subptr != NULL)
    {
        printf("%s\n", subptr);
        strcpy(&sub_binary[countsub], subptr);
        subptr = strtok(NULL, &delim);
        countsub+=1;

    }
    while (netptr != NULL)
    {
        printf("%s\n", netptr);
        strcpy(&net_binary[countnet], netptr);
        netptr = strtok(NULL, &delim);
        countnet+=1;

    }
    sub_binary[binarysize] = '\0';
    net_binary[binarysize] = '\0';
    free(sub_binary);
    free(net_binary);
}
