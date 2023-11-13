#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int is_armstrong(int num) {
    int originalNum, remainder, result = 0, n = 0;
    originalNum = num;

    while (originalNum != 0) {
        originalNum /= 10;
        ++n;
    }

    originalNum = num;
    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += pow(remainder, n);
        originalNum /= 10;
    }

    return (result == num);
}

int main() {
    int serverSocket, newSocket;    //sd , main , new 
    struct sockaddr_in serverAddr, newAddr;
    socklen_t addrSize; // store size of socket add.
    char buffer[1024];   receiving or sending data btw. client and server.

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

    if (listen(serverSocket, 10) < 0) { //10 indicates max no. of clients that can wait to connect in server's queue
        perror("Error in listening");
        exit(1);
    }

    printf("Server is listening...\n");

    addrSize = sizeof(newAddr);
    newSocket = accept(serverSocket, (struct sockaddr*)&newAddr, &addrSize);

    while (1) {
        strcpy(buffer, "Enter a number (or 'exit' to quit): ");
        send(newSocket, buffer, strlen(buffer), 0);
        recv(newSocket, buffer, 1024, 0);

        if (strcmp(buffer, "exit\n") == 0) {
            printf("Server shutting down...\n");
            break;
        } // check whether client has sent the msg or not.

        int num = atoi(buffer);
        if (is_armstrong(num)) {
            strcpy(buffer, "The number is an Armstrong number.\n");
        } else {
            strcpy(buffer, "The number is not an Armstrong number.\n");
        }
        send(newSocket, buffer, strlen(buffer), 0);
    }

    close(newSocket);
    close(serverSocket);
    return 0;
}
