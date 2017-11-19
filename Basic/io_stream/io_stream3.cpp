#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
#include <string.h>
using namespace std;  

/* 标准输出流对象
** cout.flush( ) 
** cout.put( )
** cout.write( )
** cout.width( )
** cout.fill( )
** cout.setf( )
*/

static void test_io1( )
{
	cout.put('h').put('h');
	cout<<endl;
	
	char *p = "hello itcast";
	cout.write(p,strlen(p))<<endl;;
	//cout<<endl;
	cout.write(p,strlen(p)-4)<<endl;;
	//cout<<endl;
}

static void test_io2( )
{


}

int main( )
{
	test_io1( );
	
    return 0;
}