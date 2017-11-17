#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <memory>
using namespace std;

class Singleton
{
public:
    //全局访问接口 线程安全
    static Singleton& GetInstance( )
    {
		static Singleton instance;
		
		return instance;
    }
	
    ~Singleton( )
    {
        cout << "~Singleton"<< endl;
    }
	
private:
    Singleton(const Singleton&) = delete;
	Singleton& operator = (const Singleton&) = delete;
    Singleton( )
    {
		cout << "Singleton"<<endl;
    }
};

void test1( )
{
	Singleton& s1 = Singleton::GetInstance( );
	auto&      s2 = Singleton::GetInstance( );
}

void test_singleton (int id)
{
	Singleton& single = Singleton::GetInstance( );
	cout << "id="<<id<<"single="<<&single<<endl;
}

int main(void)
{
	std::vector<std::thread> threads;
	
	for (auto i=0; i<10; i++)
	{
		threads.emplace_back(std::thread(test_singleton, i+1));
	}
	
	for (auto& thread : threads)
	{
		if (thread.joinable( ))
		{
			thread.join( );
		}
	}
	
    return 0;  
}
