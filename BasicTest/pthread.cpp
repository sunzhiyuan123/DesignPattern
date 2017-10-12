#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <mutex>          // std::mutex, std::lock_guard
#include <stdexcept>      // std::logic_error

using namespace std;

std::mutex mtx;

static int sum = 0;

void print_thread_id (int id)
{
	int i;
	printf("id=%d\n",id);
	for(i=0;i<10000;i++)
	{
		std::lock_guard<std::mutex> lg(mtx);
		sum++;
	}
}

int main( )
{
    std::thread threads[10];
    // spawn 10 threads:
    for (int i=0; i<10; i++)
        threads[i] = std::thread(print_thread_id,i+1);
	
    for (auto &th : threads) 
		th.join( );
	
	cout<<"sum: "<<sum<<endl;
	
    return 0;
}