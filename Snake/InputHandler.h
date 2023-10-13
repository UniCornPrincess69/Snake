#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "IObject.h"
#include "Player.h"

class CInputHandler : IObject
{

	
public:
	inline CInputHandler(CPlayer* a_pPlayer) : m_pPlayer(a_pPlayer)
	{}

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual void Finalize(void) override;
	virtual const ErrorType Run(void) override;

private:
	const unsigned int ReadKey(void) const;

private:
	using Keycode = unsigned int;
	CPlayer* m_pPlayer = nullptr;
	Keycode m_iCurrent = -1;
	const unsigned int M_I_DEFAULT = 0;
	const unsigned int M_I_BIT = 8;
	const unsigned int M_I_BYTE = 81;
	
};

#endif // !INPUT_HANDLER_H
