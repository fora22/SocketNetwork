#define _CRT_SECURE_NO_WARNINGS
// #define _WINSOCK_DEPRECATED Sever_NO_WARNINGS to disable deprecated API warnings

#include <WinSock2.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <memory.h>

void* recvThread(void*);
char buffer[1024];

int main(void) {
	// this is Server
	WSADATA wsa_data;
	SOCKET h_socket;
	SOCKADDR_IN sever_addr;

	SOCKET accept_socket;
	SOCKADDR accept_addr;
	int accept_addr_size;

	int data_size = 0;
	char* data;
	pthread_t recv_thr;

	// init
	WSAStartup(MAKEWORD(2, 2), &wsa_data);
	h_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	sever_addr.sin_family = AF_INET;
	sever_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	sever_addr.sin_port = 19923;

	accept_addr_size = sizeof(accept_addr);

	// error check
	if (h_socket == INVALID_SOCKET) {
		log("invalid socket");
		return 0;
	}

	if (bind(h_socket, (LPSOCKADDR)&sever_addr, sizeof(sever_addr) != ERROR_SUCCESS)) {
		log("fail bind()");
		return 0;
	}
	if (listen(h_socket, SOMAXCONN) != ERROR_SUCCESS) {
		log("fail listen()");
		return 0;
	}

	// accept() sync

	log("be waiting for client");
	accept_socket = accept(h_socket, (LPSOCKADDR)&accept_addr, &accept_addr_size);
	log("connect client");

	pthread_create(&recv_thr, NULL, recvThread, (void*)&accept_socket);

	while (1) {
		// init buffer
		memset(buffer, '\0', 1024);
		gets(buffer);

		data_size = strlen(buffer) + 1;
		data = (char*)malloc(data_size);
		memset(data, '\0', data_size);

		strcpy(data, buffer);

		send(accept_socket, (char*)&data_size, sizeof(int), 0);
		send(accept_socket, (char*)data, data_size, 0);

		memset(data, '\0', data_size);
		memset(buffer, '\0', 1024);
		free(data);
		data_size = 0;
	}

	return 0;
}

void* recvThread(void* parm) {
	int data_size;
	char* data;

	while (1) {
		recv(*((SOCKET*)parm), (char*)&data_size, sizeof(int), 0);
		data = (char*)malloc(data_size);
		memset(data, '\0', data_size);
		recv(*((SOCKET*)parm), (char*)&data_size, sizeof(int), 0);

		printf("%s\n", data);

		memset(data, '\0', data_size);
		free(data);
	}
	return NULL;
}