#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <memory>
#include <string>
using namespace std;

//������ Proxy��RealSubject�Ĺ��нӿڣ�
//�����Ϳ������κ���Ҫʹ�õ�RealSubject�ĵط���ʹ��Proxy
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

//����ʹ�õ�ʵ��
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

//�����࣬����һ��ָ��RealSubject�����ָ��
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
