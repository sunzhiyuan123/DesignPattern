#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>

using namespace std;

std::mutex mtx;           // mutex for critical section

void print_thread_id (int id)
{
	mtx.lock( );
	std::lock_guard<std::mutex> lck(mtx, std::adopt_lock);
	std::cout << "thread #" << id << '\n';
}

std::mutex foo,bar;

void task_a ( )
{
	std::lock(foo, bar); // simultaneous lock (prevents deadlock)
	std::unique_lock<std::mutex> lck1(foo, std::adopt_lock);
	std::unique_lock<std::mutex> lck2(bar, std::adopt_lock);
	std::cout << "task a\n";
}

void task_b ( )
{
	std::unique_lock<std::mutex> lck1, lck2;
	lck1 = std::unique_lock<std::mutex>(bar, std::defer_lock);
	lck2 = std::unique_lock<std::mutex>(foo, std::defer_lock);
	std::lock (lck1, lck2); // simultaneous lock (prevents deadlock)
	std::cout << "task b\n";
}

int main( )
{
#if 1
	std::vector<std::thread> threads;
	
	for (auto i=0; i<10; ++i)
	{
		threads.emplace_back(std::thread(print_thread_id, i+1));
	}
	
	for (auto& thread : threads)
	{
		if (thread.joinable( ))
		{
			thread.join( );
		}
	}
#endif

#if 0
	std::thread th1 (task_a);
	std::thread th2 (task_b);
	
	th1.join( );
	th2.join( );
#endif

	return 0;
}