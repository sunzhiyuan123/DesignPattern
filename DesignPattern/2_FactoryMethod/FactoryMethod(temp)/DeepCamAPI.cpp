#include "DeepCamAPI.h"
#include "IVideoStream.h"
#include "GenericVCDevice.h"
#include "CameraFactory.h"

template< >
std::shared_ptr<IVideoStream> DeepCamAPI::CreateCamera<IGenericVCDevicePtr>(Camera camera, IGenericVCDevicePtr & source)
{
	std::shared_ptr<IVideoStream> vs;
	switch (camera)
	{
		case Camera::StandardUVC:
		{
			break;
		}
		case Camera::CamaroNet:
		{
			vs = CameraFactory<CamaroNet>::CreateInstance(source);
			break;
		}
		default:
		{
			break;
		}
	}
	
	return vs;
}