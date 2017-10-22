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
	
	//入栈
	for(int i=0;i<10;i++)
	{
		s.push(i+1);
	}
	
	cout<<"size:"<<s.size( )<<endl;
	
	//出栈
	while(!s.empty( ))
	{
		//获取栈顶元素
		int tmp = s.top( );
		cout<<tmp<<endl;
		//弹出栈顶元素
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
		//获取栈顶元素
		Teacher temp = s.top( );
		temp.printT( );
		//弹出栈顶元素
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
		//获取栈顶元素
		Teacher *temp = s.top( );
		temp->printT( );
		//弹出栈顶元素
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