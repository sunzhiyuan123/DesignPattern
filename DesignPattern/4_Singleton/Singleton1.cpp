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
    //全局访问接口 非线程安全性
    static Singleton& GetInstance( )
    {
		if (nullptr == instance)
		{
			std::lock_guard<std::mutex> lck (mtx);
			if (nullptr == instance)
			{
				instance = std::unique_ptr<Singleton>(new Singleton);
			}
		}
		
        return *instance;
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
	static std::mutex mtx;
	static std::unique_ptr<Singleton> instance;
};
std::mutex Singleton::mtx;
std::unique_ptr<Singleton> Singleton::instance = nullptr;

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
