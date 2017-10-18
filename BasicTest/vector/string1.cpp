#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
using namespace std;  

void test_string1( )
{
	string s1 = "abcdefg";
	
	for(auto i=0;i<s1.length( );i++)
	{
		cout<<s1[i]<<endl;
	}
	
	cout<<"  "<<endl;
	
	for(string::iterator it = s1.begin( ); it!=s1.end(); it++)
	{
		cout<<*it<<endl;
	}
	
	cout<<"  "<<endl;
	
	for(auto i=0;i<s1.length( );i++)
	{
		cout<<s1.at(i)<<endl;
	}
}

void test_string2( )
{
	//string ==> char*
	string s1 = "abcdefg";
	printf("s1=%s\n",s1.c_str( ));
	//char*  ==> string
	
	//string中的内容拷贝到buffer中
	char buf1[100] = {0};
	s1.copy(buf1,3,0);//注意：只给拷贝3个字符 不会变成C风格的字符串（没有'\0'）
	cout<<"buf1:"<<buf1<<endl;
}

void test_string3( )
{
	string s1 = "aaa";
	string s2 = "bbb";
	
	s1 = s1+s2;
	cout<<"s1:"<<s1<<endl;
	
	string s3 = "ccc";
	string s4 = "ddd";
	s3.append(s4);
	cout<<"s3:"<<s1<<endl;
}

void test_string4( )
{
	string s1 = "wbm hello wbm 111 wbm 222 wbm 333";
	//int index = s1.find("wbm",0);
	//cout<<"index:"<<index<<endl;
	
	//求wbm出现的次数 每一次出现的数组下标
	int offindex = s1.find("wbm",0);
	while(offindex != string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		offindex = offindex+1;
		offindex = s1.find("wbm",offindex);
	}
	
	//把小写wbm 替换成大写WBM
	offindex = s1.find("wbm",0);
	while(offindex != string::npos)
	{
		cout<<"offindex:"<<offindex<<endl;
		s1.replace(offindex, 3, "WBM");
		offindex = offindex+1;
		offindex = s1.find("wbm",offindex);
	}
	
	cout<<"s1替换后的结果:"<<s1<<endl;
	
	string s3 = "aaa bbb ccc";
	s3.replace(0,3,"AAA");
	cout<<"s3:"<<s3<<endl;
}

int main( )
{
	//test_string1( );
	//test_string2( );
	//test_string3( );
	test_string4( );
	
    return 0;
}