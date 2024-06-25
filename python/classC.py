import math
from itertools import product
"""
This module contains the `classCs` class, which is used for subnetting class C.
Attributes:
    subnet (str): The subnet mask of the network.
    network_address (str): The network address of the network.
    number_of_subnets (int): The number of subnets to be created.

Methods:
    to_binary(subnet, network_address)
        Converts the subnet and network address to binary.
    calculate_number_of_subnets(number_of_subnets)
        Calculates the number of bits needed to represent the number of subnets.
"""

class classCs:
    def __init__(self,subnet: str, network_address: str,number_of_subnets: int) -> None:
        self.subnet = subnet
        self.network_address = network_address
        self.number_of_subnets = number_of_subnets
        
    #### TO BINARY ####
    def to_binary(self):
        sublist = self.subnet.split(".")
        networklist = self.network_address.split(".")
        subbin = [bin(int(x))[2:].zfill(8) for x in sublist]
        networkbin = [bin(int(y))[2:].zfill(8) for y in networklist]
        subbin[-1] = '00000000'
        networkbin[-1] = '00000000'
        return subbin, networkbin
    #### NUMBER OF SUBNETS ####
    def calculate_number_of_subnets(self):
        number_of_bits = math.log2(self.number_of_subnets)
        _ , network_bits = self.to_binary()
        bits = network_bits[-1][:int(number_of_bits)]
        return bits
    #### BIT COMBINATIONS ####
    def bit_combinations(self):
        length_bits = len(self.calculate_number_of_subnets())
        bin_list = [0,1]
        combo = list(product(bin_list, repeat=length_bits))
        bit_combo = ["".join(map(str,c)) for c in combo]
        return bit_combo
    #### GET NETWORK RANGES ####
    def get_network_ranges(self):
        last_sub, last_network = list(), list()
        new_sub  = list()
        subbin, networkbin = self.to_binary()
        bits = self.calculate_number_of_subnets()
        bit_combos = self.bit_combinations()
        sub_temp1 , net_temp2 = subbin[-1], networkbin[-1]
        for i in range(len(bit_combos)):
            last_network.append(bit_combos[i]+net_temp2[:-len(bits)])
        last_sub.append("1"*len(bits)+sub_temp1[len(bits):])
        new_net = [networkbin[:-1] + [x] for x in last_network]
        new_sub = [subbin[:-1] + [y] for y in last_sub]
        ranges = [new_net, new_sub[0]]
        return ranges
    #### GET BROADCAST RANGES ####
    def get_broadcast_ranges(self):
        broad_cast_list = list()
        _, networkbin = self.to_binary()
        bits = self.calculate_number_of_subnets()
        bit_combos = self.bit_combinations()
        broad_cast_temp = networkbin[-1][-len(bits):]+"1"*len(
            networkbin[-1][:-len(bits)])
        for i in range(len(bit_combos)):
            broad_cast_list.append(bit_combos[i]+broad_cast_temp[len(bits):])
        broad_cast_range = [networkbin[:-1]+[x] for x in broad_cast_list]
        return broad_cast_range
    #### Useable IP Ranges ####
    def get_useable_ranges(self):
        network_ranges = self.get_network_ranges()
        broadcast_ranges = self.get_broadcast_ranges()
        useable_ranges = list()
        for (i,j) in zip(network_ranges[0], broadcast_ranges):
            temp_net = int(i[-1],2)
            temp_broad = int(j[-1],2)
            range_list = list()
            count_temp = temp_net
            for k in range(temp_net+1, temp_broad):
                count_temp+=1
                range_list.append(count_temp)
            useable_ranges.append(range_list)
        return useable_ranges
    #### MERGE USEABLE RANGES ####
    def merge_useable_ranges(self):
        useable_ranges = self.get_useable_ranges()
        ranges = self.get_network_ranges()[0]
        integer_ranges = list()
        last_list =  list()
        for i in ranges:
            temp_list = list()
            for j in i[:-1]:
                temp_list.append(int(j,2))
            integer_ranges.append(temp_list)
        for r in range(len(integer_ranges)):
           temp_list = list()
           for l in useable_ranges[r]:
               temp_list.append(integer_ranges[r]+[l])
           last_list.append(temp_list)
        return last_list