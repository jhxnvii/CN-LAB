#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 12345
#define MAX_CLIENTS 2

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    // Create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Binding failed");
        exit(1);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Listening failed");
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept connections from clients
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client_socket[i] = accept(server_socket, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_socket[i] == -1) {
            perror("Acceptance failed");
            exit(1);
        }
        printf("Client %d connected\n", i + 1);

        // Create a thread to handle this client
        pthread_t tid;
        pthread_create(&tid, NULL, (void*)&handle_client, &client_socket[i]);
    }

    // Close server socket
    close(server_socket);

    return 0;
}

void handle_client(int client_socket) {
    char buffer[1024];
    int num;

    while (1) {
        // Receive data from client
        if (recv(client_socket, buffer, sizeof(buffer), 0) == -1) {
            perror("Receive error");
            exit(1);
        }

        // Parse the received data
        if (sscanf(buffer, "%d", &num) == 1) {
            printf("Received number from client: %d\n", num);
        } else {
            printf("Client message: %s\n", buffer);
        }

        // Send data back to client
        if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
            perror("Send error");
            exit(1);
        }
    }
}
