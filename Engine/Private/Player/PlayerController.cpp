#include "Player/PlayerController.h"
#include <iostream>

bool PlayerController::HandleInput(std::string& Input)
{
    std::cout << ">> ";
    std::getline(std::cin, Input);

    if (Input == "quit") return false;

    std::cout << "[�Է� ó����]: " << Input << "\n";
    return true;
}
