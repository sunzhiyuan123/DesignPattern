#include <iostream>
using namespace std;

class IAbstractProduct
{
public:
	IAbstractProduct( )
	{
		cout<< "IAbstractProduct ..."<<endl;
	}
	
	virtual ~IAbstractProduct( )
	{
		cout<< "~IAbstractProduct ..."<<endl;
	}
	
	virtual void Show( ) = 0;
};

class ProductA : public IAbstractProduct
{
public:
	ProductA( )
	{
		cout<< "ProductA ..."<<endl;
	}
	
	~ProductA( )
	{
		cout<< "~ProductA ..."<<endl;
	}
	
	void Show( )
	{
		cout<< "I'm ProductA"<<endl;
	}
};

class ProductB : public IAbstractProduct
{
public:
	void Show( )
	{
		cout<< "I'm ProductB"<<endl;
	}
};

class ProductC : public IAbstractProduct
{
public:
	void Show( )
	{
		cout<<"I'm productC"<<endl;
	}
};

class IAbstractFactory
{
public:
	IAbstractFactory( )
	{
		cout<<"IAbstractFactory ..."<<endl;
	}
	virtual ~IAbstractFactory( )
	{
		cout<<"~IAbstractFactory ..."<<endl;
	}
	virtual IAbstractProduct *CreateProduct( ) = 0;
};

class FactoryA : public IAbstractFactory
{
public:
	FactoryA( )
	{
		cout<<"FactoryA ..."<<endl;
	}

	~FactoryA( )
	{
		cout<<"~FactoryA ..."<<endl;
	}
	
	IAbstractProduct *CreateProduct( )
	{
		return new ProductA ( );
	}
};

class FactoryB : public IAbstractFactory
{
public:
	IAbstractProduct *CreateProduct( )
	{
		return new ProductB ( );
	}
};

class FactoryC : public IAbstractFactory
{
public:
	IAbstractProduct *CreateProduct( )
	{
		return new ProductC ( );
	}
};

int main(int argc , char *argv [])
{
	IAbstractFactory *factoryA = new FactoryA ( );
	IAbstractProduct *productA = factoryA->CreateProduct( );
	productA->Show( );
	
#if 0
	IAbstractFactory *factoryB = new FactoryB ( );
	IAbstractProduct *productB = factoryB->CreateProduct( );
	productB->Show( );
	
	IAbstractFactory *factoryC = new FactoryC ( );
	IAbstractProduct *productC = factoryC->CreateProduct( );
	productC->Show( );
#endif
	if (factoryA != NULL)
	{
		delete factoryA;
		factoryA = NULL;
	}
	
	if (productA != NULL)
	{
		delete productA;
		productA = NULL;
	}
#if 0
	if (factoryB != NULL)
	{
		delete factoryB;
		factoryB = NULL;
	}
	
	if (productB != NULL)
	{
		delete productB;
		productB = NULL;
	}
	
	if (factoryC != NULL)
	{
		delete factoryC;
		factoryC = NULL;
	}
	
	if(productC != NULL)
	{
		delete productC;
		productC = NULL;
	}
#endif

	return 0;
}