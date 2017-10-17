#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
using namespace std;

class IAbstractProduct;

template<class T>
class IAbstractFactory
{
	static_assert(std::is_base_of<IAbstractProduct, T>::value, "Class T must derive from IAbstractProduct");
public:
	virtual ~IAbstractFactory( );
	virtual IAbstractProduct* CreateProduct( ) = 0;
};

template<class T>
IAbstractFactory<T>::~IAbstractFactory( )
{
	cout<<"IAbstractFactory::~IAbstractFactory( )"<<endl;
}

template <class T>
class TStandardFactory:public IAbstractFactory<T>
{
public:
	TStandardFactory( );
	~TStandardFactory( );
	virtual IAbstractProduct* CreateProduct( );
	
	//template<class U>
	//static  IAbstractProduct* CreateInstance(U &u);
};

template <class T>
TStandardFactory<T>::TStandardFactory( )
{
	cout<<"TStandardFactory<T>::TStandardFactory( )"<<endl;
}

template <class T>
TStandardFactory<T>:: ~TStandardFactory( )
{
	cout<<"TStandardFactory:: ~TStandardFactory( )"<<endl;
}

template <class T>
IAbstractProduct* TStandardFactory<T>::CreateProduct( )
{
	cout<<"T* TStandFactory<T>::CreateProduct( )"<<endl;
	return new T( );
}

//template <class T>
//template <class U>
//inline IAbstractProduct* TStandardFactory<T>::CreateInstance(U &u)
//{

//}

#endif
