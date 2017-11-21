#ifndef PRODUCT_H_
#define PRODUCT_H_

#include <iostream>
using namespace std;

class IAbstractProduct
{
public:
	virtual ~IAbstractProduct( );
	virtual void ProductOperation( ) = 0;
};

class ConcreteProduct1:public IAbstractProduct
{
public:
	ConcreteProduct1( );
	virtual ~ConcreteProduct1( );
	virtual void ProductOperation( );
};

class ConcreteProduct2:public IAbstractProduct
{
public:
	ConcreteProduct2( );
	virtual ~ConcreteProduct2( );
	virtual void ProductOperation( );
};

#endif
