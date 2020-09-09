#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#pragma comment (lib , "ws2_32.lib")
using namespace std;

void ErrorHandling(const string message)
{
	cout << message << endl;
}

int main(void)
{
	WSADATA data;
	::WSAStartup(MAKEWORD(2, 2), &data);

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (server == INVALID_SOCKET)
	{
		ErrorHandling("서버 생성 실패");
	}


	return 0;
}