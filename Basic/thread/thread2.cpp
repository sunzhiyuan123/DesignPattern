#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for

using namespace std;


volatile int counter(0);  	  // non-atomic counter
std::mutex mtx;               // locks access to counter

void attempt_10k_increases( )
{
    for (int i=0; i<10000; ++i) 
	{
#if 0
        if (mtx.try_lock( ))  // only increase if currently not locked:
		{
            ++counter;
            mtx.unlock( );
        }
#else
		mtx.lock( );
		++counter;
		mtx.unlock( );
#endif
    }
}

void print_even(int x)
{
    if (x%2==0)
	{
		std::cout << x << " is even\n";
	}
    else throw (std::logic_error("not even"));
}

void print_thread_id(int id)
{
    try
	{
        // using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
        std::lock_guard<std::mutex> lck (mtx);
        print_even(id);
    }
    catch (std::logic_error&)
	{
        std::cout << "[exception caught]\n";
    }
}

#if 0
void print_thread_id (int id)
{
	// using a local lock_guard to lock mtx guarantees unlocking on destruction / exception:
	std::lock_guard<std::mutex> lck(mtx);
	for (int i=0; i<10000; ++i)
	{
		++counter;
	}
}
#endif

void print_block(int n, char c)
{
    // critical section (exclusive access to std::cout signaled by lifetime of lck):
    std::unique_lock<std::mutex> lck(mtx);
	
    for (int i=0; i<n; ++i)
	{
        std::cout<<c;
    }
    std::cout << '\n';
}

int main( )
{
#if 0
    std::thread threads[10];
    for (int i=0; i<10; ++i)
	{
        threads[i] = std::thread(attempt_10k_increases);
	}

    for (auto& th : threads)
	{
		th.join( );
	}
    std::cout << counter << " successful increases of the counter.\n";
#endif
	
#if 1
	std::thread threads[10];
	
	for (int i=0; i<10; ++i)
	{
		threads[i] = std::thread(print_thread_id, i+1);
	}
	
	for (auto& th : threads) 
	{
		th.join( );
	}
	std::cout << counter << " successful increases of the counter.\n";
#endif	

#if 0
	std::thread th1(print_block, 50, '*');
	std::thread th2(print_block, 50, '$');
	
    th1.join( );
    th2.join( );
#endif	
	
    return 0;
}