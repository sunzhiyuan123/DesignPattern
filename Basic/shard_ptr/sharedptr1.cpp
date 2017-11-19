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
	//unique( )�����������Ը�shared_ptr�Ƿ���ԭʼָ��Ψһӵ���ߣ�
	//Ҳ����use_count( )�ķ���ֵΪ1ʱ����true�����򷵻�false
	cout << ptr1.unique( ) << endl;
	
	//make_shared�������ڶ��з���һ�����󲢳�ʼ������󷵻�ָ��˶����share_ptrʵ��
	shared_ptr<Example1> pStr1 = make_shared<Example1>("a object");
    shared_ptr<Example1> pStr2 = make_shared<Example1>("b object");
    cout << "pStr1 use count: " << pStr1.use_count( ) << endl;
    cout << "pStr2 use count: " << pStr2.use_count( ) << endl;
	
	cout << "before" << endl;
	pStr1 = pStr2;   // �˺�pStr1��pStr2ָ����ͬ����
	cout << "pStr1 use count: " << pStr1.use_count( ) << endl;
    cout << "pStr2 use count: " << pStr2.use_count( ) << endl;
	cout << "after" << endl;
	
    cout << pStr1->name << endl;
    cout << pStr2->name << endl;
	
	shared_ptr<Example> example_ctl = shared_ptr<Example>(new Example( ));
	cout << "example_ctl use count: " << example_ctl.use_count( ) << endl;
	
    return 0;
}