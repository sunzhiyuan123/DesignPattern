#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>             // std::chrono::seconds
#include <thread>             // std::thread, std::this_thread::sleep_for
#include <vector>
#include <condition_variable> // std::condition_variable

using namespace std;


std::mutex mtx;
std::condition_variable cv;

int cargo = 0;
bool shipment_available( )
{
    return cargo != 0;
}

// 消费者线程.
void consume(int n)
{
    for (int i = 0; i < n; ++i)
	{
        std::unique_lock <std::mutex> lck(mtx);
        cv.wait(lck, shipment_available);
		//cv.wait(lck, [&](){ return cargo != 0;});
		
        std::cout << cargo << '\n';
        cargo = 0;
    }
}

int main()
{
    std::thread consumer_thread(consume, 10); // 消费者线程.
	
    // 主线程为生产者线程, 生产 10 个物品.
    for (int i = 0; i < 10; ++i) 
	{
        while (shipment_available( ))
            std::this_thread::yield( );
        std::unique_lock <std::mutex> lck(mtx);
        cargo = i + 1;
        cv.notify_one( );
    }
	
    consumer_thread.join( );
	
    return 0;
}