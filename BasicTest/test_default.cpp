#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class MyClass
{
public:
	MyClass( )=default;
	MyClass(int i):data_(i)
	{
		cout<<"enter MyClass"<<endl;
	}
	//int GetData( ) = delete;
	int GetData( )
	{
		return data_;
	}
	void SetData(int data)
	{
		data_ = data;
	}
private:
    int data_;
};

int main( )
{
	MyClass my_class(100);
	
	cout<<"data="<<my_class.GetData( )<<endl;

    return 0;
}