import classC as C
import argparse
import pandas as pd # type: ignore
def info(Class_choice):
    print("SUBNETTING Class {}".format(Class_choice))
    network_address = input("Enter the network address: ")
    subnet = input("Enter the subnet: ")
    num_subnets = input("Enter the number of subnets: ")
    return (network_address, subnet, num_subnets)
if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        usage='python subnetting.py -S <class> / --SubnetClass <class>',
        description='SUBNETTING class A, B, C',)
    parser.add_argument('-s','--SubnetClass' ,choices={'C':'ClassC','B':'ClassB','A':'ClassA'} , help='Select the class', type=str)
    args = parser.parse_args()
   
    if args.SubnetClass == 'A':
        print("SUBNETTING Class A")
    elif args.SubnetClass == 'B':
       print("SUBNETTING Class B")
    elif args.SubnetClass == 'C':
        column_name = "Subnet "
        subnet =input("Enter the subnet: ")
        network_address = input("Enter the network address: ")
        num_subnets = int(input("Enter the number of subnets: "))

        s = C.classCs(subnet, network_address,num_subnets)
        usable_ranges = s.merge_useable_ranges()
        table_header = [column_name+str(x) for x in range(1, len(usable_ranges)+1)]
        df = pd.DataFrame(usable_ranges).transpose()
        df.columns = table_header
        final_table = df.to_string(index=False)
        print(final_table)
    else:
        print("Invalid Class")