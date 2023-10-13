#include "InputHandler.h"
#include <Windows.h>


const unsigned int M_I_LEFT = 37;
const unsigned int M_I_UP = 38;
const unsigned int M_I_RIGHT = 39;
const unsigned int M_I_DOWN = 40;
const unsigned int M_I_ESCAPE = 27;

const int CInputHandler::Initialize(void)
{
	m_iCurrent = M_I_UP;
	m_pPlayer->SetDirection(m_iCurrent);
	return 0;
}

void CInputHandler::Finalize(void)
{
	if (m_iCurrent != M_I_DEFAULT) m_iCurrent = M_I_DEFAULT;
}

const ErrorType CInputHandler::Run(void)
{
	ErrorType result = ErrorType::ET_SUCCESS;

	auto key = ReadKey();

	if (m_iCurrent != key && key != M_I_DEFAULT)
	{
		m_pPlayer->SetDirection(key);
		m_iCurrent = key;
	}
	m_pPlayer->Run();
	return result;
}

//Checking the status of the keys to check for input, needed for direction change.
//Vorlesung von Marcus Schaal
const unsigned int CInputHandler::ReadKey(void) const
{
	for (unsigned int i = M_I_BIT; i < M_I_BYTE; i++)
	{
		if (GetAsyncKeyState(i))
		{
			if (i >= M_I_LEFT && M_I_DOWN >= i || i == M_I_ESCAPE)
			{
				return i;
			}
			return 0;
		}
	}
}
