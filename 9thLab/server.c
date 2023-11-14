//q. WAP in c where 2 clients and 1 server/ client 1 sends a no. and client 2 checks whether the no. is a 
//perfect no. or not a display it.

//Create a TCP socket with client sending a number to server and will check whether it's a prime number or not
//display on client.Send a number to server and check whether it's a perfect number or not and result in client.


#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Define the port number
#define PORT 8080

// Check if a number is a prime number
int is_prime(int number) {
  if (number < 2) {
    return 0;
  }
  for (int i = 2; i <= number / 2; i++) {
    if (number % i == 0) {
      return 0;
    }
  }
  return 1;
}

// Main function
int main() {
  // Create a TCP server socket
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);
  if (server_socket < 0) {
    perror("Socket creation failed");
    exit(1);
  }

  // Bind the server socket to a port
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(PORT);
  server_address.sin_addr.s_addr = INADDR_ANY;

  if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
    perror("Socket binding failed");
    exit(1);
  }

  // Listen for incoming connections
  if (listen(server_socket, 10) < 0) {
    perror("Listen failed");
    exit(1);
  }

  // Accept an incoming connection from Client 1
  int client_1_socket = accept(server_socket, NULL, NULL);
  if (client_1_socket < 0) {
    perror("Accept failed");
    exit(1);
  }

  // Accept an incoming connection from Client 2
  int client_2_socket = accept(server_socket, NULL, NULL);
  if (client_2_socket < 0) {
    perror("Accept failed");
    exit(1);
  }

  // Receive the number from Client 1
  int number;
  int recv_size = recv(client_1_socket, &number, sizeof(number), 0);
  if (recv_size < 0) {
    perror("Receive failed");
    exit(1);
  }

  // Check if the number is a prime number
  int result = is_prime(number);

  // Send the result to Client 2
  int send_size = send(client_2_socket, &result, sizeof(result), 0);
  if (send_size < 0) {
    perror("Send failed");
    exit(1);
  }

  // Close all sockets
  close(client_1_socket);
  close(client_2_socket);
  close(server_socket);

  return 0;
}