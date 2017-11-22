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
	
	int data1;
};

class Derived:public Base
{
public:
	virtual void Fun2( )
	{
		cout<<"Derived::Fun2"<<endl;
	}
	virtual void Fun3( )
	{
		cout<<"Derived::Fun3"<<endl;
	}
	int data2;
};

typedef void (*FUNC)( );

int main( )
{
	Base 		 base;
	Derived 	 derived;
	FUNC 		 func;
	unsigned long int *pVptr;
	unsigned long int *pVtable;
	
	cout<<sizeof(Base)<<endl;
	cout<<sizeof(Derived)<<endl;
	
	pVptr   = (unsigned long int *)(&base);
	pVtable = (unsigned long int *)(*pVptr);
	
	func = (FUNC)pVtable[0];
	func( );
	func = (FUNC)pVtable[1];
	func( );
	
	cout<<endl;
	
	pVptr   = (unsigned long int *)(&derived);
	pVtable = (unsigned long int *)(*pVptr);
	
	func = (FUNC)pVtable[0];
	func( );
	func = (FUNC)pVtable[1];
	func( );
	func = (FUNC)pVtable[2];
	func( );
	
	cout<<endl;
	
	//����ָ��ָ����������󣬾Ϳ���ȡ������������ͷ�ĸ��ֽڣ��Ӷ�ȡ������������
	Base *pBase = &derived;
	pBase->Fun1( );
	pBase->Fun2( );
	
	return 0;
}