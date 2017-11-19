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
	virtual void buildWall( )   = 0;
	virtual void buildDoor( )   = 0;
	virtual void buildWindow( ) = 0;
	virtual House* getHouse( )  = 0;
};

//��Ԣ���̶�
class FlatBuilder:public Builder
{
public:
	FlatBuilder( )
	{
		m_house = new House( );
	}
	virtual void buildWall( )
	{
		m_house->setWall("Flat wall");
	}
	virtual void buildDoor( )
	{
		m_house->setDoor("Flat door");
	}
	virtual void buildWindow( )
	{
		m_house->setWindow("Flat window");
	}
	virtual House* getHouse( )
	{
		return m_house;
	}
private:
	House *m_house;
};

//�������̶�
class VillaBuilder:public Builder
{
public:
	VillaBuilder( )
	{
		m_house = new House( );
	}
	virtual void buildWall( )
	{
		m_house->setWall("Villa wall");
	}
	virtual void buildDoor( )
	{
		m_house->setDoor("Villa door");
	}
	virtual void buildWindow( )
	{
		m_house->setWindow("Villa window");
	}
	virtual House* getHouse( )
	{
		return m_house;
	}
private:
	House *m_house;
};

//���ʦ(ָ����)������ҵ���߼�
//�����ӣ�        �ɾ���Ļ�
class Designers
{
public:
	Designers(Builder *build)
	{
		m_build = build;
	}
	void Construct( )
	{
		m_build->buildWall( );
		m_build->buildDoor( );
		m_build->buildWindow( );
	}
private:
	Builder *m_build;
};

int main(void)
{
	House        *house;
	Builder      *build;
	Designers    *designers;
	
	//��һ����������Ĺ��̶�
	build     = new VillaBuilder( );
	//���ʦָ�ӹ��̶Ӹɻ�
	designers = new Designers(build);
	designers->Construct( );
	house = build->getHouse( );
	house->getDoor( );
	house->getWall( );
	house->getWindow( );
	delete house;
	delete build;
	delete designers;
	
	//��һ�����칫Ԣ�Ĺ��̶�
	build     = new FlatBuilder( );
	//���ʦָ�ӹ��̶Ӹɻ�
	designers = new Designers(build);
	designers->Construct( );
	house = build->getHouse( );
	house->getDoor( );
	house->getWall( );
	house->getWindow( );
	delete house;
	delete build;
	delete designers;
	
    return 0;  
}
