#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <algorithm>
using namespace std;  

static void test_stack1( )
{
	stack<int> s;
	
	//��ջ
	for(int i=0;i<10;i++)
	{
		s.push(i+1);
	}
	
	cout<<"size:"<<s.size( )<<endl;
	
	//��ջ
	while(!s.empty( ))
	{
		//��ȡջ��Ԫ��
		int tmp = s.top( );
		cout<<tmp<<endl;
		//����ջ��Ԫ��
		s.pop( );
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

static void test_stack2( )
{
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	stack<Teacher> s;
	s.push(t1);
	s.push(t2);
	s.push(t3);
	
	while(!s.empty( ))
	{
		//��ȡջ��Ԫ��
		Teacher temp = s.top( );
		temp.printT( );
		//����ջ��Ԫ��
		s.pop( );
	}
}

static void test_stack3( )
{
	Teacher t1,t2,t3;
	t1.age = 31;
	t2.age = 32;
	t3.age = 33;
	stack<Teacher*> s;
	s.push(&t1);
	s.push(&t2);
	s.push(&t3);
	
	while(!s.empty( ))
	{
		//��ȡջ��Ԫ��
		Teacher *temp = s.top( );
		temp->printT( );
		//����ջ��Ԫ��
		s.pop( );
	}
}

int main( )
{
	test_stack1( );
	test_stack2( );
	test_stack3( );
	
    return 0;
}