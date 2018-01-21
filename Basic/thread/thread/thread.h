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
#include <atomic>

using namespace std;

class Thread
{
public:
	Thread(string name = "");
	virtual ~Thread( );
	void Start( );
	void Stop( );
	const string& GetName( ) const;
protected:
	// bool GetStatus( );
	// void SetStatus(bool started);
	virtual void StartProcess( ) = 0;
private:
	static void* startThread(void *args);
	bool          started_;
	string 		  name_;
	std::thread   thread_;
	std::mutex 	  mtx_;
};

#endif
