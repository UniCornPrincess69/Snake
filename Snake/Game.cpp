#include "Game.h"
#include <iostream>

const int CGame::Initialize(void)
{
	Introduction();
	if (m_pGameBoard != nullptr) m_pGameBoard->Initialize();
	if (m_pPlayer != nullptr) m_pPlayer->Initialize();
	if (m_pInputHandler != nullptr) m_pInputHandler->Initialize();

	return 0;
}

void CGame::Finalize(void)
{ 
	if (m_pInputHandler != nullptr)
	{
		delete m_pInputHandler;
		m_pInputHandler = nullptr;
	}

	if (m_pPlayer != nullptr)
	{
		delete m_pPlayer;
		m_pPlayer = nullptr;
	}

	if (m_pGameBoard != nullptr)
	{
		delete m_pGameBoard;
		m_pGameBoard = nullptr;
	}
}

const ErrorType CGame::Run(void)
{
	auto result = static_cast<ErrorType>(ErrorType::ET_SUCCESS);
	while (m_bIsRunning)
	{
		m_pInputHandler->Run();
		m_pGameBoard->Draw();
	}
	return result;
}

void CGame::Introduction(void)
{
	auto iInputHeight = static_cast<int>(0);
	auto iInputWidth = static_cast<int>(0);
	std::cout << "Welcome to Snake!!!" << std::endl;
	while (true)
	{
		std::cout << "Please input the Height of the Board" << std::endl;
		std::cin >> iInputHeight;
		if (CheckValue(iInputHeight))
		{
			system("CLS");
			std::cout << "Invalid value. Please try again!" << std::endl;
		}
		else break;
	}
	system("CLS");
	while (true)
	{
		std::cout << "Now please input the Width of the Board" << std::endl;
		std::cin >> iInputWidth;
		if (CheckValue(iInputWidth))
		{
			system("CLS");
			std::cout << "Invalid value. Please try again!" << std::endl;
		}
		else break;
	}
	system("CLS");
	if (m_pPlayer == nullptr) m_pPlayer = new CPlayer(iInputWidth / 2, iInputHeight / 2);
	if (m_pGameBoard == nullptr) m_pGameBoard = new CGameBoard(iInputHeight, iInputWidth, m_pPlayer);
}

bool CGame::CheckValue(int val)
{
	return (val < M_I_MIN || val > M_I_MAX);
}
