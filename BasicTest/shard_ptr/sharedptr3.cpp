#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class Integer  
{  
public:  
    Integer(int n) : n(n)
	{
	
	}
    ~Integer( ) 
	{
		cout<<"Deleting:"<<n<<endl;
	}
    int get( ) const 
	{
		return n;
	}
private:
	int n;
};

void test_shared_ptr3( )
{
	auto a = make_shared<Integer>(10);
	auto b = make_shared<Integer>(20);
	auto c = a;
	auto d = make_shared<Integer>(30);
	auto e = b;
	a = d;
	b = make_shared<Integer>(40);
	auto f = c;
	b = f;
	
	printf("a:%d\n", a->get( ));
	printf("b:%d\n", b->get( ));
	printf("c:%d\n", c->get( ));
	printf("d:%d\n", d->get( ));
	printf("e:%d\n", e->get( ));
	printf("f:%d\n", f->get( ));
}

struct MyInt
{
    MyInt(int v) :val(v)
	{
        cout<<"MyInt:"<<val<<endl;
    }
    ~MyInt( )
	{
        cout<<"~MyInt:"<<val<<endl;
    }
    int val;
};
  
void test_shared_ptr4( )
{
    shared_ptr<MyInt> sharPtr(new MyInt(1998));
    cout<<"val:" <<sharPtr->val<<endl;
    cout<<"use_count:"<<sharPtr.use_count( )<<endl;
	
    {
        shared_ptr<MyInt> locSharPtr(sharPtr);
        cout<<"use_count:"<<locSharPtr.use_count( )<<endl;
    }
	
    cout<<"use_count:"<<sharPtr.use_count( )<<endl;
	
    shared_ptr<MyInt> globSharPtr = sharPtr;
    cout<<"use_count:"<<sharPtr.use_count( )<<endl;
	//shared_ptr的reset( )函数的作用是将引用计数减1，停止对指针的共享，除非引用计数为0，否则不会发生删除操作
    globSharPtr.reset( );
    cout<<"use_count:"<<sharPtr.use_count( )<<endl;
	
    sharPtr = shared_ptr<MyInt>(new MyInt(2011));
	cout<<"val:" <<sharPtr->val<<endl;
	cout<<"use_count:"<<sharPtr.use_count( )<<endl;
}

void test_shared_ptr5( )
{
	std::shared_ptr<int> sp;
	sp.reset(new int);
	*sp = 10;
	cout<<*sp<<endl;
	
	sp.reset(new int);         				// deletes managed object, acquires new pointer  
	*sp = 20;
	cout<<*sp<<endl;
	
	sp.reset( );               				// deletes managed object  
}

int test_shared_ptr_get( )
{
	int *p = new int(10);
	shared_ptr<int> a(p);
	
	if (a.get( ) == p)
	cout << "a and p point to the same location\n";
	
	// three ways of accessing the same address:
	cout<<*a.get( )<<endl;
	cout<<*a<<endl;
	cout<<*p<<endl;
}

void test_shared_ptr_swap( )
{
	std::shared_ptr<int> foo(new int(10));
	std::shared_ptr<int> bar(new int(20));

	foo.swap(bar);
	
	std::cout<<"*foo:"<<*foo<<endl;
	std::cout<<"*bar:"<<*bar<<endl;
}

int main( )
{
	//test_shared_ptr3( );
	//test_shared_ptr4( );
	//test_shared_ptr5( );
	test_shared_ptr_get( );
	test_shared_ptr_swap( );
	
    return 0;
}