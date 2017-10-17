#pragma once
#include <memory>
#include <vector>
#include "IVideoStream.h"

enum class Camera
{
	StandardUVC,
	Camaro,
	CamaroISP,
	CamaroMovidius,
	CamaroDual,
	ImpalaE,
	Fovea,
	CamaroNet,
};

class DeepCamAPI
{
public:
	//static DeepCamAPI &Instance( );
	//std::vector<IGenericVCDevicePtr> EnumerateDevices(DeviceCategory type);
	
	template<class U>
	std::shared_ptr<IVideoStream> CreateCamera(Camera camera, U & source);
	
	//void SetLogLevel(Level level) const;
	//void EnableLog(uint8_t flag) const;
	//void WriteLog(Level level, const std::string &text) const;
	
	//template<class T>
	//static std::shared_ptr<T> QueryInterface(std::shared_ptr<IVideoStream> &vs);
	
	~DeepCamAPI( );
private:
	DeepCamAPI( );
	DeepCamAPI(DeepCamAPI &) = delete;
};