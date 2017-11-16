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

class Point
{
public:
    void init( )
    {
		output( );
    }
    static void output( )
    {
		printf("%d\n", m_nPointCount);
		//printf("%d\n", m_x);
    }
private:
	static int m_nPointCount;
	//int m_x;
};
int Point::m_nPointCount = 0;

void test1( )
{
	//1.不能通过类名来调用类的非静态成员函数
	//Point::init( );
    Point::output( );
}

void test2( )
{
	//2.类的对象可以使用静态成员函数和非静态成员函数。
	Point pt;
	pt.init( );
	pt.output( );
}

void test3( )
{
	//3.静态成员函数中不能引用非静态成员
	Point pt;
	pt.output( );
}

void test4( )
{
	//4.类的非静态成员函数可以调用用静态成员函数，但反之不能。
	Point pt;
	pt.output( );
}

	//5.类的静态成员变量必须先初始化再使用。
void test5( )
{

}

int main( )
{
	test1( );
	test2( );
	test3( );
	test4( );
	test5( );
	
    return 0;
}