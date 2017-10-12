#include <iostream>
using namespace std;

class Product
{
public:
	Product( )
	{
		cout<< "Product ..."<<endl;
	}
	
	virtual ~Product( )
	{
		cout<< "~Product ..."<<endl;
	}
	
	virtual void Show( ) = 0;
};

class ProductA : public Product
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

class ProductB : public Product
{
public:
	void Show( )
	{
		cout<< "I'm ProductB"<<endl;
	}
};

class ProductC : public Product
{
public:
	void Show( )
	{
		cout<<"I'm productC"<<endl;
	}
};

class Factory
{
public:
	Factory( )
	{
		cout<<"Factory ..."<<endl;
	}
	virtual ~Factory( )
	{
		cout<<"~Factory ..."<<endl;
	}
	virtual Product *CreateProduct( ) = 0;
};

class FactoryA : public Factory
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
	
	Product *CreateProduct( )
	{
		return new ProductA ( );
	}
};

class FactoryB : public Factory
{
public:
	Product *CreateProduct( )
	{
		return new ProductB ( );
	}
};

class FactoryC : public Factory
{
public:
	Product *CreateProduct( )
	{
		return new ProductC ( );
	}
};

int main(int argc , char *argv [])
{
	Factory *factoryA = new FactoryA ( );
	Product *productA = factoryA->CreateProduct( );
	productA->Show( );
	
#if 0
	Factory *factoryB = new FactoryB ( );
	Product *productB = factoryB->CreateProduct( );
	productB->Show( );
	
	Factory *factoryC = new FactoryC ( );
	Product *productC = factoryC->CreateProduct( );
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