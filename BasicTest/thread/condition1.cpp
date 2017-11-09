#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>             // std::chrono::seconds
#include <thread>             // std::thread, std::this_thread::sleep_for
#include <vector>
#include <condition_variable> // std::condition_variable

using namespace std;

std::mutex mtx;             // ȫ�ֻ�����.
std::condition_variable cv; // ȫ����������.
bool ready = false;         // ȫ�ֱ�־λ.

void do_print_id(int id)
{
	std::unique_lock <std::mutex> lck(mtx);
	while (!ready)          // �����־λ��Ϊ true, ��ȴ�...
	{
		std::cout << "enter " << '\n';
		cv.wait(lck);       // ��ǰ�̱߳�����, ��ȫ�ֱ�־λ��Ϊ true ֮��,
	}
					        // �̱߳�����, ��������ִ�д�ӡ�̱߳��id.
	std::cout << "thread " << id << '\n';
}

void go( )
{
    std::unique_lock <std::mutex> lck(mtx);
    ready = true;          // ����ȫ�ֱ�־λΪ true.
    cv.notify_all( );      // ���������߳�.
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