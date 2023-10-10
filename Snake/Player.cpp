#include "Player.h"

const Vector2* CPlayer::GetPosition(void) const
{
	return &m_bodyParts[0];
}

const std::vector<Vector2> CPlayer::GetSnakeBody(void) const
{
	return m_bodyParts;
}

const bool CPlayer::GetHasPickup(void) const
{
	return m_bIsPickupPresent;
}

void CPlayer::SetHasPickup(const bool& a_bIsPickUpPresent)
{
	m_bIsPickupPresent = a_bIsPickUpPresent;
}

void CPlayer::SetDirection(const unsigned int& a_iKey)
{
	switch (a_iKey)
	{
	case static_cast<unsigned int>(Direction::D_LEFT):
		m_CurrentDirection = Direction::D_LEFT;
		break;

	case static_cast<unsigned int>(Direction::D_UP):
		m_CurrentDirection = Direction::D_UP;
		break;

	case static_cast<unsigned int>(Direction::D_RIGHT):
		m_CurrentDirection = Direction::D_RIGHT;
		break;

	case static_cast<unsigned int>(Direction::D_DOWN):
		m_CurrentDirection = Direction::D_DOWN;
		break;

	default:
		break;
	}
}

void CPlayer::SetPosition(Vector2& a_pos)
{
	if (m_pPlayerPos == nullptr) return;
	m_pPlayerPos = &a_pos;
}

const int CPlayer::Initialize(void)
{
	m_bodyParts = std::vector<Vector2>();
	m_bodyParts.push_back(*m_pPlayerPos);
	if (m_pPickupPos == nullptr)
		return 0;
}

void CPlayer::Finalize(void)
{
	return void();
}

const ErrorType CPlayer::Run(void)
{
	//For the movement i need to loop backwards through my list to update the position from back
	//to front. The head moves according to the InputHandler.
	//For the pickup i need to do a -2 step, via bool. Because the snake gets longer, therefore a part doesn't move!

	//Magic numbers are simply the vectors of the direction
	switch (m_CurrentDirection)
	{
	case CPlayer::Direction::D_LEFT:
		UpdatePosition(-1, 0);
		//m_bodyParts[0].m_iX--;
		//m_pPlayerPos->m_iX--;
		break;

	case CPlayer::Direction::D_UP:
		UpdatePosition(0, -1);
		//m_bodyParts[0].m_iY--;
		//m_pPlayerPos->m_iY--;
		break;

	case CPlayer::Direction::D_RIGHT:
		UpdatePosition(1, 0);
		//m_bodyParts[0].m_iX++;
		//m_pPlayerPos->m_iX++;
		break;

	case CPlayer::Direction::D_DOWN:
		UpdatePosition(0, 1);
		//m_bodyParts[0].m_iY++;
		//m_pPlayerPos->m_iY++;
		break;

	case CPlayer::Direction::D_NONE:
		

	default:
		break;
	}



	return ErrorType();
}

void CPlayer::UpdatePosition(const int& a_iXDir, const int& a_iYDir)
{
	auto tempPos = Vector2(m_bodyParts[m_bodyParts.size() - 1]);

	for (int i = m_bodyParts.size() - 1; i > 0; i--)
	{
		m_bodyParts[i].m_iX = m_bodyParts[i - 1].m_iX;
		m_bodyParts[i].m_iY = m_bodyParts[i - 1].m_iY;
	}

	m_bodyParts[0].m_iX += a_iXDir; 
	m_bodyParts[0].m_iY += a_iYDir;

	if (m_bodyParts[0].m_iX == m_pPickupPos->m_iX &&
		m_bodyParts[0].m_iY == m_pPickupPos->m_iY) m_bIsPickupPresent = false;
	
	if (!m_bIsPickupPresent)
	{
		m_bodyParts.push_back(tempPos);
	}
}
