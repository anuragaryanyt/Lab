#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>

int main(void)
{

    int socket_desc;
    struct sockaddr_in server_addr;
    char server_message[2000], client_message[2000];
    int server_struct_length = sizeof(server_addr);

    memset(server_message, '\0', sizeof(server_message));
    memset(client_message, '\0', sizeof(client_message));

    socket_desc = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);

    if (socket_desc < 0)
    {
        printf("Error while creating socket\n");
        return -1;
    }
    printf("Socket created successfully\n");

    // Set port and IP:
    // bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(2000);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // char *message= "hello server";
    printf("enter msg:");
    gets(client_message);

    if (sendto(socket_desc, client_message, strlen(client_message), 0, (struct sockaddr *)&server_addr, server_struct_length) < 0)
    {
        printf("unable to send!!\n");
        return -1;
    }

    if (recvfrom(socket_desc, server_message, sizeof(server_message), 0, (struct sockaddr *)&server_addr, &server_struct_length) < 0)
    {
        printf("error while recieving!!\n");
        return -1;
    }

    printf("server response: %s\n", server_message);
    // close(socket_desc);

    return 0;
}
