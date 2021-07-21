// Blackjack.cpp 

#include <iostream>
#include <vector>

#include "Game.h"

const int MAX_N_PLAYERS = 6;

std::vector<std::string> vGetNamePlayers();

int main()
{
    bool isContinue = true;
    char answer;
    std::vector<std::string> vNames = vGetNamePlayers();
    isContinue = true;
    while (isContinue)
    {
        Game newGame(vNames);
        newGame.Play();
        std::cout << "Play again (enter 'Y')\nNew players (enter 'N')\nQuiet (enter 'Q') : ";
        std::cin >> answer;
        isContinue = (tolower(answer) == 'y' || tolower(answer) == 'n') ? true : false;
        system("cls");
        if (tolower(answer) == 'n')
        {
            newGame.~Game();
            vNames.clear();
            vNames = vGetNamePlayers();
        }
    }
    return 0;
}


std::vector<std::string> vGetNamePlayers()
{
    std::vector<std::string> names;
    int countPlayers = 0;
    bool isSetNames = true;
    char answer;
    while (isSetNames)
    {
        std::string name;
        std::cout << "Enter name for " << ++countPlayers << " player : ";
        std::cin >> name;
        names.push_back(name);
        if (countPlayers == MAX_N_PLAYERS)
        {
            system("cls");
            isSetNames = false;
        }
        else
        {
            std::cout << "Do you need another player?\nEnter 'Y' - Yes or 'N' - No : ";
            std::cin >> answer;
            isSetNames = (tolower(answer) == 'y') ? true : false;
            if (countPlayers < MAX_N_PLAYERS && !isSetNames)
                system("cls");
        }
    }
    return names;
}
