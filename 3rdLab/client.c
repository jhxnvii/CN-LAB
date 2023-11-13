#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>  
#include <unistd.h> 


int main() {
    // Create a socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    printf("Client socket created successfully.\n");

    // Clean up and close the socket
    close(client_socket);

    return 0;
}
