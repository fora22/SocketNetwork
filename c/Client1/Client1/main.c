#include <WinSock2.h>
#include <stdio.h>
#include <pthread.h>


typedef struct {
	int fd;
	char ip[20];
}CLIENT;

int main(void) {
	// this is client

	int sockfd;
	char send_c, recv_c;
	char msg[128];
	struct sockaddr_in server;

	return 0;
}