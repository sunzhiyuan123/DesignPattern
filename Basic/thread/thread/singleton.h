#ifndef SINGLETON_H
#define SINGLETON_H

#include "thread.h"

class Processor1: public Thread
{
public:
	static Processor1& Instance(string name = "Processor1")
    {
		if (nullptr == instance)
		{
			instance = std::unique_ptr<Processor1>(new Processor1(name));
		}
		
        return *instance;
    }
	
	virtual ~Processor1( )
	{
		cout<<"enter ~Processor1"<<endl;
	}
protected:
	virtual void Process( ) override;	
private:
	Processor1(string name):Thread(name)
	{
		cout<<"enter Processor1"<<endl;
	}
	Processor1(const Processor1&) = delete;
	Processor1& operator = (const Processor1&) = delete;
	static std::unique_ptr<Processor1> instance;
};

#endif
