#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

double calculate(double num1, double num2, char operator)
{
    switch (operator)
    {
    case '+':
        return num1 + num2;
    case '-':
        return num1 - num2;
    case '*':
        return num1 * num2;
    case '/':
        if (num2 != 0)
            return num1 / num2;
        else
            return -1; // Division by zero error
    default:
        return -1; // Invalid operator
    }
}

int main()
{
    int server_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0)
    {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in binding");
        exit(1);
    }

    if (listen(server_socket, 10) == 0)
    {
        printf("Server listening on port %d...\n", PORT);
    }
    else
    {
        perror("Error in listening");
        exit(1);
    }

    addr_size = sizeof(client_addr);
    int new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);

    char message[255];
    double num1, num2, result;
    char operator;

    while (1)
    {
        // Send menu to the client
        strcpy(message, "Menu:\n1. Addition(+)\n2. Subtraction(-)\n3. Multiplication(*)\n4. Division(/)\n5. Exit\nEnter your choice: ");
        send(new_socket, message, sizeof(message), 0);

        // Receive choice from the client
        recv(new_socket, &operator, sizeof(char), 0);

        if (operator== '5')
        {
            printf("Client requested exit. Closing connection.\n");
            break;
        }

        // Receive operands from the client
        recv(new_socket, &num1, sizeof(double), 0);
        recv(new_socket, &num2, sizeof(double), 0);

        // Calculate the result
        result = calculate(num1, num2, operator);

        // Send result to the client
        send(new_socket, &result, sizeof(double), 0);

        // Display result on the server side
        printf("Result: %lf\n", result);
    }

    close(new_socket);
    close(server_socket);

    return 0;
}