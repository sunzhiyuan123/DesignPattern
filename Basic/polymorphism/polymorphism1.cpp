#include <iostream>

using namespace std;

class Base
{
public:
	virtual void Fun1( )
	{
		cout<<"Base::Fun1"<<endl;
	}
	virtual void Fun2( )
	{
		cout<<"Base::Fun2"<<endl;
	}
	void Fun3( )
	{
		cout<<"Base::Fun3"<<endl;
	}
	Base( )
	{
		cout<<"Base"<<endl;
	}
	//���һ������Ϊ��̬����,Ҫ���������������������麯��,����ͻ����ڴ�й©�ķ��ա�
	virtual ~Base( )
	{
		cout<<"~Base"<<endl;
	}
};

class Derived:public Base
{
public:
	virtual void Fun1( )
	{
		cout<<"Derived::Fun1"<<endl;
	}
	virtual void Fun2( )
	{
		cout<<"Derived::Fun2"<<endl;
	}
	void Fun3( )
	{
		cout<<"Derived::Fun3"<<endl;
	}
	Derived( )
	{
		cout<<"Derived"<<endl;
	}
	~Derived( )
	{
		cout<<"~Derived"<<endl;
	}
};

//1.���һ�������ڻ����б�����Ϊ�麯���������������������ж����麯��
//2.ֻ��ͨ������ָ��������õ����麯������������̬��
//3.�麯����������Ϊ��̬

int main( )
{
	Base  *p;
	p = new Derived;
	
	p->Fun1( ); //Fun1���麯��������ָ��ָ����������󣬵��õ��������������麯����
	p->Fun2( );
	p->Fun3( ); //Fun3���麯��������pָ��ʵ��������������Ӧ��ĳ�Ա������
	
	delete p;
	
	return 0;
}