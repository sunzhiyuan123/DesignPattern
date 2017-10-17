#pragma once
#include "IVideoStream.h"

class CamaroNet : public IVideoStream
{
private:

public:

protected:

public:
	CamaroNet(std::shared_ptr<IVideoStream> &vs, std::shared_ptr<ISource> &sourc);
	virtual ~CamaroNet( );
};

