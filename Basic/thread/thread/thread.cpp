#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <map>
#include <string>
#include <unistd.h>
#include <sstream> 
#include "thread.h"

using namespace std;

void* Thread::startThread(void *pThis)
{
	Thread *pThread = static_cast<Thread*>(pThis);
	
	pThread->StartProcess( );
	
	return (void*)NULL;
}

Thread::Thread(string name):name_(name),started_(false)
{
	cout<<"enter Thread"<<endl;
}

Thread::~Thread( )
{
	cout<<"enter ~Thread"<<endl;
	
	Stop( );
}

void Thread::Start( )
{		
	if (false == started_)
	{
		started_ = true;
		thread_  = std::thread(startThread, this);
	}
}

void Thread::Stop( )
{
	if (true == started_)
	{
		started_ = false;
		thread_.join( );
	}
}

// bool Thread::GetStatus( )
// {
	// std::lock_guard<std::mutex> lg(mtx_);
	
	// return started_;
// }

// void Thread::SetStatus(bool started)
// {
	// std::lock_guard<std::mutex> lg(mtx_);
	
	// started_ = started;
// }

const string& Thread::GetName( ) const
{
	return name_;
}

////////////////////////////////////////////////////
class Processor1: public Thread
{
public:
	static Processor1& Instance(string proc_name = "DayNightProcessor")
    {
		if (nullptr == instance)
		{
			instance = std::unique_ptr<Processor1>(new Processor1(proc_name));
		}
		
        return *instance;
    }
	virtual ~Processor1( )
	{
		running_ = false;
		cout<<"enter ~Processor1"<<endl;
	}
protected:
	virtual void StartProcess( ) override;	
private:
	Processor1(string proc_name):Thread(proc_name),running_(false)
	{
		cout<<"enter Processor1"<<endl;
	}
	Processor1(const Processor1&) = delete;
	Processor1& operator = (const Processor1&) = delete;
	std::atomic<bool> running_;
	static std::unique_ptr<Processor1> instance;
};
std::unique_ptr<Processor1> Processor1::instance = nullptr;

void Processor1::StartProcess( )
{
	running_ = true;

	while (running_)
	{
		cout<<"enter test"<<endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	
	cout<<"exit StartProcess"<<endl;
}

int main( )
{
	Processor1::Instance( ).Start( );
	std::this_thread::sleep_for(std::chrono::seconds(5));
	//Processor1::Instance( ).Stop( );
	
	return 0;
}
