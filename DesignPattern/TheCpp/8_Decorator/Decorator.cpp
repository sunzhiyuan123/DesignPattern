#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Car
{
public:
	virtual void show( )=0;
};

class RunCar:public Car
{
	virtual void show( )
	{
		cout<<"can run"<<endl;
	}
};

class SwimCarDirector:public Car
{
public:
	SwimCarDirector(Car *car)
	{
		m_car = car;
	}
	void swim( )
	{
		cout<<"can swim"<<endl;
	}
	virtual void show( )
	{
		m_car->show( );
		swim( );
	}
private:
	Car *m_car;
};

class FlyCarDirector:public Car
{
public:
	FlyCarDirector(Car *car)
	{
		m_car = car;
	}
	void fly( )
	{
		cout<<"can fly"<<endl;
	}
	virtual void show( )
	{
		m_car->show( );
		fly( );
	}
private:
	Car *m_car;
};

//装饰者模式：动态的给一个对象添加一些额外的职责，
//就增加功能来说，此模式比生成子类更为灵活。
int main(void)
{
	Car *car = new RunCar( );
	car->show( );
	
	cout<<endl;
	
	Car *flycar = new FlyCarDirector(car);
	flycar->show( );
	
	cout<<endl;
	
	Car *swicar = new SwimCarDirector(flycar);
	swicar->show( );
	
    return 0;  
}
