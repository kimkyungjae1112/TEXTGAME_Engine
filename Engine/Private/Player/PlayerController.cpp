#include "Player/PlayerController.h"
#include <iostream>

bool PlayerController::HandleInput()
{
    std::cout << ">> ";
    std::string command;
    std::getline(std::cin, command);

    if (command == "quit") return false;

    std::cout << "[�Է� ó����]: " << command << "\n";
    return true;
}
