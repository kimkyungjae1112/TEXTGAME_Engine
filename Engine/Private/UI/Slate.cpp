#include "UI/Slate.h"
#include <iostream>
#include <Windows.h>

void Slate::AddOption(const std::string& OptionText)
{
	Options.push_back(OptionText);
}

void Slate::Clear()
{
    Options.clear();
}

void Slate::Draw() const
{
    int Width, Height;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    Width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    Height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    std::cout << "\n[ ¼±ÅÃÁö ]\n";
    for (size_t i = 0; i < Options.size(); ++i)
    {
        int pad = (Width - Options[i].length()) / 2;
        std::cout << std::string(pad, ' ') << i + 1 << ". " << Options[i] << "\n";
    }
}
