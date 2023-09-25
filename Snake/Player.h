#ifndef PLAYER_H
#define PLAYER_H

#include "IDevice.h"


enum class BodyPart
{
	BP_HEAD, BP_TAIL,
};


class CPlayer : IDevice
{
public:
	inline CPlayer(int a_iX, int a_iY) 
		: M_I_SPAWN_POSX(a_iX), M_I_SPAWN_POSY(a_iY)
	{

	}

private:
	const int M_I_SPAWN_POSX = 0;
	const int M_I_SPAWN_POSY = 0;

public:
	// Inherited via IDevice
	virtual void Initialize(void) override;
	virtual void Finalize(void) override;
	virtual ErrorType Run(void) override;

};

#endif // !PLAYER_H


