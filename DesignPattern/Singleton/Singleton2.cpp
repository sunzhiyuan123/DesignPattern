#include <iostream>
#include <vector>
using namespace std;

class Singleton
{
public:
    //全局访问接口
    static Singleton *GetInstance( )
    {
        if(instance_ == NULL)
        {
            instance_ = new Singleton;
        }
        return instance_;
    }
	
    ~Singleton( )
    {
        cout << "~Singleton"<< endl;
    }
	
private:  
    Singleton(const Singleton& other);
    Singleton & operator=(const Singleton& other);
    Singleton( )
    {
		cout << "Singleton"<<endl;
    }
    static Singleton *instance_; //引用性声明
};  

Singleton *Singleton::instance_; //定义性声明

int main(void)
{
    Singleton *s1 = Singleton::GetInstance( );
	//s2的地址等于s1，即指向同一对象
    Singleton *s2 = Singleton::GetInstance( );
	
    //Singleton s3(*s1); //既然是单例模式，是不允许被拷贝的。编译会出错
	
    return 0;  
}
