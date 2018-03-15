#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

void test_unique_ptr1( )
{
    unique_ptr<int> up1(new int(10)); // 不能复制的unique_ptr
	if(nullptr != up1)
	{
		cout<<"up1:"<<*up1<<endl;
	}
    //unique_ptr<int> up2 = up1;      // Error unique_ptr没有复制构造函数
	
	//如果需要将所有权进行转移，可以这样操作：
    unique_ptr<int> up3 = move(up1);  //现在up3是数据唯一的unique_ptr智能指针
	if(nullptr != up3)
	{
		//move函数之后 源指针变为nullptr
		if(nullptr == up1)
		{
			cout<<"up1 nullptr"<<endl;
		}
		
		cout<<"up3:"<<*up3<<endl;
	}
	
	unique_ptr<int> up4 = move(up1);  //move操作没有报错 但是up4是nullptr
	if(nullptr != up4)
	{
		cout<<"up4:"<<*up4<<endl;
	}
		
    //cout<<*up1<<endl;               // 运行时错误

    up3.reset( );        // 显示释放内存
	if(nullptr == up3)
	{
		cout<<"up3 nullptr"<<endl;
	}
	
    up1.reset( );        // 即使up1没有拥有任何内存，但是这样调用也没有问题
    // cout<<*up3<<endl; // 已经释放掉up3了，这样会运行时错误
}

void test_unique_ptr2( )
{
    shared_ptr<int> sp1(new int(20));
    shared_ptr<int> sp2 = sp1; // 这是完全可以的，增加引用计数
	
    cout<<*sp1<<endl;
    cout<<*sp2<<endl;
	
	cout<<"sp1 use_count:"<<sp1.use_count( )<<endl;
	cout<<"sp2 use_count:"<<sp2.use_count( )<<endl;
	
    sp1.reset( ); // 减少引用计数
	if(nullptr == sp1)
	{
		cout<<"sp1 nullptr"<<endl;
	}
	
	cout<<"sp1 use_count:"<<sp1.use_count( )<<endl;
	cout<<"sp2 use_count:"<<sp2.use_count( )<<endl;
	
    cout<<*sp2<<endl;
}

unique_ptr<int> Func(unique_ptr<int> a)
{         
    cout<<*a<<endl;
    return a;
}         


//由于在unique_ptr中是没有复制构造函数的，所以在直接传参时，进行值传递时，建立临时变量时，就会出错了，
//所以需要显示的调用move，转移所有权；而函数的返回值已经进行了move操作，而不用显示的进行调用。
void test_unique_ptr3( )
{
    unique_ptr<int> up1(new int(10));
	
    up1 = Func(move(up1));
    cout<<*up1<<endl;
}

//test error
void test_unique_ptr4( )
{
    //不要用get函数获取原生指针之后，对智能指针进行赋值；
	//因为，get函数获取到的原生指针没有智能指针的信息，导致智能指针无法进行管理对象
	unique_ptr<int> up1(new int(10));
	cout<<*up1<<endl;
	unique_ptr<int> up0(up1.get( ));
}

int main( )
{
	test_unique_ptr1( );
	//test_unique_ptr2( );
	//test_unique_ptr3( );
	//test_unique_ptr4( );
	
    return 0;
}