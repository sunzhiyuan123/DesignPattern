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

//从模板类派生模板类
template <typename T>
class C : public A<T>
{
public:
	using A<T>::a;
	C(T c,T a):A<T>(a)
	{
		this->c = c;
	}
	void PrintC( )
	{
		cout<<"a="<<a<<" "<<"c="<<c<<endl;
		//cout<<"a="<<this->a<<" "<<"c="<<c<<endl;
		//cout<<"a="<<A<T>::a<<" "<<"c="<<c<<endl;
	}
protected:
	T c;
};

void UseClassA(A<int>& a)
{
	a.PrintA( );
}

int main( )
{
	C<int> c1(10,20);
	
	c1.PrintC( );
	
    return 0;
}