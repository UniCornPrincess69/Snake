#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "IObject.h"
#include "Player.h"

class CInputHandler : IObject
{
public:

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual void Finalize(void) override;
	virtual const ErrorType Run(void) override;

private:
	using Keycode = unsigned int;
	CPlayer* m_pPlayer = nullptr;

};

#endif // !INPUT_HANDLER_H
