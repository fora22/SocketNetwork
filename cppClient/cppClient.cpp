#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#include <random>
#include <thread>
#include <chrono>
#pragma comment (lib , "ws2_32.lib")
#define SERVER_PORT 11235
#define SERVER_IP_ADDRES "127.0.0.1"
using namespace std;


int main(void)
{
	WSADATA wsaData;
	SOCKADDR_IN target;
	

	int err = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (err != 0) {
		cout << "WSASartup error " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}

	target.sin_family = AF_INET;
	target.sin_port = htons(SERVER_PORT);
	target.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRES);

	SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (clientSocket == INVALID_SOCKET) {
		cout << "Socket error : " << WSAGetLastError() << endl;
		WSACleanup();
		return 0;
	}




	return 0;
}
