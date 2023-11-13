#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main() {
    int clientSocket;
    char buffer[1024];
    struct sockaddr_in serverAddr;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0) {
        perror("Error in socket");
        exit(1);
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(12345); // Change the port as needed
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Error in connection");
        exit(1);
    }

    while (1) {
        recv(clientSocket, buffer, 1024, 0);
        printf("%s", buffer);

        fgets(buffer, 1024, stdin);
        send(clientSocket, buffer, strlen(buffer), 0);

        recv(clientSocket, buffer, 1024, 0);
        printf("Server response:\n%s", buffer);
    }

    close(clientSocket);
    return 0;
}
