#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <string.h>
using namespace std;  

class Teacher
{
public:
	Teacher(char *name ,int age)
	{
		m_name = new char[strlen(name)+1];
		strcpy(m_name,name);
		m_age = age;
	}
	~Teacher( )
	{
		if(m_name != NULL)
		{
			delete[ ] m_name;
			m_name = NULL;
			m_age  = 0;
		}
	}
	Teacher(const Teacher &obj)
	{
		m_name = new char[strlen(obj.m_name)+1];
		strcpy(m_name, obj.m_name);
		m_age = obj.m_age;
	}
	//���صȺŲ�����
	Teacher& operator=(const Teacher &obj)
	{
		//�Ȱ�t2�ľ��ڴ��ͷŵ�
		//����t1�Ĵ�С�����ڴ�
		//copy t1������
		if(m_name != NULL)
		{
			delete[ ] m_name;
			m_name = NULL;
			m_age  = 0;
		}
		m_name = new char[strlen(obj.m_name)+1];
		strcpy(m_name, obj.m_name);
		m_age = obj.m_age;
		
		return *this;
	}
	
	void printT( )
	{
		cout<<m_name<<" "<<m_age<<endl;
	}
private:
	char  *m_name;
	int   m_age;
};

void test_conrainer_comm1( )
{
	Teacher t1("t1",31);
	t1.printT( );
	
	vector<Teacher> v1;
	//��t1������һ�ݣ���ŵ�������
	v1.push_back(t1);
}

int main( )
{
	test_conrainer_comm1( );
	
    return 0;
}