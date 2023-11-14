#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define PORT 12345

int main() {
    int client_socket;
    struct sockaddr_in server_addr;
    char message[1024];

    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Connection failed");
        exit(1);
    }

    while (1) {
        // Read input from user
        printf("Enter a number or message for Client 1: ");
        fgets(message, sizeof(message), stdin);

        // Send data to the server
        if (send(client_socket, message, strlen(message), 0) == -1) {
            perror("Send error");
            exit(1);
        }
    }

    // Close the client socket
    close(client_socket);

    return 0;
}
