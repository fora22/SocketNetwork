#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void)
{
	int* p = new int(100);
	cout << p << "하고 " << *p << endl;
	long c = reinterpret_cast<long> (p);
	cout << c << "하고" << endl;


	return 0;
}