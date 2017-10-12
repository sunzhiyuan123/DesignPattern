#ifndef FACTORY_H_
#define FACTORY_H_

#include <iostream>
using namespace std;

class AbstractProduct;

class AbstractFactory
{
public:
	virtual ~AbstractFactory( );
	virtual AbstractProduct* CreateProduct( ) = 0;
};

AbstractFactory::~AbstractFactory( )
{
	cout<<"AbstractFactory::~AbstractFactory( )"<<endl;
}

template <class T>
class TStandardFactory:public AbstractFactory
{
public:
	TStandardFactory( );
	virtual ~TStandardFactory( );
	virtual AbstractProduct* CreateProduct( );
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
AbstractProduct* TStandardFactory<T>::CreateProduct( )
{
	cout<<"T* TStandFactory<T>::CreateProduct()"<<endl;
	return new T( );
}

#endif
