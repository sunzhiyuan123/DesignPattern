#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
using namespace std;  

static void test_list1( )
{
	list<int> li;
	cout<<"length:"<<li.size( )<<endl;
	
	for(int i=0;i<10;i++)
	{
		li.push_back(i);
	}
	cout<<"length:"<<li.size( )<<endl;
	
	for(list<int>::iterator it=li.begin( );it!=li.end( );it++)
	{
		cout<<*it<<endl;
	}
	
	list<int>::iterator it;
	it = li.begin( );
	it++;
	it++;
	it++;
	
	//it = it+5;//不支持随机的访问容器
	li.insert(it,100);
	for(list<int>::iterator it=li.begin( );it!=li.end( );it++)
	{
		cout<<*it<<endl;
	}
	
	//链表的节点的index是从0号位置开始的
	//在3号位置插入元素 让原来的3号位置变成4号位置 原来的4号位置变成5号位置。
}

static void test_list2( )
{
	list<int> li;
	
	for(int i=0;i<10;i++)
	{
		li.push_back(i);
	}
	
	cout<<"length:"<<li.size( )<<endl;
	
	for(list<int>::iterator it=li.begin( );it!=li.end( );it++)
	{
		cout<<*it<<endl;
	}
	
	list<int>::iterator it1 = li.begin( );
	list<int>::iterator it2 = li.begin( );
	it2++;
	it2++;
	it2++;
	//删除的规则 左闭右开区间
	li.erase(it1,it2);
	cout<<"length:"<<li.size( )<<endl;
	for(list<int>::iterator it=li.begin( );it!=li.end( );it++)
	{
		cout<<*it<<endl;
	}
	li.insert(li.begin( ), 100);
	li.insert(li.begin( ), 100);
	li.insert(li.begin( ), 100);
	//li.erase(li.begin( ));
	//li.remove(100);//删除2个100
	cout<<"length:"<<li.size( )<<endl;
	for(list<int>::iterator it=li.begin( );it!=li.end( );it++)
	{
		cout<<*it<<endl;
	}
}

int main( )
{
	//test_list1( );
	test_list2( );
	
    return 0;
}