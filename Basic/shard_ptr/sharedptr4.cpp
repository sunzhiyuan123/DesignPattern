#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>

using namespace std;

void any_func(void *p)
{
	cout << "some sth" << endl;
}

int main( )
{	
	//离开作用域调用 any_func。
	shared_ptr<void> A_ptr((void*)0, any_func);
	
    return 0;
}