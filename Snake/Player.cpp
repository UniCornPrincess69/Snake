#include "Player.h"
/// <summary>
/// Get Vector2* of the player position
/// </summary>
/// <param name=""></param>
/// <returns></returns>
const Vector2* CPlayer::GetPosition(void) const
{
	return &m_bodyParts[0];
}

/// <summary>
/// Get the vector of the whole snakebody
/// </summary>
/// <param name=""></param>
/// <returns>List of body parts</returns>
const std::vector<Vector2> CPlayer::GetSnakeBody(void) const
{
	return m_bodyParts;
}

/// <summary>
/// Gets the bool if the pickup is present, or rather if the snake has eaten it.
/// </summary>
/// <param name=""></param>
/// <returns>bool if the pickup is still present</returns>
const bool CPlayer::GetHasPickup(void) const
{
	return m_bIsPickupPresent;
}

/// <summary>
/// Setting of the bool, if snake has eaten the pickup.
/// </summary>
/// <param name="a_bIsPickUpPresent">Bool to be set</param>
void CPlayer::SetHasPickup(const bool& a_bIsPickUpPresent)
{
	m_bIsPickupPresent = a_bIsPickUpPresent;
}

/// <summary>
/// Setting the direction in which the snake will move.
/// Control step so that the snake can't go back on itself.
/// </summary>
/// <param name="a_iKey">Direction to move in</param>
void CPlayer::SetDirection(const unsigned int& a_iKey)
{
	// This disables the players ability to walk backwards
	if (m_CurrentDirection == Direction::D_UP && (Direction)a_iKey == Direction::D_DOWN) return;
	if (m_CurrentDirection == Direction::D_DOWN && (Direction)a_iKey == Direction::D_UP) return;
	if (m_CurrentDirection == Direction::D_RIGHT && (Direction)a_iKey == Direction::D_LEFT) return;
	if (m_CurrentDirection == Direction::D_LEFT && (Direction)a_iKey == Direction::D_RIGHT) return;
	
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

	case static_cast<unsigned int>(Direction::D_NONE):
		exit(EXIT_SUCCESS);
		break;

	default:
		break;
	}
}

/// <summary>
/// Set position of the player
/// </summary>
/// <param name="a_pos">Position to be set</param>
void CPlayer::SetPosition(Vector2& a_pos)
{
	if (m_pPlayerPos == nullptr) return;
	m_pPlayerPos = &a_pos;
}

const int CPlayer::Initialize(void)
{
	m_bodyParts = std::vector<Vector2>();
	m_bodyParts.push_back(*m_pPlayerPos);
	return 0;
}


const ErrorType CPlayer::Run(void)
{

	//Magic numbers are simply the vectors of the direction
	switch (m_CurrentDirection)
	{
	case CPlayer::Direction::D_LEFT:
		UpdatePosition(-1, 0);
		break;

	case CPlayer::Direction::D_UP:
		UpdatePosition(0, -1);
		break;

	case CPlayer::Direction::D_RIGHT:
		UpdatePosition(1, 0);
		break;

	case CPlayer::Direction::D_DOWN:
		UpdatePosition(0, 1);
		break;

	case CPlayer::Direction::D_NONE:


	default:
		break;
	}
	return ErrorType();
}

/// <summary>
/// Update position of all the body parts of the snake and elongating the
/// snake on pickup
/// </summary>
/// <param name="a_iXDir">Direction along the X-axis, can be -1, 0, 1</param>
/// <param name="a_iYDir">Direction along the Y-axis, can be -1, 0, 1</param>
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

	if (m_pPickupPos == nullptr) return;

	if (m_bodyParts[0].m_iX == m_pPickupPos->m_iX &&
		m_bodyParts[0].m_iY == m_pPickupPos->m_iY) m_bIsPickupPresent = false;

	if (!m_bIsPickupPresent)
	{
		m_bodyParts.push_back(tempPos);
	}
}
