#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

class Animal
{
public:
	virtual void eat( ) = 0;
};

class Dog:public Animal
{
public:
	virtual void eat( )
	{
		cout<<"Dog eat"<<endl;
	}
	
	void doHome( )
	{
		cout<<"doHome"<<endl;
	}
};

class Cat:public Animal
{
public:
	virtual void eat( )
	{
		cout<<"Cat eat"<<endl;
	}
	
	void doThing( )
	{
		cout<<"doThing"<<endl;
	}
};

void playObj(Animal *base)
{
	base->eat( );
	
	Dog *pDog = dynamic_cast<Dog*>(base);
	if(nullptr == pDog)
	{
		pDog->doHome( );
	}

	Cat *pCat = dynamic_cast<Cat*>(base);
	if(nullptr == pCat)
	{
		pCat->doThing( );
	}
}

int main( )
{
	Dog dog;
	Cat cat;
	
	playObj(&dog);
	playObj(&cat);

	Animal *base = &dog;
	base = static_cast<Animal*>(&dog);
}