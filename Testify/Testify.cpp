#include <iostream>
#include <thread>
using namespace std;
#include <WinSock2.h>

void func1(void) {
    for (int i = 0; i < 10; i++)
    {
        cout << "thread_1" << endl;
    }
}

void func2(void) {
    for (int i = 0; i < 10; i++)
    {
        cout << "thread_2" << endl;
    }
}

void func3(void) {
    for (int i = 0; i < 10; i++)
    {
        cout << "thread_3" << endl;
    }
}




int main(void)
{
    thread t1(func1);
    thread t2(func2);
    thread t3(func3);
    cout << "join Àü" << endl;

    t1.join();
    t2.join();
    t3.join();

    cout << "join ÈÄ" << endl;

    return 0;
}