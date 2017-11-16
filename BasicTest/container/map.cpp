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

void test_map1( )
{
	map<int,string> map1;
	//����1
	map1.insert(pair<int,string>(1,"teacher1"));
	map1.insert(pair<int,string>(2,"teacher2"));
	//����2
	map1.insert(make_pair(3,"teacher3"));
	map1.insert(make_pair(4,"teacher4"));
	//����3
	map1.insert(map<int,string>::value_type(5,"teacher5"));
	map1.insert(map<int,string>::value_type(6,"teacher6"));
	//����4
	map1[7] = "teacher7";
	map1[8] = "teacher8";
	
	for(map<int,string>::iterator it=map1.begin( );it!=map1.end( );it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	cout<<" ";
	
	//set����ɾ��Ԫ��
	while(!map1.empty( ))
	{
		map<int,string>::iterator it = map1.begin( );
		cout<<it->first<<" "<<it->second<<endl;
		map1.erase(it);
	}
}

//ǰ���ַ��� ����ֵΪpair<iterator,bool> ��key�Ѿ������򱨴�
//������                                 ��key�Ѿ��������޸�
void test_map2( )
{
	map<int,string> map1;
	//����1
	pair<map<int,string>::iterator,bool> pair1 = map1.insert(pair<int,string>(1,"teacher1"));
	map1.insert(pair<int,string>(2,"teacher2"));
	//����2
	pair<map<int,string>::iterator,bool> pair3 = map1.insert(make_pair(3,"teacher3"));
	map1.insert(make_pair(4,"teacher4"));
	//����3
	pair<map<int,string>::iterator,bool> pair5 = map1.insert(pair<int,string>(5,"teacher5"));
	if(pair5.second != true)
	{
		cout<<"insert error"<<endl;
	}
	else
	{
		cout<<pair5.first->first<<" "<<pair5.first->second<<endl;
	}
	
	pair<map<int,string>::iterator,bool> pair6 = map1.insert(pair<int,string>(5,"teacher6"));
	if(pair6.second != true)
	{
		cout<<"insert error"<<endl;
	}
	else
	{
		cout<<pair6.first->first<<pair6.first->second<<endl;
	}
	//����4
	map1[7] = "teacher7";
	map1[7] = "teacher77";
	
	for(map<int,string>::iterator it=map1.begin( );it!=map1.end( );it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
}

void test_map3( )
{
	map<int,string> map1;
	//����1
	map1.insert(pair<int,string>(1,"teacher1"));
	map1.insert(pair<int,string>(2,"teacher2"));
	//����2
	map1.insert(make_pair(3,"teacher3"));
	map1.insert(make_pair(4,"teacher4"));
	//����3
	map1.insert(map<int,string>::value_type(5,"teacher5"));
	map1.insert(map<int,string>::value_type(6,"teacher6"));
	//����4
	map1[7] = "teacher7";
	map1[8] = "teacher8";
		
	for(map<int,string>::iterator it=map1.begin( );it!=map1.end( );it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}
	
	map<int,string>::iterator it2 = map1.find(100);
	if(it2 == map1.end( ))
	{
		cout<<"find error"<<endl;
	}
	else
	{
		cout<<it2->first<<"\t"<<it2->second<<endl;
	}
	
	pair<map<int,string>::iterator, map<int,string>::iterator> mypair = map1.equal_range(5);//�������������� �γ�һ��pair
	//��һ��������>=5��λ��
	//��һ��������=5��λ��
	if(mypair.first == map1.end( ))
	{
		cout<<"not find"<<endl;
	}
	else
	{
		cout<<mypair.first->first<<"\t"<<mypair.first->second<<endl;
	}
	
	if(mypair.second == map1.end( ))
	{
		cout<<"not find"<<endl;
	}
	else
	{
		cout<<mypair.second->first<<"\t"<<mypair.second->second<<endl;
	}
}

void test_map4( )
{
	map<int,string> map1;
	//����1
	map1.insert(pair<int,string>(1,"teacher1"));
	map1.insert(pair<int,string>(2,"teacher2"));
	//����2
	map1.insert(make_pair(3,"teacher3"));
	map1.insert(make_pair(4,"teacher4"));
	//����3
	map1.insert(map<int,string>::value_type(5,"teacher5"));
	map1.insert(map<int,string>::value_type(6,"teacher6"));
	
	int key = 1;
	
	map<int,string>::iterator iter;
	iter = map1.find(key);
	if (iter == map1.end( ))
	{
		map1.insert(make_pair(key, "teacher1"));
	}
	else
	{
		map1.erase(iter);
		map1.insert(make_pair(key, "teacher_1_new"));
	}
	
	//forѭ���������
	for(auto &it:map1)
	{
		cout<<it.first<<" "<<it.second<<endl;
	}
}

int main( )
{
	//test_map1( );
	//test_map2( );
	//test_map3( );
	test_map4( );
	
    return 0;
}