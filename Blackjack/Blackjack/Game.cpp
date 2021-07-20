#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

//#include "Deck.h"

Game::Game(std::vector<std::string>& vNamePlayers)
{
	std::vector<std::string>::iterator it;
	for (it = vNamePlayers.begin(); it != vNamePlayers.end(); ++it)
	{
		vGamePlayers.push_back(Player(*it));
	}
	srand(static_cast<unsigned int>(time(0)));
	gameDeck.Populate();
	gameDeck.Shuffle();
}

void Game::Play()
{
	std::vector<Player>::iterator it;
	for (int i = 0; i < 2; ++i)
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
		{
			gameDeck.Deal(*it);
		}
		gameDeck.Deal(gameHandHouse);
	}
	gameHandHouse.FlipFirstCard();

	std::cout << gameHandHouse << std::endl;
	std::cout << std::setfill('*') << std::setw(20);
	std::cout << "\n";
	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}
	
	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
	{
		gameDeck.AdditionalCards(*it);
		system("cls");
		std::cout << gameHandHouse << std::endl;
		std::cout << std::setfill('*') << std::setw(20);
		std::cout << "\n";
		for (std::vector<Player>::iterator jt = vGamePlayers.begin(); jt != vGamePlayers.end(); ++jt)
		{
			std::cout << (*jt) << std::endl;
		}
		
	}
	gameHandHouse.FlipFirstCard();
	gameDeck.AdditionalCards(gameHandHouse);
	system("cls");

	std::cout << gameHandHouse << std::endl;
	std::cout << std::setfill('*') << std::setw(30);
	std::cout << "\n";
	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
	{
		std::cout << (*it) << std::endl;
	}

	int result = 0,
			count = 0,
			indexResult = 0;
	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
	{
		if (result == it->getTotal() && !(it->isBoosted()))
		{
			++count;
		}
		if (result < it->getTotal() && !(it->isBoosted()))
		{
			result = it->getTotal();
			count = 0;
			indexResult = std::distance(vGamePlayers.begin(), it);
		}
	}
		
	if (gameHandHouse.isBoosted() || gameHandHouse.getTotal() < result)
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
		{
			if (result == it->getTotal() && std::distance(vGamePlayers.begin(), it) != indexResult)
			{
				it->Push();
			}
			if (result > it->getTotal() && !(it->isBoosted()))
				it->Lose();
			if (count != 0 && std::distance(vGamePlayers.begin(), it) == indexResult && !(it->isBoosted()))
				vGamePlayers.at(indexResult).Push();
			else if (count == 0 && std::distance(vGamePlayers.begin(), it) == indexResult && !(it->isBoosted()))
				vGamePlayers.at(indexResult).Win();
		}
		std::cout << "\n\n";
	}
	else if (gameHandHouse.getTotal() > result)
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
		{
			if (!(it->isBoosted()))
				it->Lose();
		}
		std::cout << "Try again!\n\n";
	}
	else if (gameHandHouse.getTotal() == result)
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
		{
			if (result == it->getTotal() && !(it->isBoosted()))
			{
				it->Push();
			}
			if (result > it->getTotal() && !(it->isBoosted()))
				it->Lose();
		}
		std::cout << "\n\n";
	}
	
	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); ++it)
	{
		it -> Clear();
	}
	gameHandHouse.Clear();
}

Game::~Game()
{

}