#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;  

void printD(deque<int> &d)
{
	for(deque<int>::iterator it=d.begin( );it!=d.end();it++)
	{
		cout<<*it<<endl;
	}
}

static void test_deque1( )
{
	deque<int> d1;
	d1.push_back(1);
	d1.push_back(3);
	d1.push_back(5);
	
	d1.push_front(-11);
	d1.push_front(-22);
	d1.push_front(-33);
	
	cout<<"ͷ��Ԫ��"<<d1.front( )<<endl;
	cout<<"β��Ԫ��"<<d1.back( )<<endl;
	printD(d1);
	//��ͷ������Ԫ��
	d1.pop_front( );
	cout<<"size="<<d1.size( )<<endl;
	//��β������Ԫ��
	d1.pop_back( );
	cout<<"size="<<d1.size( )<<endl;
	printD(d1);
	
	deque<int>::iterator it = find(d1.begin( ), d1.end( ), -11);
	if(it != d1.end( ))
	{
		cout<<"-11 is "<<distance(d1.begin( ), it)<<endl;
	}
	else
	{
		cout<<"û�ҵ�ֵ��33��Ԫ��"<<endl;
	}
}

int main( )
{
	test_deque1( );

    return 0;
}