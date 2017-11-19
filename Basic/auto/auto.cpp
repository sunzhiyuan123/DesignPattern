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
    // 简单自动类型推断
    auto a = 123;
    cout << "a=" << a << endl;
    auto s("fred");
    cout << "s=" << s << endl;
	
    // 冗长的类型说明（如迭代器）
    vector<int> vec(10);
    auto iter = vec.begin( );
    cout << "type of iter is " << typeid(iter).name( ) << endl;
	
    // 使用模板技术时，如果某个变量的类型依赖于模板参数，使用auto确定变量类型
    add(101, 1.1);
}