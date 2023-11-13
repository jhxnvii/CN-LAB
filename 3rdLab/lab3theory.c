/* 1.Network byte order and host byte order
2.Extract bites from msb to lsb but in host byte it is reverse.   
3.Socket: lies between application and transport.(7 layers)
4.Interface that connects ethernet to device.
5.Source, destination and communication channel requires for a communication to occur.
6.  server                           client
    
    process                          process
    socket                           socket
    transport                        transport
    network                          network
    link                             link
    physical  <----internet---->     physical
7.STREAM SOCKETS:(SOCK_STREAM)
8.DATAGRAM SOCKETS(SOCK_DGRAM)
9. int socket(int domain, int type, int protocol)
-> domain should be PF_INET
-> type can be SOCK_STREAM or SOCK_DGRAM
-> set protocol to 0
-> -1 on error
ex: in sockfd;
    sockfd: socket(PF_INET,SOCK_STREAM,0);
10. SOCKET STRUCTURES: information related to socket address.   --> holds (i)address family (ii)protocol address
  ex: struct sockaddr_in{
    short int, sin_family; , ...etc}
--> sin_port and sin_addr must be in network byte order.
11. DEALING WITH IP ADDRESSES 
 int inet_atom(char*cp,struct in_addr*inp);
 --> inet_atom gives non-zero on success.
-->For binding: file descriptor, structure , address length
int bind(int sockfd,struct sockaddr*my_addr,int addrlen)

*/