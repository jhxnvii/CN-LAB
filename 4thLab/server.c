#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SERVER_PORT 4952 // the port users will be connecting to
#define MAXBUFLEN 200

int main() {
    int sockfd;
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t addr_len;
    int numbytes;
    char buf[MAXBUFLEN];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
        printf("Socket creation failed");
        exit(1);
    }

    // Set up server address
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(SERVER_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    // Bind the socket to the server address
    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1) {
        printf("Socket binding failed");
        exit(1);
    }

    addr_len = sizeof their_addr;

    // Receive data from clients
    numbytes = recvfrom(sockfd, buf, MAXBUFLEN - 1, 0,
                        (struct sockaddr *)&their_addr, &addr_len);
    if (numbytes == -1) {
        printf("Receiving failed");
        exit(1);
    }

    printf("Got packet from %s\n", inet_ntoa(their_addr.sin_addr));
    printf("Packet is %d bytes long\n", numbytes);
    buf[numbytes] = '\0';
    printf("Packet contains \"%s\"\n", buf);

    // Close the socket
    close(sockfd);
    return 0;
}
