#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <memory>
#include <string>
using namespace std;

//定义了 Proxy和RealSubject的公有接口，
//这样就可以在任何需要使用到RealSubject的地方都使用Proxy
class Subject
{
public:
	Subject( )
	{
		
	}
	virtual ~Subject( )
	{
		
	}
	virtual void Request( )=0;
};

//真正使用的实体
class RealSubject:public Subject
{
public:
	RealSubject( )
	{
		cout<<"construction of RealSubject"<<endl;
	}
	virtual ~RealSubject( )
	{
		
	}
	virtual void Request( )
	{
		cout<<"Request by RealSubject"<<endl;
	}
};

//代理类，含有一个指向RealSubject对象的指针
class Proxy:public Subject
{
public:
	Proxy( ):m_pRealSubject(NULL)
	{
		cout<<"Construction a Proxy"<<endl;
	}
	virtual ~Proxy( )
	{
		delete m_pRealSubject;
		m_pRealSubject = NULL;
	}
	virtual void Request( )
	{
		if(NULL==m_pRealSubject)
		{
			cout<<"Realquest by Proxy"<<endl;
			m_pRealSubject = new RealSubject( );
		}
		m_pRealSubject->Request( );
	}
private:
	RealSubject *m_pRealSubject;
};

int main(void)
{
	Subject *pProxy = new Proxy( );
	pProxy->Request( );
	
	delete pProxy;

    return 0;  
}
