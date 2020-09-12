#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#include <random>
#include <thread>
#include <chrono>
#pragma comment (lib , "ws2_32.lib")
using namespace std;


int makeRand(void)
{
	// 무엇?
	random_device rd;
	mt19937 rng(rd());
	uniform_int_distribution<int> ud(1, 1024);

	return ud(rng);
}

int main(void)
{
	WSADATA wsaData;
	SOCKADDR_IN serverAdress, clientAdress;
	int err;

	err = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (err != 0) {
		cout << "WSAStartup error " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}

	serverAdress.sin_family = AF_INET; // AF_INET은 뭔지??
	serverAdress.sin_port = htons(11235);
	serverAdress.sin_addr.s_addr = inet_addr("127.0.0.1"); // s_addr은 그냥 쓰던데 왜?

	SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (serverSocket == INVALID_SOCKET)
	{
		cout << "Socket Error" << WSAGetLastError() << endl;
		WSACleanup();
		return false; // 소켓 생성 실패시 실행
	}

	if (bind(serverSocket, reinterpret_cast<SOCKADDR*> (&serverAdress), sizeof(serverAdress)))
	{
		// reinterpret_cast에서 cast가 먼지?
		cout << "Binding failed. Error code : " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}
	
	cout << "client를 기다립니다." << endl;

	listen(serverSocket, 5); // backlog(5)가 먼지?
	int xx = sizeof(clientAdress);
	SOCKET clientSocket = accept(serverSocket, reinterpret_cast<SOCKADDR*> (&clientAdress), &xx); // bind에서는 그냥 sizeof 쓰던데 왜 얘는 &(주소값)인지?
	cout << "Connection Complete" << "새로운 Socket은 " << clientSocket << endl;

	int receiveNumber;
	char communicationBuffer[100];
	int iRand;
	int bytesSent;
	while (TRUE)
	{
		receiveNumber = recv(clientSocket, communicationBuffer, 100, 0); // flag는 뭔지?
		if (receiveNumber <= 0) { cout << "Got nothing" << endl; break; }
		communicationBuffer[receiveNumber] = 0;

		if (!strcmp(communicationBuffer, "Hello"))
		{
			iRand = makeRand();
			auto sRand = to_string(iRand);
			cout << "Sending Random Number " << iRand << "to the client" << endl;
			bytesSent = send(clientSocket, sRand.c_str(), sRand.length(), 0);

			continue;
		}
		string sNumber(communicationBuffer);
		try
		{
			iRand = stoi(sNumber);
			cout << "Server got " << "\"" << iRand << "\"" << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "Sending \"" << iRand++ << "\"" << " to Client" << endl;
			auto sRand = to_string(iRand);
			bytesSent = send(clientSocket, sRand.c_str(), sRand.length(), 0);
		}
		catch (const invalid_argument& ex)
		{
			cerr << "Invalid argument while converting string to number" << endl;
			cerr << "Error : " << ex.what() << endl;
			break;
		}
		catch (const out_of_range& ex)
		{
			cerr << "Invalid argument while converting string to number" << endl;
			cerr << "Error : " << ex.what() << endl;
			break;
		}
	}
	
	closesocket(serverSocket);
	WSACleanup();

	return 0;
}