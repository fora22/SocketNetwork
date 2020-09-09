#include <iostream>
#include <string>
#include <vector>
#include <WinSock2.h>
#include <random>
#include <thread>
#include <chrono>
//#pragma comment (lib , "ws2_32.lib")
using namespace std;

int main(void)
{
	vector<double> homework;
	for (int i = 0; i <= 5; i++)
	{
		homework.push_back(i);
		cout << homework[i] << endl;
		cout << homework.size() << endl;
	}

	return 0;
}
