#ifndef DEVICE_H
#define DEVICE_H

#include "ErrorType.h"

class IObject
{
	virtual const int Initialize(void) = 0;
	virtual void Finalize(void) = 0;
	virtual const ErrorType Run(void) = 0;
};


#endif // !DEVICE_H


