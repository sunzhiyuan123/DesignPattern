#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

void Func1(shared_ptr<int> a)
{
    cout<<"Enter Func1"<<endl;
    cout<<"Ref count: "<<a.use_count( )<<endl;
    cout<<"Leave Func1"<<endl;
}

shared_ptr<int> Func2(shared_ptr<int> a)
{
    cout<<"Enter Func2"<<endl;
    cout<<"Ref count: "<<a.use_count( )<<endl;
    cout<<"Leave Func2"<<endl;
    return a;
}

int main()
{
    shared_ptr<int> ptr1(new int(10));
    cout<<"Ref count: "<<ptr1.use_count( )<<endl;

	shared_ptr<int> ptr2 = ptr1;
	cout<<"Ref count: "<<ptr2.use_count( )<<endl;
	
    Func1(ptr1);
	cout<<"Ref count: "<<ptr1.use_count( )<<endl;
	
    Func2(ptr1);
	cout<<"Ref count: "<<ptr1.use_count( )<<endl;
	
    shared_ptr<int> ptr3 = Func2(ptr1);
    cout<<"Ref count:"<<ptr3.use_count( )<<endl;
	
    return 0;
}