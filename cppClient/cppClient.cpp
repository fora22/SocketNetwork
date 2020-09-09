#include <iostream>
#include <vector>
#include <string>
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