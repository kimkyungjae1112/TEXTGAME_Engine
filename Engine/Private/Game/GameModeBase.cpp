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
	GameMap->SetPlayerPosition(3, 2);
	
	SlatePopup = new Slate();
	SlatePopup->AddOption("앞으로 간다");
	SlatePopup->AddOption("왼쪽으로 돈다");
	SlatePopup->AddOption("상태 보기");
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
		if (Input == "게임시작")
		{
			bIsBeforeRun = false;
		}
		else if (Input == "게임종료")
		{
			exit(0);
		}
		else
		{
			DrawCenteredText("=== TEXT RPG GAME ===");
			DrawCenteredText("[MainMenu] : 게임시작, 상태, 공격, 게임종료");
			return;
		}
	}

	std::vector<std::string> Lines;

	auto MapLines = GameMap->GetMapLines();
	Lines.insert(Lines.end(), MapLines.begin(), MapLines.end());

	Lines.push_back("");

	auto PopupLines = SlatePopup->GetPopupLines();
	Lines.insert(Lines.end(), PopupLines.begin(), PopupLines.end());

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
	DrawCenteredText("[MainMenu] : 게임시작, 상태, 공격, 게임종료");

	int PaddingLines = Height - 2 - static_cast<int>(InnerLines.size());
	int TopPadding = PaddingLines / 2;
	int BottomPadding = PaddingLines - TopPadding;

	// 위쪽 공백
	for (int i = 0; i < TopPadding; ++i)
	{
		std::cout << "|" << std::string(Width - 2, ' ') << "|\n";
	}

	// 내용 출력
	for (const auto& line : InnerLines)
	{
		int pad = (Width - 2 - static_cast<int>(line.length())) / 2;
		if (pad < 0) pad = 0;
		std::cout << "|" << std::string(pad, ' ') << line
			<< std::string(Width - 2 - pad - line.length(), ' ') << "|\n";
	}

	// 아래쪽 공백
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


