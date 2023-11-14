//WAP where the client sends the no. to server , server finds out the square root and returns the result back to the client.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <math.h>

int main() {
    int serverSocket, newSocket;
    struct sockaddr_in serverAddr, newAddr;
    socklen_t addrSize;
    char buffer[1024];

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        perror("Error in socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change the port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Bind error");
        exit(1);
    }

    if (listen(serverSocket, 10) < 0) {
        perror("Error in listening");
        exit(1);
    }

    printf("Server is listening...\n");

    addrSize = sizeof(newAddr);
    newSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addrSize);

    while (1) {
        strcpy(buffer, "Enter a number to find its square root: ");
        send(newSocket, buffer, strlen(buffer), 0);
        recv(newSocket, buffer, 1024, 0);
        
        double num = atof(buffer);
        if (num < 0) {
            strcpy(buffer, "Invalid input. Please enter a non-negative number.\n");
        } else {
            double result = sqrt(num);
            sprintf(buffer, "Square root of %.2lf is %.2lf\n", num, result);
        }

        send(newSocket, buffer, strlen(buffer), 0);
    }

    close(newSocket);
    close(serverSocket);
    return 0;
}
