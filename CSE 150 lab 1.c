2. In the output of my pingall, all four hosts can connect to each other. At the same time, all 12 ICMP echo requests were received without packet loss (12/12 0dropped). The "dump" 
command seems to be used to verify the network configuration. From my output, it is not difficult to find that there are a total of four hosts, one switch, and one controller. The IP 
addresses of the four hosts are 10.0.0.1, 10.0.0.2, 10.0.0.3, 10.0.0.4 respectively. The switch has four interfaces, namely s1-eth1, s1-eth2, s1-eth3, s1-eth4. There is also a loopback 
interface ("lo"). Finally there is the controller named "c0". It has an IP address of 127.0.0.1. Its port number is 6633. At the same time, the above four hosts and controllers have 
unique pids to be marked.

3. The TCP bandwidth between hosts h1 and h4 has been tested to be 22.0 Gbits/sec in both directions.

4. 1. According to the result, six "of_packet_in" messages popped up.