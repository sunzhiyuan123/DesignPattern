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

ProcessorBase::ProcessorBase(string name_):name(name_)
{
	SetThreadStatus(false);
}

ProcessorBase::~ProcessorBase( )
{
	if (GetThreadStatus( ))
	{
		Stop( );
	}
}

void ProcessorBase::BaseRun(ProcessorBase *self)
{
	SetThreadStatus(true);
	self->StartProcess( );
	SetThreadStatus(false);
}

bool ProcessorBase::Start( )
{
	std::lock_guard<std::mutex> lg(mtx);
	
	if (GetThreadStatus( ))
	{
		return false;
	}
	
	SetThreadStatus(true);
	thread = std::thread(RunProcessor, this);
	
	return true;
}

bool ProcessorBase::Stop( )
{
	std::lock_guard<std::mutex> lg(mtx);
	
	if (GetThreadStatus( ))
	{
		SetThreadStatus(false);
		StopProcess( );
		thread.join( );
		return true;
	}
	
	return false;
}

bool ProcessorBase::Restart( )
{
	std::lock_guard<std::mutex> lg(mtx);
	
	if (GetThreadStatus( ))
	{
		SetThreadStatus(false);
		StopProcess( );
		thread.join( );
	}
	
	SetThreadStatus(true);
	thread = std::thread(RunProcessor, this);
	
	return true;
}

bool ProcessorBase::GetThreadStatus( )
{
	return status.Get( );
}

void ProcessorBase::SetThreadStatus(bool status_)
{
	status.Set(status_);
}

void ProcessorBase::SetThreadName(string name_)
{
	name = name_;
}

string ProcessorBase::GetThreadName( )
{
	return name;
}

void *RunProcessor(void *arg)
{
	ProcessorBase* proc_ptr = (ProcessorBase*) arg;
	proc_ptr->BaseRun(proc_ptr);
	
	return (void *) NULL;
}

int main( )
{

	return 0;
}
