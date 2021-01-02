#define HAVE_STRUCT_TIMESPEC
#define SERVER_PORT 11235
#define SERVER_IP_ADDRES "127.0.0.1"

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

void socketSend(SOCKET* sSocket, string* sMessage) {
    // socketArg* sendSocketArg = (socketArg*)(&socket_arg);	// struct ������ cast��

    // int sendCheck;
    // sendCheck = send(*(sendSocketArg->recvSocket), (*(sendSocketArg->rMessage)).c_str(), (*(sendSocketArg->rMessage)).length(), 0);  
    int sendCheck;
    sendCheck = send(*sSocket, (*sMessage).c_str(), (*sMessage).length(), 0);
}

//SOCKET* recvSocket, char* buffer, string* rMessage
void* socketReceive(void* socket_arg) {
    socketArg* recvSocketArg = (socketArg*)(&socket_arg);	// struct ������ cast��

    int messageLength = 0;
    while (true)
    {
        messageLength = recv(*(recvSocketArg->recvSocket), recvSocketArg->buffer, strlen(recvSocketArg->buffer), 0);
        if (messageLength > 0)
        {
            recvSocketArg->buffer[messageLength] = 0;
            *(recvSocketArg->rMessage) = recvSocketArg->buffer;
            cout << *(recvSocketArg->rMessage) << endl;
        }
    }
}

int main(void)
{
    WSADATA wsaData;
    SOCKADDR_IN sAdress;

    int err = WSAStartup(MAKEWORD(2, 2), &wsaData);

    if (err != 0) {
        cout << "WSASartup error " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }

    sAdress.sin_family = AF_INET;
    sAdress.sin_port = htons(SERVER_PORT);
    sAdress.sin_addr.s_addr = inet_addr(SERVER_IP_ADDRES);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // create socket

    if (clientSocket == INVALID_SOCKET) {
        cout << "Socket error : " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }

    if (connect(clientSocket, reinterpret_cast<SOCKADDR*>(&sAdress), sizeof(sAdress)) == SOCKET_ERROR)
    {
        cout << "connect() error : " << WSAGetLastError() << endl;
        cout << "���� ���� �������ּ���." << endl;
        WSACleanup();
        return 0; // couldn't connect
    }

    // Connect Complete
    cout << "Connect Complete" << endl;
    
    char clientBuffer[8192]; // 1024 * 8 byte
    string clientMessage;
    int clientRecvStatus = 0;		// thread ���� �� ��ȯ�ϴ� �� ���� ����
    int clientSendStatus = 0;		// thread ���� �� ��ȯ�ϴ� �� ���� ����

    // pthread id �����
    pthread_t clientRecvPosix;
    pthread_t clientSendPosix;

    // struct �����
    socketArg* socket_arg = new socketArg;	// �Լ��� �־��� ������(����)�� ���� ������ struct�� �����ؼ� �� ���� �Ѱ���
    socket_arg->recvSocket = &clientSocket;
    socket_arg->buffer = clientBuffer;
    socket_arg->rMessage = &clientMessage;

    int phtreadRecvCheck = pthread_create(&clientRecvPosix, NULL, socketReceive, (void*)socket_arg);
    // int pthreadSendCheck = pthread_create(&clientSendPosix, NULL, socketSend, (void*)socket_arg);
   
    while (true)
    {
        cout << "Message : ";
        cin >> clientMessage;
        socketSend(&clientSocket, &clientMessage);
    }
    
    pthread_join(clientRecvPosix, (void**)clientRecvStatus);
    // pthread_join(clientSendPosix, (void**)clientSendStatus);

    delete socket_arg;
    closesocket(clientSocket);
    WSACleanup();


    return 0;
}
