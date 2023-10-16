#ifndef GAME_H
#define GAME_H

#include "IObject.h"

#include "GameBoard.h"
#include "InputHandler.h"
#include "Player.h"


class CGame : IObject
{
	
public:
	inline CGame(bool a_bIsGameStarted) : m_bIsRunning(a_bIsGameStarted)
	{}

private:
	void Introduction(void);
	bool CheckValue(int);
	void GameOver(void);

public:
	virtual const int Initialize(void) override;
	virtual void Finalize(void) override;
	virtual const ErrorType Run(void) override;

private:
	const int M_I_WIDTH = 0;
	const int M_I_HEIGHT = 0;
	const int M_I_MIN = 20;
	const int M_I_MAX = 40;

	bool m_bIsRunning = false;
	CPlayer* m_pPlayer = nullptr;
	CGameBoard* m_pGameBoard = nullptr;
	CInputHandler* m_pInputHandler = nullptr;
};


#endif // !GAME_H


