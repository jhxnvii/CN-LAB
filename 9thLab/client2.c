#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the port number
#define PORT 8080

// Main function
int main() {
  // Create a TCP client socket
  int client_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (client_socket < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Connect to the server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if (connect(client_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Connect failed");
    exit(1);
  }

  // Receive the result from the server
  int result;
  int recv_size = recv(client_socket, &result, sizeof(result), 0);
  if (recv_size < 0) {
    perror("Receive failed");
    exit(1);
  }

  // Display the result
  if (result) {
    printf("The number is a prime number.\n");
  } else {
    printf("The number is not a prime number.\n");
  }

  // Close the socket
  close(client_socket);

  return 0;
}