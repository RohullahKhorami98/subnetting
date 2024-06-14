

### Class C Subnetting for 8 Subnets

We have a Class C network 192.168.1.0 and we need to create 8 subnets. Below are the steps to calculate the subnet mask, network addresses, broadcast addresses, and host ranges for each subnet.

#### Step-by-Step Process:

1. **Determine the number of bits to borrow:**
   - To create 8 subnets, we need to borrow 3 bits from the host portion (since 2^3 = 8).

2. **Convert the network address to binary and indicate the borrowed bits:**
   - The original network address in binary is:
     ```
     192      .168      .1        .0
     11000000 .10101000 .00000001 .00000000
     ```
   - After borrowing 3 bits from the host portion:
     ```
     11000000 .10101000 .00000001 .XXX00000
     ```

3. **Determine the new subnet mask:**
   - Original subnet mask for a Class C network: 255.255.255.0 (binary: 11111111.11111111.11111111.00000000)
   - New subnet mask after borrowing 3 bits:
     ```
     11111111 .11111111 .11111111 .11100000
     ```
   - Converting to decimal notation:
     ```
     255      .255      .255      .224
     ```
   - New subnet mask: **255.255.255.224**

4. **Calculate the subnet network addresses:**
   - With 3 borrowed bits, we have 8 combinations. Here are the network addresses for each subnet:

     - **Subnet 1:**
       ```
       11000000 .10101000 .00000001 .00000000
       192      .168      .1        .0
       ```

     - **Subnet 2:**
       ```
       11000000 .10101000 .00000001 .00100000
       192      .168      .1        .32
       ```

     - **Subnet 3:**
       ```
       11000000 .10101000 .00000001 .01000000
       192      .168      .1        .64
       ```

     - **Subnet 4:**
       ```
       11000000 .10101000 .00000001 .01100000
       192      .168      .1        .96
       ```

     - **Subnet 5:**
       ```
       11000000 .10101000 .00000001 .10000000
       192      .168      .1        .128
       ```

     - **Subnet 6:**
       ```
       11000000 .10101000 .00000001 .10100000
       192      .168      .1        .160
       ```

     - **Subnet 7:**
       ```
       11000000 .10101000 .00000001 .11000000
       192      .168      .1        .192
       ```

     - **Subnet 8:**
       ```
       11000000 .10101000 .00000001 .11100000
       192      .168      .1        .224
       ```

5. **Calculate the broadcast addresses:**
   - The broadcast address is obtained by setting all host bits to 1.

     - **Broadcast for Subnet 1:**
       ```
       11000000 .10101000 .00000001 .00011111
       192      .168      .1        .31
       ```

     - **Broadcast for Subnet 2:**
       ```
       11000000 .10101000 .00000001 .00111111
       192      .168      .1        .63
       ```

     - **Broadcast for Subnet 3:**
       ```
       11000000 .10101000 .00000001 .01011111
       192      .168      .1        .95
       ```

     - **Broadcast for Subnet 4:**
       ```
       11000000 .10101000 .00000001 .01111111
       192      .168      .1        .127
       ```

     - **Broadcast for Subnet 5:**
       ```
       11000000 .10101000 .00000001 .10011111
       192      .168      .1        .159
       ```

     - **Broadcast for Subnet 6:**
       ```
       11000000 .10101000 .00000001 .10111111
       192      .168      .1        .191
       ```

     - **Broadcast for Subnet 7:**
       ```
       11000000 .10101000 .00000001 .11011111
       192      .168      .1        .223
       ```

     - **Broadcast for Subnet 8:**
       ```
       11000000 .10101000 .00000001 .11111111
       192      .168      .1        .255
       ```

6. **Determine the range of host addresses:**
   - The range is between the network address and the broadcast address, excluding both.

     - **Range for Subnet 1:**
       ```
       192.168.1.1 – 192.168.1.30
       ```

     - **Range for Subnet 2:**
       ```
       192.168.1.33 – 192.168.1.62
       ```

     - **Range for Subnet 3:**
       ```
       192.168.1.65 – 192.168.1.94
       ```

     - **Range for Subnet 4:**
       ```
       192.168.1.97 – 192.168.1.126
       ```

     - **Range for Subnet 5:**
       ```
       192.168.1.129 – 192.168.1.158
       ```

     - **Range for Subnet 6:**
       ```
       192.168.1.161 – 192.168.1.190
       ```

     - **Range for Subnet 7:**
       ```
       192.168.1.193 – 192.168.1.222
       ```

     - **Range for Subnet 8:**
       ```
       192.168.1.225 – 192.168.1.254
       ```

### Summary for Class C Subnetting with 8 Subnets:

- **Subnet Mask:** 255.255.255.224
- **Subnets and their corresponding Network Addresses, Broadcast Addresses, and Host Ranges:**

| Subnet | Network Address | Broadcast Address | Host Range               |
|--------|-----------------|-------------------|--------------------------|
| 1      | 192.168.1.0     | 192.168.1.31      | 192.168.1.1 – 192.168.1.30 |
| 2      | 192.168.1.32    | 192.168.1.63      | 192.168.1.33 – 192.168.1.62 |
| 3      | 192.168.1.64    | 192.168.1.95      | 192.168.1.65 – 192.168.1.94 |
| 4      | 192.168.1.96    | 192.168.1.127     | 192.168.1.97 – 192.168.1.126 |
| 5      | 192.168.1.128   | 192.168.1.159     | 192.168.1.129 – 192.168.1.158 |
| 6      | 192.168.1.160   | 192.168.1.191     | 192.168.1.161 – 192.168.1.190 |
| 7      | 192.168.1.192   | 192.168.1.223     | 192.168.1.193 – 192.168.1.222 |
| 8      | 192.168.1.224   | 192.168.1.255     | 192.168.1.225 – 192.168.1.254 |

---

### Class A Subnetting Example for 16 Subnets

Given a Class A network 10.0.0.0, let's divide it into 16 subnets.

#### Step-by-Step Process:

1. **Determine the number of bits to borrow:**
   - To create 16 subnets, we need to borrow 4 bits from the host portion (since 2^4 = 16).

2. **Original Class A network address:**
   ```
   10      .0       .0       .0
   00001010.00000000.00000000.00000000
   ```

3. **Borrowing 4 bits for subnetting:**
   ```
   00001010.0000XXXX.00000000.00000000
   ```

4. **New subnet mask:**
   - Original subnet mask for Class A: 255.0.0.0 (

binary: 11111111.00000000.00000000.00000000)
   - New subnet mask after borrowing 4 bits:
     ```
     11111111.11110000.00000000.00000000
     ```
   - Converting to decimal notation:
     ```
     255      .240      .0        .0
     ```
   - New subnet mask: **255.240.0.0**

5. **Calculate the subnet network addresses:**
   - With 4 borrowed bits, we have 16 combinations. Here are the first few:

     - **Subnet 1:**
       ```
       00001010.00000000.00000000.00000000
       10      .0       .0       .0
       ```

     - **Subnet 2:**
       ```
       00001010.00010000.00000000.00000000
       10      .16      .0       .0
       ```

     - **Subnet 3:**
       ```
       00001010.00100000.00000000.00000000
       10      .32      .0       .0
       ```

     - **Subnet 4:**
       ```
       00001010.00110000.00000000.00000000
       10      .48      .0       .0
       ```

     - **Subnet 5:**
       ```
       00001010.01000000.00000000.00000000
       10      .64      .0       .0
       ```

6. **Broadcast addresses and host ranges:**
   - The broadcast address is obtained by setting all host bits to 1.

     - **Broadcast for Subnet 1:**
       ```
       00001010.00001111.11111111.11111111
       10      .15      .255     .255
       ```

     - **Broadcast for Subnet 2:**
       ```
       00001010.00011111.11111111.11111111
       10      .31      .255     .255
       ```

     - **Broadcast for Subnet 3:**
       ```
       00001010.00101111.11111111.11111111
       10      .47      .255     .255
       ```

     - **Broadcast for Subnet 4:**
       ```
       00001010.00111111.11111111.11111111
       10      .63      .255     .255
       ```

     - **Broadcast for Subnet 5:**
       ```
       00001010.01001111.11111111.11111111
       10      .79      .255     .255
       ```

7. **Determine the range of host addresses:**
   - The range is between the network address and the broadcast address, excluding both.

     - **Range for Subnet 1:**
       ```
       10.0.0.1 – 10.15.255.254
       ```

     - **Range for Subnet 2:**
       ```
       10.16.0.1 – 10.31.255.254
       ```

     - **Range for Subnet 3:**
       ```
       10.32.0.1 – 10.47.255.254
       ```

     - **Range for Subnet 4:**
       ```
       10.48.0.1 – 10.63.255.254
       ```

     - **Range for Subnet 5:**
       ```
       10.64.0.1 – 10.79.255.254
       ```

### Summary for Class A Subnetting with 16 Subnets:

- **Subnet Mask:** 255.240.0.0
- **Subnets and their corresponding Network Addresses, Broadcast Addresses, and Host Ranges:**

| Subnet | Network Address | Broadcast Address | Host Range               |
|--------|-----------------|-------------------|--------------------------|
| 1      | 10.0.0.0        | 10.15.255.255     | 10.0.0.1 – 10.15.255.254 |
| 2      | 10.16.0.0       | 10.31.255.255     | 10.16.0.1 – 10.31.255.254 |
| 3      | 10.32.0.0       | 10.47.255.255     | 10.32.0.1 – 10.47.255.254 |
| 4      | 10.48.0.0       | 10.63.255.255     | 10.48.0.1 – 10.63.255.254 |
| 5      | 10.64.0.0       | 10.79.255.255     | 10.64.0.1 – 10.79.255.254 |
| ...    | ...             | ...               | ...                      |

---

### Class B Subnetting Example for 32 Subnets

Given a Class B network 172.16.0.0, let's divide it into 32 subnets.

#### Step-by-Step Process:

1. **Determine the number of bits to borrow:**
   - To create 32 subnets, we need to borrow 5 bits from the host portion (since 2^5 = 32).

2. **Original Class B network address:**
   ```
   172      .16      .0       .0
   10101100 .00010000 .00000000 .00000000
   ```

3. **Borrowing 5 bits for subnetting:**
   ```
   10101100 .00010XXXX .00000000 .00000000
   ```

4. **New subnet mask:**
   - Original subnet mask for Class B: 255.255.0.0 (binary: 11111111.11111111.00000000.00000000)
   - New subnet mask after borrowing 5 bits:
     ```
     11111111 .11111111 .11111000 .00000000
     ```
   - Converting to decimal notation:
     ```
     255      .255      .248      .0
     ```
   - New subnet mask: **255.255.248.0**

5. **Calculate the subnet network addresses:**
   - With 5 borrowed bits, we have 32 combinations. Here are the first few:

     - **Subnet 1:**
       ```
       10101100 .00010000 .00000000 .00000000
       172      .16      .0       .0
       ```

     - **Subnet 2:**
       ```
       10101100 .00010001 .00000000 .00000000
       172      .16      .8       .0
       ```

     - **Subnet 3:**
       ```
       10101100 .00010010 .00000000 .00000000
       172      .16      .16      .0
       ```

     - **Subnet 4:**
       ```
       10101100 .00010011 .00000000 .00000000
       172      .16      .24      .0
       ```

     - **Subnet 5:**
       ```
       10101100 .00010100 .00000000 .00000000
       172      .16      .32      .0
       ```

6. **Broadcast addresses and host ranges:**
   - The broadcast address is obtained by setting all host bits to 1.

     - **Broadcast for Subnet 1:**
       ```
       10101100 .00010000 .00000111 .11111111
       172      .16      .7       .255
       ```

     - **Broadcast for Subnet 2:**
       ```
       10101100 .00010001 .00000111 .11111111
       172      .16      .15      .255
       ```

     - **Broadcast for Subnet 3:**
       ```
       10101100 .00010010 .00000111 .11111111
       172      .16      .23      .255
       ```

     - **Broadcast for Subnet 4:**
       ```
       10101100 .00010011 .00000111 .11111111
       172      .16      .31      .255
       ```

     - **Broadcast for Subnet 5:**
       ```
       10101100 .00010100 .00000111 .11111111
       172      .16      .39      .255
       ```

7. **Determine the range of host addresses:**
   - The range is between the network address and the broadcast address, excluding both.

     - **Range for Subnet 1:**
       ```
       172.16.0.1 – 172.16.7.254
       ```

     - **Range for Subnet 2:**
       ```
       172.16.8.1 – 172.16.15.254
       ```

     - **Range for Subnet 3:**
       ```
       172.16.16.1 – 172.16.23.254
       ```

     - **Range for Subnet 4:**
       ```


       172.16.24.1 – 172.16.31.254
       ```

     - **Range for Subnet 5:**
       ```
       172.16.32.1 – 172.16.39.254
       ```

### Summary for Class B Subnetting with 32 Subnets:

- **Subnet Mask:** 255.255.248.0
- **Subnets and their corresponding Network Addresses, Broadcast Addresses, and Host Ranges:**

| Subnet | Network Address | Broadcast Address | Host Range               |
|--------|-----------------|-------------------|--------------------------|
| 1      | 172.16.0.0      | 172.16.7.255      | 172.16.0.1 – 172.16.7.254 |
| 2      | 172.16.8.0      | 172.16.15.255     | 172.16.8.1 – 172.16.15.254 |
| 3      | 172.16.16.0     | 172.16.23.255     | 172.16.16.1 – 172.16.23.254 |
| 4      | 172.16.24.0     | 172.16.31.255     | 172.16.24.1 – 172.16.31.254 |
| 5      | 172.16.32.0     | 172.16.39.255     | 172.16.32.1 – 172.16.39.254 |
| ...    | ...             | ...               | ...                      |

