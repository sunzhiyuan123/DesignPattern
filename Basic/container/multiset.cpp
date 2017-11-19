#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <deque>
#include <queue>
#include <list>
#include <set>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;  

static void test_multiset1( )
{
	multiset<int> set1;
	
	for(int i=0;i<10;i++)
	{
		set1.insert(i);
	}
	
	for(multiset<int>::iterator it=set1.begin( );it!=set1.end();it++)
	{
		cout<<*it<<endl;
	}
	
	while(!set1.empty( ))
	{
		multiset<int>::iterator it=set1.begin( );
		cout<<*it<<" ";
		set1.erase(it);
	}
}

int main( )
{
	test_multiset1( );
    return 0;
}