#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class A
{
public:
	A(int a) : a_(a)
	{
		cout << "A Constructor..." << endl;
	}
	~A( )
	{
		cout << "A Destructor..." << endl;
	}
	
	int a_;
};

void test_weak_ptr1( )
{
	shared_ptr<A> sp(new A(10));
	weak_ptr<A>   wp(sp);//ָ��sp��ָ����ڴ�
	//sp.reset( );
	
	//����������,wp.lock( )��������һ��ָ��������shared_ptr,���򷵻�һ����shared_ptr.
	if (shared_ptr<A> pa = wp.lock( ))
	{
		cout << pa->a_ << endl;
	}
	else
	{
		cout << "wp is nullptr" << endl;
	}
}

void test_weak_ptr2( )
{
	shared_ptr<A> sp(new A(5));
	weak_ptr<A>   wp(sp);
	sp.reset( );                    //��ʱsp������
	//weak_ptr���ṩ��expired( )�������ж���ָ�����Ƿ��Ѿ�������
	cout << wp.expired( ) << endl;  //true��ʾ�ѱ����٣�����Ϊfalse
}

void Check(weak_ptr<int> &wp)
{
	//weak_ptr��û������operator->��operator *����������˲���ֱ��ͨ��weak_ptrʹ�ö���
	//���͵��÷��ǵ�����lock���������shared_ptrʾ������������ԭʼ����
    shared_ptr<int> sp = wp.lock( ); //���»��shared_ptr����
    if (sp != nullptr)
    {
        cout<<"The value is "<<*sp<<endl;
    }
    else
    {
        cout<<"Pointer is invalid."<<endl;
    }
}

void test_weak_ptr3( )
{
    shared_ptr<int> sp1(new int(10));
    shared_ptr<int> sp2 = sp1;
    weak_ptr<int>   wp  = sp1; //ָ��sp1��ָ����ڴ�
	
    cout<<*sp1<<endl;
    cout<<*sp2<<endl;
    Check(wp);
	
    sp1.reset( );
    cout<<*sp2<<endl;
    Check(wp);
	
    sp2.reset( );
    Check(wp);
}

class ClassB1;

class ClassA1
{
public:
    ClassA1( )
	{
		cout << "ClassA1 Constructor..." << endl;
	}
    ~ClassA1( )
	{
		cout << "ClassA1 Destructor..." << endl;
	}
    shared_ptr<ClassB1> pb;  // ��A������B
};

class ClassB1
{
public:
    ClassB1( )
	{
		cout << "ClassB1 Constructor..." << endl;
	}
    ~ClassB1( )
	{
		cout << "ClassB1 Destructor..." << endl;
	}
    shared_ptr<ClassA1> pa;  // ��B������A
};

//�������ü�����ʵ�ֵļ��������Ǳ��ⲻ��ѭ�����ã��������ã������� shared_ptrҲ������.
void test_weak_ptr4( )
{
    shared_ptr<ClassA1> spa = make_shared<ClassA1>( );
    shared_ptr<ClassB1> spb = make_shared<ClassB1>( );
    spa->pb = spb;
    spb->pa = spa;
    // ����������˼��һ�£�spa��spb���ͷ���Դô��
}

//ѭ�����õĸĽ�
class ClassBB;

class ClassAA
{
public:
    ClassAA( )
	{
		cout << "ClassAA Constructor..." << endl;
	}
    ~ClassAA( )
	{
		cout << "ClassAA Destructor..." << endl;
	}
	
    weak_ptr<ClassBB> pb;  // ��A������B
};

class ClassBB
{
public:
    ClassBB( )
	{
		cout << "ClassBB Constructor..." << endl;
	}
    ~ClassBB( )
	{ 
		cout << "ClassBB Destructor..." << endl;
	}
    weak_ptr<ClassAA> pa;  // ��B������A
};

void test_weak_ptr5( )
{
    shared_ptr<ClassAA> spa = make_shared<ClassAA>( );
    shared_ptr<ClassBB> spb = make_shared<ClassBB>( );
    spa->pb = spb;
    spb->pa = spa;
    // ����������˼��һ�£�spa��spb���ͷ���Դô��
}

int main( )
{
	//test_weak_ptr1( );
	//test_weak_ptr2( );
	test_weak_ptr3( );
	//test_weak_ptr4( );
	//test_weak_ptr5( );
	
    return 0;
}