#ifndef THREAD_H
#define THREAD_H

#include <iostream>
#include <mutex>
#include <thread>
#include <string>
#include <atomic>

using namespace std;

class Thread
{
public:
	Thread(string name = "");
	virtual ~Thread( );
	bool Run( );
	bool Stop( );
	bool IsRunning( ) const;
	string Name( ) const;
protected:
	virtual void Process( ) = 0;
private:
	void StartThread( );
	std::string      name_;
	std::thread   	 thread_;
	std::atomic_bool running_;
	std::mutex 		 mtx_;
};

#endif
