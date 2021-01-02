#define HAVE_STRUCT_TIMESPEC
#define SERVER_PORT 11235
#define SERVER_IP_ADDRES "127.0.0.1"
#define BUFFER_SIZE 8192	// 1024 * 8 byte

#include <iostream>
#include <string>
#include <WinSock2.h>
#include <pthread.h>

#pragma comment (lib , "ws2_32.lib")

using namespace std;

struct socketArg
{
	SOCKET* recvSocket;
	char* buffer;
	string* rMessage;
};

void socketSend(SOCKET* sendSocket, string* sMessage) {
	int sendCheck;
	sendCheck = send(*sendSocket, (*sMessage).c_str(), (*sMessage).length(), 0);
}

//SOCKET* recvSocket, char* buffer, string* rMessage
void *socketReceive(void *socket_arg) {
	socketArg* my_socket_arg = (socketArg*)(socket_arg);	// struct 형으로 cast함
	
	int messageLength = 0 ;
	while (TRUE)
	{
		messageLength = recv(*(my_socket_arg->recvSocket), my_socket_arg->buffer, strlen(my_socket_arg->buffer), 0);
		if (messageLength > 0) {
			my_socket_arg->buffer[messageLength] = 0;
			*(my_socket_arg->rMessage) = my_socket_arg->buffer;
			cout << *(my_socket_arg->rMessage) << endl;
			socketSend((my_socket_arg->recvSocket), (my_socket_arg->rMessage));
		} else {
			cout << "can't recv" << endl;
			exit(1);
		}
	}
}

int main(void) {
	WSADATA wsaData;
	SOCKADDR_IN sAdress, cAdress;		// serverAdress, ClientAdress

	int err = WSAStartup(MAKEWORD(2, 2), &wsaData);

	if (err != 0) {
		cout << "WSAStartup error" << WSAGetLastError() << endl;
		WSACleanup();
		return 1;
	}

	sAdress.sin_family = AF_INET;
	sAdress.sin_port = htons(SERVER_PORT);
	sAdress.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRES);

	SOCKET sSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (sSocket == INVALID_SOCKET)
	{
		cout << "Socket Error" << WSAGetLastError() << endl;
		WSACleanup();
		return false; // 소켓 생성 실패시 실행
	}

	if (bind(sSocket, reinterpret_cast<SOCKADDR*> (&sAdress), sizeof(sAdress)))
	{
		// reinterpret_cast에서 cast가 먼지?
		cout << "Binding failed. Error code : " << WSAGetLastError() << endl;
		WSACleanup();
		return false;
	}
	cout << "client를 기다립니다." << endl;

	listen(sSocket, 5);
	int sizeCAdress = sizeof(cAdress);
	SOCKET chatSocket = accept(sSocket, reinterpret_cast<SOCKADDR*> (&cAdress), &sizeCAdress);
	cout << "Connection Complete " << "새로운 Socket은 " << chatSocket << endl;
	SOCKET* chatSocketPtr = &chatSocket;

	int receiveNumber;
	char commuBuffer[BUFFER_SIZE]; // 1024 * 8 byte
	string commuMessage;
	int status = 0;		// thread 종료 시 반환하는 값 저장 변수

	pthread_t posix;
	socketArg* socket_arg = new socketArg;	// 함수에 넣어줄 데이터(인자)가 많기 때문에 struct로 형성해서 한 번에 넘겨줌
	socket_arg->recvSocket = &chatSocket;
	socket_arg->buffer = commuBuffer;
	socket_arg->rMessage = &commuMessage;

	int pthreadCheck = pthread_create(&posix, NULL, socketReceive, (void*)socket_arg);	// void* 형은 모든 자료형 타입을 가르킬 수 있기 때문에 나중에 cast하면 됨

	pthread_join(posix, (void **)status);


	cout << "return thread " << status << endl;

	// server 종료
	delete socket_arg;
	closesocket(chatSocket);
	closesocket(sSocket);
	WSACleanup();


	return 0;
}