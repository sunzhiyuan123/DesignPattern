#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

template<class T, class U>
void add(T t, U u)
{
    auto s = t + u;
    cout << "s=" << s << endl;
}

int main( )
{
    // ���Զ������ƶ�
    auto a = 123;
    cout << "a=" << a << endl;
    auto s("fred");
    cout << "s=" << s << endl;
	
    // �߳�������˵�������������
    vector<int> vec(10);
    auto iter = vec.begin( );
    cout << "type of iter is " << typeid(iter).name( ) << endl;
	
    // ʹ��ģ�弼��ʱ�����ĳ������������������ģ�������ʹ��autoȷ����������
    add(101, 1.1);
}