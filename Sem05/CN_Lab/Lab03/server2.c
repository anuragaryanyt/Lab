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
	char buf[100];	// server
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

	int bd = bind(sockfd, (struct sockaddr *)&server, sizeof(server));
	if (bd == -1)
	{
		printf("Binding  Error\n");
		exit(0);
	}
	else
	{
		printf("\nBinding successfull");
	}

	while (strcmp(buff, "Exit") != 0 && strcmp(buf, "Exit") != 0)
	{
		// Receive from client
		struct sockaddr_in client;
		int len = sizeof(client);
		int r = recvfrom(sockfd, (char *)buff, 100, 0, (struct sockaddr *)&client, &len);
		buff[r] = '\0';
		printf("\nClient: %s\n", buff);

		// Send from server
		printf("Enter Message: ");
		scanf(" %[^\n]", buf);
		int l = strlen(buf);
		int s = sendto(sockfd, (char *)buf, l, 0, (const struct sockaddr *)&client, sizeof(client));
		if (s == -1)
		{
			printf("Message send unsuccessful\n");
		}
	}

	close(sockfd);
	return 0;
}
