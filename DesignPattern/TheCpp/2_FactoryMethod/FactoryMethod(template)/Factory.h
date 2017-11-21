#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
using namespace std;

class IAbstractProduct;

class IAbstractFactory
{
public:
	virtual ~IAbstractFactory( );
	virtual IAbstractProduct* CreateProduct( ) = 0;
};

IAbstractFactory::~IAbstractFactory( )
{
	cout<<"IAbstractFactory::~IAbstractFactory( )"<<endl;
}

template <class T>
class ConcreteFactory:public IAbstractFactory
{
public:
	ConcreteFactory( );
	~ConcreteFactory( );
	virtual IAbstractProduct* CreateProduct( );
};

template <class T>
ConcreteFactory<T>::ConcreteFactory( )
{
	cout<<"ConcreteFactory<T>::ConcreteFactory( )"<<endl;
}

template <class T>
ConcreteFactory<T>:: ~ConcreteFactory( )
{
	cout<<"ConcreteFactory:: ~ConcreteFactory( )"<<endl;
}

template <class T>
IAbstractProduct* ConcreteFactory<T>::CreateProduct( )
{
	cout<<"T* TStandFactory<T>::CreateProduct( )"<<endl;
	return new T( );
}

#endif
