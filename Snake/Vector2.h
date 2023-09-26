#ifndef VECTOR_2_H
#define VECTOR_2_H

struct Vector2
{
	inline Vector2(int a_iX, int a_iY) : m_iX(a_iX), m_iY(a_iY)
	{}

	int m_iX = 0;
	int m_iY = 0;
};

#endif // !VECTOR_2_H

