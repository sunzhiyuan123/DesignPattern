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
	//1.����ͨ��������������ķǾ�̬��Ա����
	//Point::init( );
    Point::output( );
}

void test2( )
{
	//2.��Ķ������ʹ�þ�̬��Ա�����ͷǾ�̬��Ա������
	Point pt;
	pt.init( );
	pt.output( );
}

void test3( )
{
	//3.��̬��Ա�����в������÷Ǿ�̬��Ա
	Point pt;
	pt.output( );
}

void test4( )
{
	//4.��ķǾ�̬��Ա�������Ե����þ�̬��Ա����������֮���ܡ�
	Point pt;
	pt.output( );
}

	//5.��ľ�̬��Ա���������ȳ�ʼ����ʹ�á�
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