#include "Game.h"
#include "Utils.h"
#include <Windows.h>
#include <iostream>

const int CGame::Initialize(void)
{
	Introduction();
	if (m_pPlayer != nullptr) m_pPlayer->Initialize();
	if (m_pGameBoard != nullptr) m_pGameBoard->Initialize();
	if (m_pInputHandler == nullptr) m_pInputHandler = new CInputHandler(m_pPlayer);
	if (m_pInputHandler != nullptr) m_pInputHandler->Initialize();

	return 0;
}

void CGame::Finalize(void)
{
	DeletePointer(m_pInputHandler);
	DeletePointer(m_pPlayer);
	DeletePointer(m_pGameBoard);
}

const ErrorType CGame::Run(void)
{
	auto result = static_cast<ErrorType>(ErrorType::ET_SUCCESS);
	m_pGameBoard->Draw();
	while (m_bIsRunning)
	{
		m_pInputHandler->Run();
		m_pGameBoard->Draw();
		if (m_pGameBoard->CheckGameOver())
		{
			GameOver();
		}
		Sleep(500);
	}
	return result;
}

//Introduction text for the game
//User input for the size of the gameboard is asked
void CGame::Introduction(void)
{
	auto iInputHeight = static_cast<int>(0);
	auto iInputWidth = static_cast<int>(0);
	std::cout << "Welcome to Snake!!!" << std::endl;
	std::cout << "Please use the arrow keys for control!" << std::endl;
	std::cout << "If you want to end the game just press escape." << std::endl;
	std::cout << "Press Enter to continue" << std::endl;
	std::cin.ignore();
	system("CLS");
	while (true)
	{
		std::cout << "Please input the Height of the Board(20 - 40)" << std::endl;
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
		std::cout << "Now please input the Width of the Board(20 - 40)" << std::endl;
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

	auto iSeedInput = static_cast<unsigned int>(0);
	while (true)
	{
		std::cout << "At last please insert a number between 0 and 100!" << std::endl;
		std::cout << "This is for game magic in the background ;P" << std::endl;
		std::cin >> iSeedInput;
		if (0 > iSeedInput || iSeedInput > 100)
		{
			system("CLS");
			std::cout << "Invalid value. Please try again!" << std::endl;
		}
		else break;
	}
	m_pGameBoard->SetSeed(iSeedInput);
}

bool CGame::CheckValue(int val)
{
	return (val < M_I_MIN || val > M_I_MAX);
}

void CGame::GameOver(void)
{
	system("CLS");
	while (true)
	{
		std::cout << "Unfortunately you lost the game!!!" << std::endl;
		std::cout << "Press enter to end the game!" << std::endl;
		std::cin.ignore();
		exit(EXIT_SUCCESS);
	}
}

