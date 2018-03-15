#include <iostream>  
#include <memory> // shared_ptr  
#include <thread>  
#include <chrono>  
#include <mutex>
#include <vector>
#include <string>
#include <unistd.h>
using namespace std;

void test_unique_ptr1( )
{
    unique_ptr<int> up1(new int(10)); // ���ܸ��Ƶ�unique_ptr
	if(nullptr != up1)
	{
		cout<<"up1:"<<*up1<<endl;
	}
    //unique_ptr<int> up2 = up1;      // Error unique_ptrû�и��ƹ��캯��
	
	//�����Ҫ������Ȩ����ת�ƣ���������������
    unique_ptr<int> up3 = move(up1);  //����up3������Ψһ��unique_ptr����ָ��
	if(nullptr != up3)
	{
		//move����֮�� Դָ���Ϊnullptr
		if(nullptr == up1)
		{
			cout<<"up1 nullptr"<<endl;
		}
		
		cout<<"up3:"<<*up3<<endl;
	}
	
	unique_ptr<int> up4 = move(up1);  //move����û�б��� ����up4��nullptr
	if(nullptr != up4)
	{
		cout<<"up4:"<<*up4<<endl;
	}
		
    //cout<<*up1<<endl;               // ����ʱ����

    up3.reset( );        // ��ʾ�ͷ��ڴ�
	if(nullptr == up3)
	{
		cout<<"up3 nullptr"<<endl;
	}
	
    up1.reset( );        // ��ʹup1û��ӵ���κ��ڴ棬������������Ҳû������
    // cout<<*up3<<endl; // �Ѿ��ͷŵ�up3�ˣ�����������ʱ����
}

void test_unique_ptr2( )
{
    shared_ptr<int> sp1(new int(20));
    shared_ptr<int> sp2 = sp1; // ������ȫ���Եģ��������ü���
	
    cout<<*sp1<<endl;
    cout<<*sp2<<endl;
	
	cout<<"sp1 use_count:"<<sp1.use_count( )<<endl;
	cout<<"sp2 use_count:"<<sp2.use_count( )<<endl;
	
    sp1.reset( ); // �������ü���
	if(nullptr == sp1)
	{
		cout<<"sp1 nullptr"<<endl;
	}
	
	cout<<"sp1 use_count:"<<sp1.use_count( )<<endl;
	cout<<"sp2 use_count:"<<sp2.use_count( )<<endl;
	
    cout<<*sp2<<endl;
}

unique_ptr<int> Func(unique_ptr<int> a)
{         
    cout<<*a<<endl;
    return a;
}         


//������unique_ptr����û�и��ƹ��캯���ģ�������ֱ�Ӵ���ʱ������ֵ����ʱ��������ʱ����ʱ���ͻ�����ˣ�
//������Ҫ��ʾ�ĵ���move��ת������Ȩ���������ķ���ֵ�Ѿ�������move��������������ʾ�Ľ��е��á�
void test_unique_ptr3( )
{
    unique_ptr<int> up1(new int(10));
	
    up1 = Func(move(up1));
    cout<<*up1<<endl;
}

//test error
void test_unique_ptr4( )
{
    //��Ҫ��get������ȡԭ��ָ��֮�󣬶�����ָ����и�ֵ��
	//��Ϊ��get������ȡ����ԭ��ָ��û������ָ�����Ϣ����������ָ���޷����й������
	unique_ptr<int> up1(new int(10));
	cout<<*up1<<endl;
	unique_ptr<int> up0(up1.get( ));
}

int main( )
{
	test_unique_ptr1( );
	//test_unique_ptr2( );
	//test_unique_ptr3( );
	//test_unique_ptr4( );
	
    return 0;
}