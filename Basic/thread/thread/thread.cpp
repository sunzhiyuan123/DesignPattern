#include <iostream>
#include "thread.h"

using namespace std;

void Thread::StartThread( )
{
	Process( );
}

Thread::Thread(string name):name_(name),running_(false)
{
	cout<<"enter Thread"<<endl;
}

Thread::~Thread( )
{
	cout<<"enter ~Thread"<<endl;
	
	Stop( );
}

bool Thread::Run( )
{
	std::lock_guard<std::mutex> lck(mtx_);
	if(running_)
	{
		return true;
	}
	
	running_ = true;
	thread_  = std::thread(&Thread::StartThread, this);
	
	return true;
}

bool Thread::Stop( )
{
	std::lock_guard<std::mutex> lck(mtx_);
	if(!running_)
	{
		return true;
	}
	
	running_ = false;
	thread_.join( );
	
	return true;
}

string Thread::Name( ) const
{
	return name_;
}

bool Thread::IsRunning( ) const
{
	return running_;
}