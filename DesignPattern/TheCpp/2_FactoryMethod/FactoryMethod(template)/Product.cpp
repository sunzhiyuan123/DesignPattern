#include "Product.h"
#include <iostream>
using namespace std;

//class IAbstractProduct
IAbstractProduct::~IAbstractProduct( )
{
	cout<<"IAbstractProduct::~IAbstractProduct( )"<<endl;
}

void IAbstractProduct::ProductOperation( )
{
	cout<<"void IAbstractProduct::ProductOperation( )"<<endl;
}

//class ConcreteProduct1
ConcreteProduct1::ConcreteProduct1( )
{
	cout<<"ConcreteProduct1::ConcreteProduct1( )"<<endl;
}

ConcreteProduct1::~ConcreteProduct1( )
{
	cout<<"ConcreteProduct1::~ConcreteProduct1( )"<<endl;
}

void ConcreteProduct1::ProductOperation( )
{
	cout<<"void ConcreteProduct1::ProductOperation( )"<<endl;
}

//class ConcreteProduct2
ConcreteProduct2::ConcreteProduct2( )
{
	cout<<"ConcreteProduct2::ConcreteProduct2( )"<<endl;
}

ConcreteProduct2::~ConcreteProduct2( )
{
	cout<<"ConcreteProduct2::~ConcreteProduct2( )"<<endl;
}

void ConcreteProduct2::ProductOperation( )
{
	cout<<"void ConcreteProduct2::ProductOperation( )"<<endl;
}
