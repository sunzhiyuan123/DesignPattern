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
	//��ֻ������ȥ��
	p1 = const_cast<char*>(p);
	p1[0] = 'z';
	
	cout<<p<<endl;
}

int main( )
{
	char buf[] = "aaabbbccc";
	//Ҫȷ��p��ָ����ڴ�ռ�ȷʵ���޸ģ���������޸Ļ��������
	printBuf(buf);
	
	return 0;
}