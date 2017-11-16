#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;  

/* 标准输入流对象
** cin.get( )        一次只能读取一个字符
** cin.get(一个参数) 读取一个字符
** cin.get(三个参数) 可以读取字符串
** cin.getline( )    
** cin.ignore( )
** cin.peek( )
** cin.putback( )
*/


static void test_io1( )
{
	char mybuf[1024];
	int  myInt;
	long myLong;
	
	cin >> myInt;
	cin >> myLong;
	
	cin >> mybuf;//遇到空格停止接收数据
	
	cout<<"myInt:"<<myInt<<endl;
	cout<<"myLong:"<<myLong<<endl;
	cout<<"mybuf:"<<mybuf<<endl;
}

static void test_io2( )
{
	char ch;
	
	while((ch = cin.get( )) != EOF)
	{
		cout<<ch<<endl;
	}
}

static void test_io3( )
{
	char a,b,c;
	
	cin.get(a);
	cin.get(b);
	cin.get(c);
	
	cout<<a<<b<<c<<endl;
}

static void test_io4( )
{
	char buf1[256];
	char buf2[256];
	
	cout<<"请输入一个字符串 含有多个空格 aa bb cc dd"<<endl;
	
	cin >> buf1;
	
	cin.getline(buf2, sizeof(buf2));
	
	cout<<"buf1:"<<buf1<<endl;
	cout<<"buf2:"<<buf2<<endl;
}

int main( )
{
	//test_io1( );
	//test_io2( );
	//test_io3( );
	test_io4( );
	
    return 0;
}