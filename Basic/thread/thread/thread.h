#ifndef THREAD_H
#define THREAD_H

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
using namespace std;

void *RunProcessor(void *arg);

template <class T>
class MtxElem
{
public:
	T Get( )
	{
		T e;
		mtx.lock( );
		e = elem;
		mtx.unlock( );
		return e;
	}
	void Set(const T& e)
	{
		mtx.lock( );
		elem = e;
		mtx.unlock( );
	}
private:
	T elem;
	mutex mtx;
};

class ProcessorBase
{
public:
	ProcessorBase(string name_ = "");
	virtual ~ProcessorBase( );
	bool Start( );
	bool Stop( );
	bool Restart( );
	void BaseRun(ProcessorBase *self);
	
protected:
	void   SetThreadName(string name_);
	string GetThreadName( );
	void   SetThreadStatus(bool status_);
	bool   GetThreadStatus( );
	
	virtual void StartProcess( ) = 0;
	virtual void StopProcess( )  = 0;
	
private:
	MtxElem<bool> status;
	string 		  name;
	std::thread   thread;
	mutex 		  mtx;
};

#endif
