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

static void test_set1( )
{
	set<int> set1;
	for(int i=0;i<5;i++)
	{
		int tmp = rand( );
		set1.insert(tmp);
	}
	//���� Ԫ��Ψһ �Զ�����Ĭ��������Ǵ�С��������
	//���ܰ���[]��ʽ����Ԫ��
	set1.insert(100);
	set1.insert(100);
	set1.insert(100);
	
	for(set<int>::iterator it=set1.begin( );it!=set1.end( );it++)
	{
		cout<<*it<<endl;
	}
	//ɾ������
	while(!set1.empty( ))
	{
		set<int>::iterator it=set1.begin( );
		cout<<*it<<endl;
		set1.erase(set1.begin( ));
	}
	cout<<"size"<<set1.size( )<<endl;
}

static void test_set2( )
{
	//Ĭ�ϴ�С����
	set<int>              set1;
	//��С����
	set<int,less<int>>    set2;
	//�Ӵ�С
	set<int,greater<int>> set3;
	
	for(int i=0;i<5;i++)
	{
		int tmp = rand( );
		set3.insert(tmp);
	}
	for(set<int,greater<int>>::iterator it=set3.begin( );it!=set3.end( );it++)
	{
		cout<<*it<<endl;
	}
}

class Student
{
public:
	Student(char *name, int age)
	{
		strcpy(this->name, name);
		this->age = age;
	}
	char name[64];
	int  age;
};

//���ڸ��ӵ��������� Teacher Student
//�º���
struct FuncStudent
{
	//�����˺������ò�����
	bool operator( )(const Student &left,const Student &right)
	{
		if(left.age < right.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

//�º������÷�
static void test_set3( )
{
	set<Student, FuncStudent> set1;
	Student s1((char *)"s1",44);
	Student s2((char *)"s2",32);
	Student s3((char *)"s3",33);
	Student s4((char *)"s4",33);//�������33�� ֻ����ɹ��˵�һ��
	
	//�����ж�inset�Ƿ����ɹ�
	set1.insert(s1);
	set1.insert(s2);
	set1.insert(s3);
	set1.insert(s4);
	
	for(set<Student>::iterator it=set1.begin( );it!=set1.end( );it++)
	{
		cout<<"age="<<it->age<<" name"<<it->name<<endl;
	}
}

//
static void test_set4( )
{
	set<Student, FuncStudent> set1;
	Student s1((char *)"s1",44);
	Student s2((char *)"s2",32);
	Student s3((char *)"s3",33);
	Student s4((char *)"s4",33);//�������33�� ֻ����ɹ��˵�һ��
	
	//�����ж�inset�Ƿ����ɹ�
	pair<set<Student, FuncStudent>::iterator,bool> pair1 = set1.insert(s3);
	if(pair1.second == true)
	{
		cout<<"insert success"<<endl;
	}
	else
	{
		cout<<"insert error"<<endl;
	}
	
	pair<set<Student, FuncStudent>::iterator,bool> pair2 = set1.insert(s4);
	if(pair2.second == true)
	{
		cout<<"insert success"<<endl;
	}
	else
	{
		cout<<"insert error"<<endl;
	}
	
	for(set<Student>::iterator it=set1.begin( );it!=set1.end( );it++)
	{
		cout<<"age="<<it->age<<" name"<<it->name<<endl;
	}
}

static void test_set5( )
{
	set<int>  set1;
	
	for(int i=0;i<10;i++)
	{
		set1.insert(i+1);
	}
	
	for(set<int>::iterator it=set1.begin( );it!=set1.end( );it++)
	{
		cout<<*it<<endl;
	}
	
	set<int>::iterator it0 = set1.find(5);
	cout<<"it0:"<<*it0<<endl;
	
	int num = set1.count(5);
	cout<<"num:"<<num<<endl;
}

int main( )
{
	//test_set1( );
	//test_set2( );
	//test_set3( );
	//test_set4( );
	test_set5( );
    return 0;
}