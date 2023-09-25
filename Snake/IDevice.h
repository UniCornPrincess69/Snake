#ifndef DEVICE_H
#define DEVICE_H

#include "ErrorType.h"

class IDevice
{
	virtual void Initialize(void) = 0;
	virtual void Finalize(void) = 0;
	virtual ErrorType Run(void) = 0;
};


#endif // !DEVICE_H


