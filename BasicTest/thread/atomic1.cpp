#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <atomic>

using namespace std;

std::atomic_int foo(0);

void set_foo(int x)
{
    foo = x; // µ÷ÓÃ std::atomic::operator=().
}

void print_foo( )
{
    while (foo == 0) // wait while foo == 0
	{
        std::this_thread::yield( );
    }
    std::cout << "foo: " << foo << '\n';
}

int main( )
{
    std::thread first(print_foo);
    std::thread second(set_foo, 10);
    first.join( );
    second.join( );
	
    return 0;
}