#pragma once
#include <vector>
#include "IVideoStream.h"

template<class T>
class ICameraFactory
{
	//1.静态断言 
	//第一个参数常量表达式的值为真(true或者非零值)，那么static_assert不做任何事情，
	//否则会产生一条编译错误，错误位置就是该static_assert语句所在行，错误提示就是第二个参数提示字符串。\
	//2.is_base_of
	//确保模板参数T是从IVideoStream直接或间接派生而来

	static_assert(std::is_base_of<IVideoStream, T>::value, "Class T must derive from IVideoStream");
public:
	//template<class U>
	//static std::shared_ptr<IVideoStream> CreateInstance(U &device) = delete;
	~ICameraFactory( ) = default;
protected:
	ICameraFactory( ) = default;
	
};

