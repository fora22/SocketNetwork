#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#include <random>
#include <thread>
#include <chrono>
#include <fstream>

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

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);  // create socket

    if (clientSocket == INVALID_SOCKET) {
        cout << "Socket error : " << WSAGetLastError() << endl;
        WSACleanup();
        return 0;
    }

    if (connect(clientSocket, reinterpret_cast<SOCKADDR*>(&target), sizeof(target)) == SOCKET_ERROR)
    {
        cout << "connect() error : " << WSAGetLastError() << endl;
        cout << "서버 먼저 실행해주세요." << endl;
        WSACleanup();
        return 0; // couldn't connect
    }

    // Connect Complete
    string sendMessage;
    int byteSend;
    int receiveClientNumber;
    char clientBuffer[8192]; // 1024 * 8 byte

    // file open
    //ifstream in("test.txt");


    while (true)
    {
        try
        {
            cout << "Please send Message : ";
            getline(cin, sendMessage);
            /*hile (getline(in, sendMessage)) {
                byteSend = send(clientSocket, sendMessage.c_str(), sendMessage.length(), 0);
            }
            in.close();*/
            //byteSend = send(clientSocket, sendMessage.c_str(), sendMessage.length(), 0);

            receiveClientNumber = recv(clientSocket, clientBuffer, strlen(clientBuffer), 0); // read max 50 bytes

            if (receiveClientNumber <= 0) { cout << "Got Nothing" << endl; break; }
            clientBuffer[receiveClientNumber] = 0; // make a string

            cout << "Received from Server : " << clientBuffer << endl;

            break;
        }
        catch (const invalid_argument& ex)
        {
            cerr << "Invalid argument while converting string to number" << endl;
            cerr << "Error: " << ex.what() << endl;
            break;
        }
        catch (const out_of_range& ex)
        {
            cerr << "Invalid argument while converting string to number" << endl;
            cerr << "Error: " << ex.what() << endl;
            break;
        }
    }

    closesocket(clientSocket);
    WSACleanup();


    return 0;
}
