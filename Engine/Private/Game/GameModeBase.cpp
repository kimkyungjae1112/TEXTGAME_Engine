#include "Game/GameModeBase.h"
#include "World/World.h"
#include "World/Map.h"
#include "UI/Slate.h"
#include <iostream>
#include <Windows.h>

GameModeBase::GameModeBase(World* InWorld) : GameWorld(InWorld)
{
	bIsBeforeRun = true;
	GameMap = new Map(10, 5);
	SlatePopup = new Slate();
	GameMap->SetPlayerPosition(3, 2);
}

GameModeBase::~GameModeBase() = default;

void GameModeBase::OnTurn()
{
	GameWorld->OnTurn();
}

void GameModeBase::Render(std::string Input)
{
	if (bIsBeforeRun)
	{
		if (Input == "���ӽ���")
		{
			bIsBeforeRun = false;
		}
		else if (Input == "��������")
		{
			exit(0);
		}
		else
		{
			DrawCenteredText("=== TEXT RPG GAME ===");
			DrawCenteredText("[MainMenu] : ���ӽ���, ����, ����, ��������");
			return;
		}
	}

	std::vector<std::string> Lines;

	// �̴ϸ� �߰�
	Lines.push_back("[ �̴ϸ� ]");
	for (int y = 0; y < 5; ++y)
	{
		std::string row;
		for (int x = 0; x < 10; ++x)
		{
			if (x == 3 && y == 2) row += "@ ";
			else row += ". ";
		}
		Lines.push_back(row);
	}

	Lines.push_back(""); 
	Lines.push_back("[ ������ ]");
	Lines.push_back("1. ������ ����");
	Lines.push_back("2. �������� ����");
	Lines.push_back("3. ���� ����");

	DrawConsoleBox(Lines);
}

void GameModeBase::GetConsoleSize(int& Width, int& Height)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

void GameModeBase::DrawConsoleBox(const std::vector<std::string>& InnerLines)
{
	int Width, Height;
	GetConsoleSize(Width, Height);

	std::string Border(Width, '=');
	system("cls");

	std::cout << Border << "\n";
	DrawCenteredText("=== TEXT RPG GAME ===");
	DrawCenteredText("[MainMenu] : ���ӽ���, ����, ����, ��������");

	int PaddingLines = Height - 2 - static_cast<int>(InnerLines.size());
	int TopPadding = PaddingLines / 2;
	int BottomPadding = PaddingLines - TopPadding;

	// ���� ����
	for (int i = 0; i < TopPadding; ++i)
	{
		std::cout << "|" << std::string(Width - 2, ' ') << "|\n";
	}

	// ���� ���
	for (const auto& line : InnerLines)
	{
		int pad = (Width - 2 - static_cast<int>(line.length())) / 2;
		if (pad < 0) pad = 0;
		std::cout << "|" << std::string(pad, ' ') << line
			<< std::string(Width - 2 - pad - line.length(), ' ') << "|\n";
	}

	// �Ʒ��� ����
	for (int i = 0; i < BottomPadding; ++i)
	{
		std::cout << "|" << std::string(Width - 2, ' ') << "|\n";
	}

	std::cout << Border << "\n";
}

void GameModeBase::DrawCenteredText(const std::string& Text)
{
	int Width, Height;
	GetConsoleSize(Width, Height);

	int Padding = (Width - static_cast<int>(Text.length())) / 2;
	if (Padding < 0) Padding = 0;


	std::cout << "|" << std::string(Padding - 1, ' ') << Text << std::string(Padding, ' ') << "|" << "\n";
}


