#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for

using namespace std;

void thread1(int n)
{
    for (int i = 0; i < 5; ++i)
	{
        std::cout << "Thread " << n << " executing\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void thread2(int& n)
{
    for (int i = 0; i < 5; ++i)
	{
        std::cout << "Thread 2 executing\n";
        ++n;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void thread_task(int n)
{
    std::this_thread::sleep_for(std::chrono::seconds(n));
    std::cout<<"hello thread "<<std::this_thread::get_id( )<<" paused"<<n<<" seconds"<< std::endl;
}

int main( )
{
#if 0
	int n = 0;
	std::thread thrd0;                       // thrd0 is not a thread
    std::thread thrd1(thread1, n + 1);       // thrd1 pass by value
    std::thread thrd2(thread2, std::ref(n)); // thrd2 pass by reference
    std::thread thrd3(std::move(thrd2));     // thrd3 is now running thread2( ) thrd2 is no longer a thread
    thrd1.join( );
    thrd3.join( );
    std::cout << "Final value of n is " << n << '\n';
#endif
	
    std::thread threads[5];
	
    for (int i = 0; i < 5; i++)
	{
        threads[i] = std::thread(thread_task, i + 1);
    }
	
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (auto& t: threads)
	{
        t.join( );
    }
	
    std::cout << "All threads joined.\n";
	
    return 0;
}