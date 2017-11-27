#include <iostream>

using namespace std;

class Cobject
{
public:
	virtual void Serialize( )
	{
		cout<<"Cobject::Serialize"<<endl;
	}
};

class Cdocument:public Cobject
{
public:
	int data1_;
	void Fun( )
	{
		cout<<"Cdocument::Fun"<<endl;
		Serialize( );
	}
	virtual void Serialize( )
	{
		cout<<"Cdocument::Serialize"<<endl;
	}
	Cdocument( )
	{
		cout<<"Cdocument"<<endl;
	}
	Cdocument(const Cdocument& other)
	{
		cout<<"Cdocument(const Cdocument& other)"<<endl;
	}
};

class CMydoc:public Cdocument
{
public:
	int data2;
	virtual void Serialize( )
	{
		cout<<"CMydoc::Serialize"<<endl;
	}
};

int main( )
{
	Cdocument *pCdocument;
	CMydoc    mydoc;
	mydoc.Fun( );
	cout<<endl;
	
	pCdocument = &mydoc;
	pCdocument->Fun( );
	cout<<endl;
	
	CMydoc *pmydoc = new CMydoc;
	pmydoc->Fun( );
	cout<<endl;
	
	((Cdocument)(mydoc)).Fun( );//mydoc对象强制转换成Cdocument对象，向上转型(派生类的特有成员会消失，就连虚表也发生了变化)。
								//完完全全将派生类对象转换成了基类对象，包括虚表。
	
	return 0;
}