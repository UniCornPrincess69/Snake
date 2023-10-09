#include "Player.h"

const Vector2* CPlayer::GetPosition(void) const
{
    return m_pPlayerPos;
}

const std::vector<Vector2> CPlayer::GetSnakeBody(void) const
{
    return m_bodyParts;
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
    
    if (m_pPlayerPos->m_iX == m_pPickupPos->m_iX &&
        m_pPlayerPos->m_iY == m_pPickupPos->m_iY)
    {
        m_bodyParts.push_back(Vector2(0, 0));
    }
    
    return ErrorType();
}
