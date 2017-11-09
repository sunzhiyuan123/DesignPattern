#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>             // std::chrono::seconds
#include <thread>             // std::thread, std::this_thread::sleep_for
#include <vector>
#include <condition_variable> // std::condition_variable

using namespace std;

std::mutex mtx;             // 全局互斥锁.
std::condition_variable cv; // 全局条件变量.
bool ready = false;         // 全局标志位.

void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
	while (!ready)          // 如果标志位不为 true, 则等待...
	{
		std::cout << "enter " << '\n';
		cv.wait(lck);       // 当前线程被阻塞, 当全局标志位变为 true 之后,
	}
					        // 线程被唤醒, 继续往下执行打印线程编号id.
	std::cout << "thread " << id << '\n';
}

void go( )
{
    std::unique_lock <std::mutex> lck(mtx);
    ready = true;          // 设置全局标志位为 true.
    cv.notify_all( );      // 唤醒所有线程.
}

int main( )
{
    std::thread threads[10];
	
    for (int i = 0; i < 10; ++i)
	{
        threads[i] = std::thread(do_print_id, i);
	}
	
    std::cout << "10 threads ready to race...\n";
	std::this_thread::sleep_for(std::chrono::seconds(2));
    go( ); // go!
	
	for (auto& th:threads)
	{
		th.join( );
	}
	
    return 0;
}