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
	
	((Cdocument)(mydoc)).Fun( );//mydoc����ǿ��ת����Cdocument��������ת��(����������г�Ա����ʧ���������Ҳ�����˱仯)��
								//����ȫȫ�����������ת�����˻�����󣬰������
	
	return 0;
}