#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class A
{
public:
	A(int a) : a_(a)
	{
		cout << "A Constructor..." << endl;
	}
	~A( )
	{
		cout << "A Destructor..." << endl;
	}
	
	int a_;
};

void test_weak_ptr1( )
{
	shared_ptr<A> sp(new A(10));
	weak_ptr<A>   wp(sp);//指向sp所指向的内存
	//sp.reset( );
	
	//如果对象存在,wp.lock( )函数返回一个指向共享对象的shared_ptr,否则返回一个空shared_ptr.
	if (shared_ptr<A> pa = wp.lock( ))
	{
		cout << pa->a_ << endl;
	}
	else
	{
		cout << "wp is nullptr" << endl;
	}
}

void test_weak_ptr2( )
{
	shared_ptr<A> sp(new A(5));
	weak_ptr<A>   wp(sp);
	sp.reset( );                    //此时sp被销毁
	//weak_ptr还提供了expired( )函数来判断所指对象是否已经被销毁
	cout << wp.expired( ) << endl;  //true表示已被销毁，否则为false
}

void Check(weak_ptr<int> &wp)
{
	//weak_ptr并没有重载operator->和operator *操作符，因此不可直接通过weak_ptr使用对象，
	//典型的用法是调用其lock函数来获得shared_ptr示例，进而访问原始对象
    shared_ptr<int> sp = wp.lock( ); //重新获得shared_ptr对象
    if (sp != nullptr)
    {
        cout<<"The value is "<<*sp<<endl;
    }
    else
    {
        cout<<"Pointer is invalid."<<endl;
    }
}

void test_weak_ptr3( )
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int>   wp  = sp1; //指向sp1所指向的内存
	
    cout<<*sp1<<endl;
    cout<<*sp2<<endl;
    Check(wp);
	
    sp1.reset( );
    cout<<*sp2<<endl;
    Check(wp);
	
    sp2.reset( );
    Check(wp);
}

class ClassB1;

class ClassA1
{
public:
    ClassA1( )
	{
		cout << "ClassA1 Constructor..." << endl;
	}
    ~ClassA1( )
	{
		cout << "ClassA1 Destructor..." << endl;
	}
    shared_ptr<ClassB1> pb;  // 在A中引用B
};

class ClassB1
{
public:
    ClassB1( )
	{
		cout << "ClassB1 Constructor..." << endl;
	}
    ~ClassB1( )
	{
		cout << "ClassB1 Destructor..." << endl;
	}
    shared_ptr<ClassA1> pa;  // 在B中引用A
};

//对于引用计数法实现的计数，总是避免不了循环引用（或环形引用）的问题 shared_ptr也不例外.
void test_weak_ptr4( )
{
    shared_ptr<ClassA1> spa = make_shared<ClassA1>( );
    shared_ptr<ClassB1> spb = make_shared<ClassB1>( );
    spa->pb = spb;
    spb->pa = spa;
    // 函数结束，思考一下：spa和spb会释放资源么？
}

//循环引用的改进
class ClassBB;

class ClassAA
{
public:
    ClassAA( )
	{
		cout << "ClassAA Constructor..." << endl;
	}
    ~ClassAA( )
	{
		cout << "ClassAA Destructor..." << endl;
	}
	
    weak_ptr<ClassBB> pb;  // 在A中引用B
};

class ClassBB
{
public:
    ClassBB( )
	{
		cout << "ClassBB Constructor..." << endl;
	}
    ~ClassBB( )
	{ 
		cout << "ClassBB Destructor..." << endl;
	}
    weak_ptr<ClassAA> pa;  // 在B中引用A
};

void test_weak_ptr5( )
{
    shared_ptr<ClassAA> spa = make_shared<ClassAA>( );
    shared_ptr<ClassBB> spb = make_shared<ClassBB>( );
    spa->pb = spb;
    spb->pa = spa;
    // 函数结束，思考一下：spa和spb会释放资源么？
}

int main( )
{
	//test_weak_ptr1( );
	//test_weak_ptr2( );
	test_weak_ptr3( );
	//test_weak_ptr4( );
	//test_weak_ptr5( );
	
    return 0;
}