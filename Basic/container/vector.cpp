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
	//��β������Ԫ��
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	cout<<"length:"<<v1.size( )<<endl;
	
	//��ȡͷ��Ԫ��
	cout<<"ͷ��Ԫ��:"<<v1.front( )<<endl;
	
	//�޸�ͷ��Ԫ�� ��������ֵ����ֵ  Ӧ�÷���һ������
	v1.front( ) = 11;
	v1.back( )  = 55;
	
	while(v1.size( ) > 0)
	{
		//��ȡβ��Ԫ��
		cout<<"β��Ԫ��:"<<v1.back( )<<endl;
		//ɾ��β��Ԫ��
		v1.pop_back( );
	}
	cout<<"length:"<<v1.size( )<<endl;
}

//vector�ĳ�ʼ��
void test_vector2( )
{
	vector<int> v1;
	
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(5);
	v1.push_back(7);
	
	//�����ʼ��
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
	//��ǰ���ڴ�׼����
	vector<int> v1(10);
	//push_back������������Ԫ�ص�β�����Ԫ��
	v1.push_back(100);
	v1.push_back(200);
	
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	
	cout<<"length:"<<v1.size( )<<endl;
	
	printV(v1);
}

//1.�����������
//1       3     5   
//begin()          end( )
//�׵�ַ           �����ĺ���
//��it == v1.end( )��ʱ�� ˵����������Ѿ����������

//2.������������
//���������  �����������
void test_vector4( )
{
	vector<int> v1(10);
	for(int i=0;i<10;i++)
	{
		v1[i] = i;
	}
	//�����������
	for(vector<int>::iterator it = v1.begin( ); it != v1.end( ); it++)
	{
		cout<<*it<<endl;
	}
	
	//�����������
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
	//����ɾ��
	v1.erase(v1.begin( ),v1.begin( )+3);
	//����Ԫ�ص�λ��ɾ�� ָ��λ��ɾ��
	v1.erase(v1.begin( ));
	printV(v1);
	cout<<endl;
	//����Ԫ��ֵɾ��
	v1[0] = 2;
	v1[1] = 2;
	printV(v1);
	cout<<endl;
	for(vector<int>::iterator it=v1.begin( ); it!=v1.end( ); )
	{
		if(*it == 2)
		{
			//��ɾ����������ָ���Ԫ�ص�ʱ��,erase��������it�Զ��ƶ����¸�λ��
			//��ɾ��һ��Ԫ�ص�ʱ��erase�������ص�������λ��(ɾ��Ԫ�ص���һ��λ��)
			it = v1.erase(it);
		}
		else
		{
			it++;
		}
	}
	printV(v1);
	cout<<endl;
	//�����������
	v1.insert(v1.begin( ),100);
	v1.insert(v1.end( ),200);
	printV(v1);
}

int main( )
{
	//test_vector1( );
	//test_vector2( );
	//test_vector3( );
	//test_vector4( );
	test_vector5( );
	
    return 0;
}