#pragma once
#include <memory>
#include <string>

class ISource
{
public:
	virtual ~ISource( ) = default;
};

class IGenericVCDevice
{
public:
	virtual std::string GetSymbolicLink( ) = 0;
	virtual std::string GetFriendlyName( ) = 0;
	virtual std::string GetDeviceInfo( )   = 0;
	virtual std::shared_ptr<ISource> &GetSource( ) = 0;
	virtual ~IGenericVCDevice( ) = default;
};

typedef std::shared_ptr<IGenericVCDevice> IGenericVCDevicePtr;
