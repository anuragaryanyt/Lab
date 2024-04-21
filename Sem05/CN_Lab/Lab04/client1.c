#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int client_socket;
    struct sockaddr_in server_address;
    char expression[BUFFER_SIZE];

    // Create socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address struct
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");  // Server IP address
    server_address.sin_port = htons(8080);  // Server port

    // Connect to the server
    if (connect(client_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Get user input for a mathematical expression
    printf("Enter a mathematical expression (e.g., 2 + 3): ");
    fgets(expression, sizeof(expression), stdin);

    // Send the expression to the server
    send(client_socket, expression, strlen(expression), 0);

    // Receive and print the result from the server
    char result[BUFFER_SIZE];
    recv(client_socket, result, sizeof(result), 0);
    printf("Result from server: %s\n", result);

    // Close the client socket
    close(client_socket);

    return 0;
}

