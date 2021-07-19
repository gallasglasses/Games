// Blackjack.cpp 

#include <iostream>
#include <vector>
#include "Game.h"

const size_t MAX_N_PLAYERS = 7;

std::vector<std::string> vGetNamePlayers();

int main()
{
    bool isContinue = true;
    char answer;
    std::vector<std::string> vNewNamePlayers = vGetNamePlayers();
    Game newGame(vNewNamePlayers);
    while (isContinue)
    {
        std::cout << "Do you want to play again?\nEnter 'Y' - Yes or 'N' - No : ";
        std::cin >> answer;
        isContinue = (tolower(answer) == 'y') ? true : false;
    }
    return 0;
}

std::vector<std::string> vGetNamePlayers()
{
    std::vector<std::string> vNames;
    size_t countPlayers = 0;
    bool isContinue = true;
    char answer;
    while (isContinue && countPlayers != MAX_N_PLAYERS)
    {
        std::string name;
        std::cout << "Enter name for " << countPlayers + 1 << " player : ";
        std::cin >> name;
        vNames.push_back(name);
        std::cout << "Do you need another player?\nEnter 'Y' - Yes or 'N' - No : ";
        std::cin >> answer;
        isContinue = (tolower(answer) == 'y') ? true : false;
    }
    return vNames;
}