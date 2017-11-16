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
	char buf1[256];
	char buf2[256];
	
	cout<<"请输入一个字符串 含有多个空格 aa bbccdd"<<endl;
	
	cin >> buf1;
	//去除空格
	cin.ignore(2);
	
	cin.getline(buf2, sizeof(buf2));
	
	cout<<"buf1:"<<buf1<<endl;
	cout<<"buf2:"<<buf2<<endl;
}

int main( )
{
	test_io1( );
	
    return 0;
}