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

std::vector<std::string> Slate::GetPopupLines() const
{
    std::vector<std::string> Result;
    Result.push_back("[ º±≈√¡ˆ ]");
    for (size_t i = 0; i < Options.size(); ++i)
    {
        Result.push_back(std::to_string(i + 1) + ". " + Options[i]);
    }
    return Result;
}
