// UDP

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int sockfd;
    char buff[100]; // client
    char buf[100];  // serevr
    struct sockaddr_in server;
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    if (sockfd == -1)
    {
        printf("Socket not created\n");
        exit(0);
    }
    else
    {
        printf("Socket created successfully\n");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(2000);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    while (strcmp(buff, "Exit") != 0 && strcmp(buf, "Exit") != 0)
    {
        // Send from client
        printf("Enter Message: ");
        scanf(" %[^\n]", buff);
        int len = strlen(buff);
        int s = sendto(sockfd, (char *)buff, len, 0, (const struct sockaddr *)&server, sizeof(server));
        if (s == -1)
        {
            printf("Message send unsuccessful\n");
        }

        // Receive from server
        int l = sizeof(server);
        int r = recvfrom(sockfd, (char *)buf, 100, 0, (struct sockaddr *)&server, &l);
        buf[r] = '\0';
        printf("\nMessage is: %s\n", buf);
    }

    close(sockfd);
    return 0;
}
