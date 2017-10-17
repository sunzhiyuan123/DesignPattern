#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

class Example
{
public:
    Example( ) : e(1) 
	{
		cout << "Example..." << endl;
	}
    ~Example( )
	{
		cout << "~Example" << endl;
	}
	
    int e;
};

class Example1
{
public:
    Example1(string n) : name(n)
	{
		cout << n << " Example1..." << endl;
	}
    ~Example1( )
	{ 
		cout << name << " ~Example1..." << endl;
	}
	
    string name;
};

int main( )
{	
	shared_ptr<Example> ptr1(new Example( ));
	cout << (*ptr1).e << endl;
	cout << "ptr1 use count: " << ptr1.use_count( ) << endl;
	cout << ptr1.unique( ) << endl;
	shared_ptr<Example> ptr2 = ptr1;
    cout << "ptr1 use count: " << ptr1.use_count( ) << endl;
    cout << "ptr2 use count: " << ptr2.use_count( ) << endl;
	shared_ptr<Example> ptr3 = ptr2;
	cout << "ptr1 use count: " << ptr1.use_count( ) << endl;
	cout << "ptr2 use count: " << ptr2.use_count( ) << endl;
	cout << "ptr3 use count: " << ptr3.use_count( ) << endl;
	//unique( )函数用来测试该shared_ptr是否是原始指针唯一拥有者，
	//也就是use_count( )的返回值为1时返回true，否则返回false
	cout << ptr1.unique( ) << endl;
	
	//make_shared函数会在堆中分配一个对象并初始化，最后返回指向此对象的share_ptr实例
	shared_ptr<Example1> pStr1 = make_shared<Example1>("a object");
    shared_ptr<Example1> pStr2 = make_shared<Example1>("b object");
    cout << "pStr1 use count: " << pStr1.use_count( ) << endl;
    cout << "pStr2 use count: " << pStr2.use_count( ) << endl;
	
	cout << "before" << endl;
	pStr1 = pStr2;   // 此后pStr1和pStr2指向相同对象
	cout << "pStr1 use count: " << pStr1.use_count( ) << endl;
    cout << "pStr2 use count: " << pStr2.use_count( ) << endl;
	cout << "after" << endl;
	
    cout << pStr1->name << endl;
    cout << pStr2->name << endl;
	
	shared_ptr<Example> example_ctl = shared_ptr<Example>(new Example( ));
	cout << "example_ctl use count: " << example_ctl.use_count( ) << endl;
	
    return 0;
}