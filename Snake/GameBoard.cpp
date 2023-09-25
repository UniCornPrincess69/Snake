#include "GameBoard.h"

void CGameBoard::Initialize(void)
{
}

ErrorType CGameBoard::Draw(void)
{
	return ErrorType();
}

void CGameBoard::InstantiateBoard(void)
{
	m_tileMap = std::vector<std::vector<TileType>>();

	for (int x = 0; x <= m_iWidth; x++)
	{
		m_tileMap.push_back(std::vector<TileType>());
		for (int y = 0; y <= m_iHeight; y++)
		{
			m_tileMap[x].push_back(TileType::TT_NONE);
		}
	}
}

void CGameBoard::PlacePickup(void)
{
}
