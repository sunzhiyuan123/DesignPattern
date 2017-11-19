#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <deque>
#include <queue>
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

static void test_queue1( )
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	
	cout<<"��ͷԪ��:"<<q.front( )<<endl;
	cout<<"���д�С:"<<q.size( )<<endl;
	while(!q.empty( ))
	{
		cout<<q.front( )<<endl;
		q.pop( );
	}
}

//teacher
class Teacher
{
public:
	int  age;
	char name[32];
	void printT( )
	{
		cout<<"age:"<<age<<endl;
	}
};

static void test_queue2( )
{
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;

	queue<Teacher> q;
	q.push(t1);
	q.push(t2);
	q.push(t3);
	
	while(!q.empty( ))
	{
		Teacher tmp = q.front( );
		tmp.printT( );
		q.pop( );
	}
}

static void test_queue3( )
{
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	queue<Teacher*> q;
	q.push(&t1);
	q.push(&t2);
	q.push(&t3);
	
	while(!q.empty( ))
	{
		//��ȡջ��Ԫ��
		Teacher *temp = q.front( );
		temp->printT( );
		//����ջ��Ԫ��
		q.pop( );
	}
}

int main( )
{
	test_queue1( );
	test_queue2( );
	test_queue3( );
	
    return 0;
}