#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;  

class Person
{
public:
	string  name;
	int     age;
	string  tel;
	double  sal;
};

void test_multimap1( )
{
	Person p1,p2,p3,p4,p5;
	multimap<string,Person> map2;
	
	p1.name = "wang1";
	p1.age  = 31;
	
	p2.name = "wang2";
	p2.age  = 32;
	
	p3.name = "zhang3";
	p3.age  = 33;
	
	p4.name = "zhang4";
	p4.age  = 34;
	
	p5.name = "zhao5";
	p5.age  = 35;
	//sale 部门
	map2.insert(make_pair("sale",p1));
	map2.insert(make_pair("sale",p2));
	//development
	map2.insert(make_pair("development",p3));
	map2.insert(make_pair("development",p4));
	//Financial
	map2.insert(make_pair("Financial",p5));
	
	for(multimap<string,Person>::iterator it= map2.begin( );it!=map2.end( );it++)
	{
		cout<<it->first<<" "<<it->second.name<<endl;
	}
	
	//按部门显示员工人数
	int num = map2.count("development");
	cout<<"development num:"<<map2.count("development")<<endl;
	cout<<"sale num:"<<map2.count("sale")<<endl;
	cout<<"development num:"<<map2.count("Financial")<<endl;
	
	multimap<string,Person>::iterator it2 = map2.find("development");
	
	int tag = 0;
	while((it2 != map2.end( ))&&(tag<num))
	{
		cout<<it2->first<<" "<<it2->second.name<<endl;
		it2++;
		tag++;
	}
}

void test_multimap2( )
{
	Person p1,p2,p3,p4,p5;
	multimap<string,Person> map2;
	
	p1.name = "wang1";
	p1.age  = 31;
	
	p2.name = "wang2";
	p2.age  = 32;
	
	p3.name = "zhang3";
	p3.age  = 33;
	
	p4.name = "zhang4";
	p4.age  = 34;
	
	p5.name = "zhao5";
	p5.age  = 35;
	//sale 部门
	map2.insert(make_pair("sale",p1));
	map2.insert(make_pair("sale",p2));
	//development
	map2.insert(make_pair("development",p3));
	map2.insert(make_pair("development",p4));
	//Financial
	map2.insert(make_pair("Financial",p5));
	
	for(multimap<string,Person>::iterator it= map2.begin( );it!=map2.end( );it++)
	{
		//cout<<it->first<<" "<<it->second.name<<endl;
		if(it->second.age == 32)
		{
			it->second.name = "name32";
		}
	}
	
	for(multimap<string,Person>::iterator it= map2.begin( );it!=map2.end( );it++)
	{
		cout<<it->first<<" "<<it->second.name<<endl;
	}
}

int main( )
{
	//test_multimap1( );
	test_multimap2( );
	
    return 0;
}