#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "IDevice.h"

class CInputHandler : IDevice
{
	// Inherited via IDevice
public:
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual ErrorType Run(void) override;
};

#endif // !INPUT_HANDLER_H
