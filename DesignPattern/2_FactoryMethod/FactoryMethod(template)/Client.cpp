#include "Factory.h"
#include "Product.h"
#include <iostream>
using namespace std;

int main( )
{
	IAbstractFactory  *pFactory = new ConcreteFactory<ConcreteProduct1>( );
	IAbstractProduct  *pProduct = pFactory->CreateProduct( );
	pProduct->ProductOperation( );
	delete pProduct;
	delete pFactory;
	
	cout<<endl<<endl<<endl;
#if 0
	pFactory = new ConcreteFactory<ConcreteProduct2>( );
	pProduct = pFactory->CreateProduct( );
	pProduct->ProductOperation( );
	delete pProduct;
	delete pFactory;
#endif
	
	return 0;
}
