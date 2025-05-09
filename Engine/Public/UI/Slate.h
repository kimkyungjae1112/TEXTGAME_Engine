#ifndef __SLATE_H__
#define __SLATE_H__

#include <vector>
#include <string>

class Slate
{
public:
    void AddOption(const std::string& OptionText);
    void Clear();

    std::vector<std::string> GetPopupLines() const;

private:
    std::vector<std::string> Options;
};

#endif // !__SLATE_H__
