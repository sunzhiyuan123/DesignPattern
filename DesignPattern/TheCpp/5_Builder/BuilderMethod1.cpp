#include <iostream>  // std::cout
#include <mutex>     // std::mutex, std::lock_guard
#include <stdexcept> // std::logic_error
#include <chrono>    // std::chrono::seconds
#include <thread>    // std::thread, std::this_thread::sleep_for
#include <vector>
#include <memory>
#include <string>
using namespace std;

class House
{
public:
	void setDoor(string door)
	{
		this->m_door = door;
	}
	void setWall(string wall)
	{
		this->m_wall = wall;
	}
	void setWindow(string window)
	{
		this->m_window = window;
	}
	
	string getDoor( )
	{
		cout<<m_door<<endl;
		return this->m_door;
	}
	string getWall( )
	{
		cout<<m_wall<<endl;
		return this->m_wall;
	}
	string getWindow( )
	{
		cout<<m_window<<endl;
		return this->m_window;
	}
private:
	string m_door;
	string m_wall;
	string m_window;
};

class Builder
{
public:
	Builder( )
	{
		m_house = new House( );
	}
	
	void makeBuild( )
	{
		buildWall(m_house);
		buildDoor(m_house);
		buildWindow(m_house);
	}
 	
	void buildWall(House *h)
	{
		h->setWall("wall");
	}
	void buildDoor(House *h)
	{
		h->setDoor("door");
	}
	void buildWindow(House *h)
	{
		h->setWindow("window");
	}
	House* getHouse( )
	{
		return m_house;
	}
private:
	House *m_house;
};

int main(void)
{
#if 0
	House *house = new House( );
	house->setDoor("door");
	house->setWall("wall");
	house->setWindow("window");
	delete house;
#endif
	House   *house;
	Builder *builder;
	builder = new Builder;
	builder->makeBuild( );
	house   = builder->getHouse( );
	
	house->getDoor( );
	house->getWall( );
	house->getWindow( );
	
    return 0;  
}
