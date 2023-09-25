// Snake.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
#include "ErrorType.h"

CGame* m_pGame = nullptr;
bool m_bGameStarted = true;

int main()
{
	auto result = ErrorType::ET_SUCCESS;
	
	//Initialize
	if (m_pGame == nullptr) m_pGame = new CGame(m_bGameStarted);
	else result = ErrorType::ET_PTR_NOT_INSTANTIATED;
	if (result != ErrorType::ET_SUCCESS) return static_cast<int>(result);

	//Run
	m_pGame->Initialize();
	m_pGame->Run();
	m_pGame->Finalize();

	//Finalize
	if (m_pGame != nullptr)
	{
		delete m_pGame;
		m_pGame = nullptr;
	}


	return static_cast<int>(result);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
