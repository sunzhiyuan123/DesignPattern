#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;  

void test_vector1( )
{
	vector<int> v1;
	cout<<"length:"<<v1.size( )<<endl;
	//向尾部插入元素
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout<<"length:"<<v1.size( )<<endl;
	
	//获取头部元素
	cout<<"头部元素:"<<v1.front( )<<endl;
	
	//修改头部元素 函数返回值当左值  应该返回一个引用
	v1.front( ) = 11;
	v1.back( )  = 55;
	
	while(v1.size( ) > 0)
	{
		//获取尾部元素
		cout<<"尾部元素:"<<v1.back( )<<endl;
		//删除尾部元素
		v1.pop_back( );
	}
	cout<<"length:"<<v1.size( )<<endl;
}

//vector的初始化
void test_vector2( )
{
	vector<int> v1;
	
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	
	//对象初始化
	vector<int> v2 = v1;
	vector<int> v3(v2.begin( ),v2.begin( )+2);
}

static void printV(vector<int> &v)
{
	for(int i=0;i<v.size( );i++)
	{
		cout<<v[i]<<endl;
	}
}

void test_vector3( )
{
	//提前把内存准备好
	vector<int> v1(10);
	//push_back函数是在数组元素的尾部添加元素
	v1.push_back(100);
	v1.push_back(200);
	
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	
	cout<<"length:"<<v1.size( )<<endl;
	
	printV(v1);
}

//1.迭代器的理解
//1       3     5   
//begin()          end( )
//首地址           容器的后面
//当it == v1.end( )的时候 说明这个容器已经遍历完毕了

//2.迭代器的种类
//正向迭代器  逆向迭代器等
void test_vector4( )
{
	vector<int> v1(10);
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	//正向遍历容器
	for(vector<int>::iterator it = v1.begin( ); it != v1.end( ); it++)
	{
		cout<<*it<<endl;
	}
	
	//反向遍历容器
	for(vector<int>::reverse_iterator rit = v1.rbegin( ); rit != v1.rend( ); rit++)
	{
		cout<<*rit<<endl;
	}
}

void test_vector5( )
{
	vector<int> v1(10);
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	//区间删除
	v1.erase(v1.begin( ),v1.begin( )+3);
	//根据元素的位置删除 指定位置删除
	v1.erase(v1.begin( ));
	printV(v1);
	cout<<endl;
	//根据元素值删除
	v1[0] = 2;
	v1[1] = 2;
	printV(v1);
	cout<<endl;
	for(vector<int>::iterator it=v1.begin( ); it!=v1.end( ); )
	{
		if(*it == 2)
		{
			//当删除迭代器所指向的元素的时候,erase函数会让it自动移动到下个位置
			//当删除一个元素的时候，erase函数返回迭代器的位置(删除元素的下一个位置)
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	printV(v1);
	cout<<endl;
	//容器插入操作
	v1.insert(v1.begin( ),100);
	v1.insert(v1.end( ),200);
	printV(v1);
}

void test_vector6( )
{
	vector<int> v1;
    for (int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//方法一：使用clear函数 清空元素 不回收空间
	cout<<endl;
	v1.clear( );
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//方法二：使用erase函数循环删除  挡换厥湛占�
	cout<<endl;
	for(vector<int>::iterator iter=v1.begin( ); iter!=v1.end( ); )
	{
		//当删除迭代器所指向的元素的时候,erase函数会让it自动移动到下个位置
		//当删除一个元素的时候，erase函数返回迭代器的位置(删除元素的下一个位置)
		iter = v1.erase(iter);
	}
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//第三种办法 最简单的使用swap,清除元素并回收内存
	cout<<endl;
	vector<int>( ).swap(v1);
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
}

void test_vector7( )
{
	vector<int*> v1;
	
    for (int i=0;i<10;i++)
    {
        v1.push_back(new int(i));
    }
	
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//vector::clear( )函数的作用是清空容器中的内容，但如果是指针对象的话，并不能清空其内容，
	//必须要像以下方法才能达到清空指针对象的内容：
	//1.free元素所指向的空间
	for(auto iter = v1.begin( ); iter != v1.end( ); iter++)
	{
		delete *iter;
	}
	
	//2.清除元素
	v1.clear( );
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
}

int main( )
{
	//test_vector1( );
	//test_vector2( );
	//test_vector3( );
	//test_vector4( );
	//test_vector5( );
	//test_vector6( );
	test_vector7( );
    return 0;
}