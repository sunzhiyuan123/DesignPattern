#include <iostream>
#include <vector>
using namespace std;

class Singleton
{
public:
    //ȫ�ַ��ʽӿ�
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
    static Singleton *instance_; //����������
};  

Singleton *Singleton::instance_; //����������

int main(void)
{
    Singleton *s1 = Singleton::GetInstance( );
	//s2�ĵ�ַ����s1����ָ��ͬһ����
    Singleton *s2 = Singleton::GetInstance( );
	
    //Singleton s3(*s1); //��Ȼ�ǵ���ģʽ���ǲ����������ġ���������
	
    return 0;  
}
