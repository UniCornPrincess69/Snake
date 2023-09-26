#include "GameBoard.h"

void CGameBoard::Initialize(void)
{
	auto xCoord = RandomNumber(m_iWidth);
	auto yCoord = RandomNumber(m_iHeight);

	if (m_pPickupPos == nullptr) m_pPickupPos = new Vector2(xCoord, yCoord);
	if (m_pPlayer != nullptr) m_pPlayer->SetPickupPos(m_pPickupPos);
	if (m_pPlayer != nullptr) m_snakeBody = m_pPlayer->GetSnakeBody();

	for (int x = 0; x < m_tileMap.size(); x++)
	{
		for (int y = 0; y < m_tileMap[x].size(); y++)
		{
			if (x == 0 || y == 0 ||
				x == m_tileMap.size() - 1 ||
				y == m_tileMap[x].size() - 1)
			{
				m_tileMap[x][y] = TileType::TT_WALL;
			}
			else if (m_snakeBody[x].m_iX == x && m_snakeBody[x].m_iY == y/*x == m_pPlayer->GetPosition()->m_iX &&
				y == m_pPlayer->GetPosition()->m_iY*/)
			{
				m_tileMap[x][y] = TileType::TT_SNAKE;
			}
			else if (x == m_pPickupPos->m_iX && 
				y == m_pPickupPos->m_iY)
			{
				m_tileMap[x][y] = TileType::TT_PICKUP;
			}
		}
	}
}

ErrorType CGameBoard::Draw(void)
{
	system("CLS");

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

const int CGameBoard::RandomNumber(int a_iPosCoord)
{
	return 1 + (rand() % (a_iPosCoord - 1));
}
