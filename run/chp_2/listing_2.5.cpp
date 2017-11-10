#include <thread>
#include <iostream>

using std::cout;
using std::endl;

void some_function()
{
    cout << "some_function" << endl;
}

void some_other_function(int)
{
    cout << "some_other_function" << endl;
}

std::thread f()
{
    void some_function();
    return std::thread(some_function);
}
std::thread g()
{
    void some_other_function(int);
    std::thread t(some_other_function,42);
    return t;
}

int main()
{
    std::thread t1=f();
    t1.join();
    std::thread t2=g();
    t2.join();
}
