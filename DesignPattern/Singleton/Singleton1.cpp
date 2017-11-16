#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Singleton
{
public:
    //全局访问接口
    static Singleton& GetInstance( )
    {
		static std::unique_ptr<Singleton> instance;
		
		if (nullptr == instance)
		{
			instance = std::unique_ptr<Singleton>(new Singleton);
		}
		
        return *instance;
    }
	
	void print( )
	{
		cout<<"enter print"<<endl;
	}
	
    ~Singleton( )
    {
        cout << "~Singleton"<< endl;
    }
	
private:
    Singleton(Singleton&) = delete;
    Singleton( )
    {
		cout << "Singleton"<<endl;
    }
};

void test1( )
{
	Singleton& s1 = Singleton::GetInstance( );
	s1.print( );
	auto& s2 = Singleton::GetInstance( );
	s2.print( );
}

int main(void)
{
	test1( );
	cout << "exit"<<endl;
	
    return 0;  
}
