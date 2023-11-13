#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h> 
#include <unistd.h> 


int main() {
    // Create a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Socket creation failed");
        return 1;
    }
    
    // Bind the socket
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY; // Use any available network interface
    server_addr.sin_port = htons(12345); // Port to bind

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("Bind failed");
        close(server_socket);
        return 1;
    }

    printf("Server socket created and bound successfully.\n");

    // Clean up and close the socket
    close(server_socket);

    return 0;
}
