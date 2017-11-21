#pragma once
#include <vector>
#include "IVideoStream.h"

template<class T>
class ICameraFactory
{
	//1.��̬���� 
	//��һ�������������ʽ��ֵΪ��(true���߷���ֵ)����ôstatic_assert�����κ����飬
	//��������һ��������󣬴���λ�þ��Ǹ�static_assert��������У�������ʾ���ǵڶ���������ʾ�ַ�����\
	//2.is_base_of
	//ȷ��ģ�����T�Ǵ�IVideoStreamֱ�ӻ�����������

	static_assert(std::is_base_of<IVideoStream, T>::value, "Class T must derive from IVideoStream");
public:
	//template<class U>
	//static std::shared_ptr<IVideoStream> CreateInstance(U &device) = delete;
	~ICameraFactory( ) = default;
protected:
	ICameraFactory( ) = default;
	
};

