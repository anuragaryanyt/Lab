#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int client_socket;
    struct sockaddr_in server_addr;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0)
    {
        perror("Error in socket creation");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(client_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        perror("Error in connection");
        exit(1);
    }

    char choice;
    double num1, num2, result;

    while (1)
    {
        // Receive menu from the server
        char menu[255];
        recv(client_socket, menu, sizeof(menu), 0);
        printf("%s", menu);

        // Send choice to the server
        scanf(" %c", &choice);
        send(client_socket, &choice, sizeof(char), 0);

        if (choice == '5')
        {
            printf("Exiting.\n");
            break;
        }

        // Send operands to the server
        printf("Enter operand 1: ");
        scanf("%lf", &num1);
        printf("Enter operand 2: ");
        scanf("%lf", &num2);
        send(client_socket, &num1, sizeof(double), 0);
        send(client_socket, &num2, sizeof(double), 0);

        // Receive result from the server
        recv(client_socket, &result, sizeof(double), 0);

        // Display result on the client side
        printf("Result: %lf\n", result);
    }

    close(client_socket);

    return 0;
}