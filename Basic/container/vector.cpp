#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;  

void test_vector1( )
{
	vector<int> v1;
	cout<<"length:"<<v1.size( )<<endl;
	//ÏòÎ²²¿²åÈëÔªËØ
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout<<"length:"<<v1.size( )<<endl;
	
	//»ñÈ¡Í·²¿ÔªËØ
	cout<<"Í·²¿ÔªËØ:"<<v1.front( )<<endl;
	
	//ĞŞ¸ÄÍ·²¿ÔªËØ º¯Êı·µ»ØÖµµ±×óÖµ  Ó¦¸Ã·µ»ØÒ»¸öÒıÓÃ
	v1.front( ) = 11;
	v1.back( )  = 55;
	
	while(v1.size( ) > 0)
	{
		//»ñÈ¡Î²²¿ÔªËØ
		cout<<"Î²²¿ÔªËØ:"<<v1.back( )<<endl;
		//É¾³ıÎ²²¿ÔªËØ
		v1.pop_back( );
	}
	cout<<"length:"<<v1.size( )<<endl;
}

//vectorµÄ³õÊ¼»¯
void test_vector2( )
{
	vector<int> v1;
	
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	
	//¶ÔÏó³õÊ¼»¯
	vector<int> v2 = v1;
	vector<int> v3(v2.begin( ),v2.begin( )+2);
}

static void printV(vector<int> &v)
{
	for(int i=0;i<v.size( );i++)
	{
		cout<<v[i]<<endl;
	}
}

void test_vector3( )
{
	//ÌáÇ°°ÑÄÚ´æ×¼±¸ºÃ
	vector<int> v1(10);
	//push_backº¯ÊıÊÇÔÚÊı×éÔªËØµÄÎ²²¿Ìí¼ÓÔªËØ
	v1.push_back(100);
	v1.push_back(200);
	
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	
	cout<<"length:"<<v1.size( )<<endl;
	
	printV(v1);
}

//1.µü´úÆ÷µÄÀí½â
//1       3     5   
//begin()          end( )
//Ê×µØÖ·           ÈİÆ÷µÄºóÃæ
//µ±it == v1.end( )µÄÊ±ºò ËµÃ÷Õâ¸öÈİÆ÷ÒÑ¾­±éÀúÍê±ÏÁË

//2.µü´úÆ÷µÄÖÖÀà
//ÕıÏòµü´úÆ÷  ÄæÏòµü´úÆ÷µÈ
void test_vector4( )
{
	vector<int> v1(10);
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	//ÕıÏò±éÀúÈİÆ÷
	for(vector<int>::iterator it = v1.begin( ); it != v1.end( ); it++)
	{
		cout<<*it<<endl;
	}
	
	//·´Ïò±éÀúÈİÆ÷
	for(vector<int>::reverse_iterator rit = v1.rbegin( ); rit != v1.rend( ); rit++)
	{
		cout<<*rit<<endl;
	}
}

void test_vector5( )
{
	vector<int> v1(10);
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	//Çø¼äÉ¾³ı
	v1.erase(v1.begin( ),v1.begin( )+3);
	//¸ù¾İÔªËØµÄÎ»ÖÃÉ¾³ı Ö¸¶¨Î»ÖÃÉ¾³ı
	v1.erase(v1.begin( ));
	printV(v1);
	cout<<endl;
	//¸ù¾İÔªËØÖµÉ¾³ı
	v1[0] = 2;
	v1[1] = 2;
	printV(v1);
	cout<<endl;
	for(vector<int>::iterator it=v1.begin( ); it!=v1.end( ); )
	{
		if(*it == 2)
		{
			//µ±É¾³ıµü´úÆ÷ËùÖ¸ÏòµÄÔªËØµÄÊ±ºò,eraseº¯Êı»áÈÃit×Ô¶¯ÒÆ¶¯µ½ÏÂ¸öÎ»ÖÃ
			//µ±É¾³ıÒ»¸öÔªËØµÄÊ±ºò£¬eraseº¯Êı·µ»Øµü´úÆ÷µÄÎ»ÖÃ(É¾³ıÔªËØµÄÏÂÒ»¸öÎ»ÖÃ)
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	printV(v1);
	cout<<endl;
	//ÈİÆ÷²åÈë²Ù×÷
	v1.insert(v1.begin( ),100);
	v1.insert(v1.end( ),200);
	printV(v1);
}

void test_vector6( )
{
	vector<int> v1;
    for (int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//·½·¨Ò»£ºÊ¹ÓÃclearº¯Êı Çå¿ÕÔªËØ ²»»ØÊÕ¿Õ¼ä
	cout<<endl;
	v1.clear( );
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//·½·¨¶ş£ºÊ¹ÓÃeraseº¯ÊıÑ­»·É¾³ı  µ²»»ØÊÕ¿Õ¼ä
	cout<<endl;
	for(vector<int>::iterator iter=v1.begin( ); iter!=v1.end( ); )
	{
		//µ±É¾³ıµü´úÆ÷ËùÖ¸ÏòµÄÔªËØµÄÊ±ºò,eraseº¯Êı»áÈÃit×Ô¶¯ÒÆ¶¯µ½ÏÂ¸öÎ»ÖÃ
		//µ±É¾³ıÒ»¸öÔªËØµÄÊ±ºò£¬eraseº¯Êı·µ»Øµü´úÆ÷µÄÎ»ÖÃ(É¾³ıÔªËØµÄÏÂÒ»¸öÎ»ÖÃ)
		iter = v1.erase(iter);
	}
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//µÚÈıÖÖ°ì·¨ ×î¼òµ¥µÄÊ¹ÓÃswap,Çå³ıÔªËØ²¢»ØÊÕÄÚ´æ
	cout<<endl;
	vector<int>( ).swap(v1);
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
}

void test_vector7( )
{
	vector<int*> v1;
	
    for (int i=0;i<10;i++)
    {
        v1.push_back(new int(i));
    }
	
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
	
	//vector::clear( )º¯ÊıµÄ×÷ÓÃÊÇÇå¿ÕÈİÆ÷ÖĞµÄÄÚÈİ£¬µ«Èç¹ûÊÇÖ¸Õë¶ÔÏóµÄ»°£¬²¢²»ÄÜÇå¿ÕÆäÄÚÈİ£¬
	//±ØĞëÒªÏñÒÔÏÂ·½·¨²ÅÄÜ´ïµ½Çå¿ÕÖ¸Õë¶ÔÏóµÄÄÚÈİ£º
	//1.freeÔªËØËùÖ¸ÏòµÄ¿Õ¼ä
	for(auto iter = v1.begin( ); iter != v1.end( ); iter++)
	{
		delete *iter;
	}
	
	//2.Çå³ıÔªËØ
	v1.clear( );
	cout<<"size="<<v1.size( )<<endl;
	cout<<"capacity="<<v1.capacity( )<<endl;
}

int main( )
{
	//test_vector1( );
	//test_vector2( );
	//test_vector3( );
	//test_vector4( );
	//test_vector5( );
	//test_vector6( );
	test_vector7( );
    return 0;
}