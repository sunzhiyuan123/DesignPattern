#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

void printBuf(const char *p)
{
	//p[0] = 'z';
	char *p1 = NULL;
	//const char* ==> char*
	//把只读属性去掉
	p1 = const_cast<char*>(p);
	p1[0] = 'z';
	
	cout<<p<<endl;
}

int main( )
{
	char buf[] = "aaabbbccc";
	//要确保p所指向的内存空间确实能修改，如果不能修改会带来灾难
	printBuf(buf);
	
	return 0;
}