#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <fstream>
#include <unistd.h>
#include <string.h>
using namespace std;  

static void test_io1( )
{
	char ch;	
	string name = "./file.txt";
	//����һ�������������ļ�����
	ofstream fout(name,ios::app);
	if(!fout)
	{
		cout<<"open error"<<endl;
		return;
	}
	fout<<"hello wrold 111"<<endl;
	fout<<"hello wrold 222"<<endl;
	fout<<"hello wrold 333"<<endl;
	fout.close( );
	
	//����һ��������������ļ�����
	ifstream fin(name);
	while(fin.get(ch))
	{
		cout<<ch;
	}
	fin.close( );
}

class Teacher
{
public:
	Teacher( )
	{
		age_ = 33;
		strcpy(name_,"");
	}
	Teacher(int age, char *name)
	{
		age_ = age;
		strcpy(name_,name);
	}
	void printT( )
	{
		cout<<"age:"<<age_<<" "<<"name:"<<name_<<endl;
	
	}
private:
	int age_;
	char name_[32];
};

//�������ļ�
static void test_io2( )
{
	string fname = "./file1.txt";
	//����һ�������������ļ�����
	ofstream fout(fname,ios::binary);
	if(!fout)
	{
		cout<<"open error"<<endl;
		return;
	}
	
	Teacher t1(31,(char *)"t31");
	Teacher t2(32,(char *)"t32");
	fout.write((char *)&t1,sizeof(t1));
	fout.write((char *)&t2,sizeof(t2));
	fout.close( );
	
	Teacher Temp;
	ifstream fin(fname);
	fin.read((char *)&Temp,sizeof(Temp));
	Temp.printT( );
	
	fin.read((char *)&Temp,sizeof(Temp));
	Temp.printT( );
	fin.close( );
}

int main( )
{
	//test_io1( );
	test_io2( );
	
    return 0;
}