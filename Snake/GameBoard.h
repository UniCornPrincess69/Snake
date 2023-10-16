#ifndef GAME_BOARD_H
#define GAME_BOARD_H

#include "ErrorType.h"
#include "Player.h"
#include "Vector2.h"
#include <vector>


class CGameBoard
{
	enum class TileType : char
	{
		TT_NONE , TT_GROUND, TT_WALL, TT_SNAKE, TT_PICKUP, TT_COUNT,
	};

public:
	inline CGameBoard(int a_iHeight, int a_iWidth, CPlayer* a_pPlayer)
		: m_iHeight(a_iHeight), m_iWidth(a_iWidth), m_pPlayer(a_pPlayer)
	{
		if (m_pPlayer == nullptr) return;
		InstantiateBoard();
	}

	void Initialize(void);
	ErrorType Draw(void);
	void SetSeed(unsigned int);
	const bool CheckGameOver(void) const;

private:
	void InstantiateBoard(void);
	void PlacePickup(void);
	const int RandomNumber(int);

private:
	int m_iHeight = 0;
	int m_iWidth = 0;
	unsigned int m_iSeed = 0;
	bool m_bIsPickupPresent = false;
	CPlayer* m_pPlayer = nullptr;
	Vector2* m_pPickupPos = nullptr;

	std::vector<std::vector<TileType>> m_tileMap = {};
	std::vector<Vector2> m_snakeBody = {};
};


#endif // !DISPLAY_H

