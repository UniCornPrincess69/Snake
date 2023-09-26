#ifndef PLAYER_H
#define PLAYER_H

#include "IObject.h"
#include "Vector2.h"
#include <iostream>
#include <vector>


class CPlayer : IObject
{
public:
	inline CPlayer(int a_iX, int a_iY) : m_pPlayerPos(new Vector2(a_iX, a_iY))
	{}

public:
	const Vector2* GetPosition(void) const;
	const std::vector<Vector2> GetSnakeBody(void) const;
	void SetPosition(Vector2&);
	inline void SetPickupPos(const Vector2* a_pPickupPos) { m_pPickupPos = const_cast<Vector2*>(a_pPickupPos); };

	// Inherited via IObject
	virtual const int Initialize(void) override;
	virtual void Finalize(void) override;
	virtual const ErrorType Run(void) override;

private:
	Vector2* m_pPlayerPos = nullptr;
	Vector2* m_pPickupPos = nullptr;
	std::vector<Vector2> m_bodyParts = {};
};

#endif // !PLAYER_H


