#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;  

template <typename T>
class A
{
public:
	A(T a)
	{
		this->a = a;
	}
	void PrintA()
	{
		cout<<"a="<<a<<endl;
	}
protected:
	T a;
};

class B:public A<int>
{
public:
	B(int a, int b):A<int>(a)
	{
		this->b = b;
	}
	void PrintB( )
	{
		cout<<"a="<<a<<" "<<"b="<<b<<endl;
	}
	
private:
	int b;
};


void UseClassA(A<int>& a)
{
	a.PrintA( );
}

int main( )
{
	B b1(10,20);
	b1.PrintB( );
	//A<int> a1(10);
	//UseClassA(a1);
	
    return 0;
}