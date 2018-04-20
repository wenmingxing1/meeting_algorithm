/*两个线程交叉打印AB*/
#include<iostream>
#include<mutex>
#include<thread>

using namespace std;

mutex mtx;

void print(char ch) {
    int num = 10;
    for (int i = 0; i < num; ++i) {
        mtx.lock();
        cout << ch << endl;
        mtx.unlock();
    }
}

int main() {
    thread th1(print, 'A');
    thread th2(print, 'B');

    th1.join();
    th2.join();

    return 0;
}
