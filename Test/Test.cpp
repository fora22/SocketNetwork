#include <iostream>
//#include <boost/thread.hpp>

using namespace std;

void func(void) {
	cout << "1" << endl;
	
}

void func2(void) {
	cout << "2" << endl;
}

int main(void) {
	//boost::thread th1 = boost::thread(func);
	//boost::thread th2 = boost::thread(func2);


	//th1.join();
	//th2.join();
	cout << _MSC_VER << endl;
	return 0;
}