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
	//如果一个类作为多态基类,要将基类的析构函数定义成虚函数,否则就会有内存泄漏的风险。
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

//1.如果一个函数在基类中被声明为虚函数，则他在所有派生类中都是虚函数
//2.只有通过基类指针或者引用调用虚函数才能引发动态绑定
//3.虚函数不能声明为静态

int main( )
{
	Base  *p;
	p = new Derived;
	
	p->Fun1( ); //Fun1是虚函数，基类指针指向派生类对象，调用的是派生类对象的虚函数。
	p->Fun2( );
	p->Fun3( ); //Fun3非虚函数，根据p指针实际类型来调用相应类的成员函数。
	
	delete p;
	
	return 0;
}