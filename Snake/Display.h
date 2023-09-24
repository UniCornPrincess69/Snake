#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ErrorType.h"

class CGameBoard
{
	enum class TileType : char 
	{
		TT_GROUND, TT_WALL, TT_PLAYER, TT_PICKUP
	};

	inline CGameBoard(int a_iHeight, int a_iWidth) 
		: m_iHeight(a_iHeight), m_iWidth(a_iWidth)
	{}

public:
	void Initialize(void);
	ErrorType Draw(void);

private:
	int m_iHeight;
	int m_iWidth;
};


#endif // !DISPLAY_H

