#pragma once

#include <memory>
#include <type_traits>
#include "ICameraFactory.h"
#include "IVideoStream.h"
#include "CamaroNet.h"

template<class T>
class CameraFactory : public ICameraFactory<T>
{
public:
	template<class U>
	static std::shared_ptr<IVideoStream> CreateInstance(U &u);
private:
	CameraFactory( )  = default;
protected:
	~CameraFactory( ) = default;
};

template<class T>
template<class U>
inline std::shared_ptr<IVideoStream> CameraFactory<T>::CreateInstance(U& device)
{
	(void)device;
	throw std::invalid_argument("Unimplementation");
	//return{};
}

template <>
template <>
inline std::shared_ptr<IVideoStream> CameraFactory<CamaroNet>::CreateInstance<IGenericVCDevicePtr>(IGenericVCDevicePtr& device)
{

	//return std::make_shared<CamaroNet>(reader, device->GetSource());
}