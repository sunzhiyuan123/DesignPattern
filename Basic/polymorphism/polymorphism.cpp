#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class Base
{
public:
	virtual void fun1( )
	{
		cout<<"Base::fun1()"<<endl;
	}
	virtual void fun2( )
	{
		cout<<"Base::fun2()"<<endl;
	}
	virtual void fun3( )
	{
		cout<<"Base::fun3()"<<endl;
	}
private:
	int a;
};

class A:public Base
{
public:
	void fun1( )
	{
		cout<<"A::fun1()"<<endl;
	}
	void fun2( )
	{
		cout<<"A::fun2()"<<endl;
	}
private:
	int b;
};

#if 0
void foo (Base& obj)
{
	obj.fun1( );
	obj.fun2( );
	obj.fun3( );
}
#endif

int main( )
{
#if 0
	Base b;
	A a;
	foo(b);
	foo(a);
#endif
	
	cout<<sizeof(Base)<<endl;	
	cout<<sizeof(A)<<endl;	
		
	return 0;
}