#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;  

/* ��׼����������
** cin.get( )        һ��ֻ�ܶ�ȡһ���ַ�
** cin.get(һ������) ��ȡһ���ַ�
** cin.get(��������) ���Զ�ȡ�ַ���
** cin.getline( )    
** cin.ignore( )
** cin.peek( )
** cin.putback( )
*/

static void test_io1( )
{
	char buf1[256];
	char buf2[256];
	
	cout<<"������һ���ַ��� ���ж���ո� aa bbccdd"<<endl;
	
	cin >> buf1;
	//ȥ���ո�
	cin.ignore(2);
	
	cin.getline(buf2, sizeof(buf2));
	
	cout<<"buf1:"<<buf1<<endl;
	cout<<"buf2:"<<buf2<<endl;
}

int main( )
{
	test_io1( );
	
    return 0;
}