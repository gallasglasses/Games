#include "Game.h"
#include <iostream>
#include <vector>
//#include "Deck.h"

Game::Game(std::vector<std::string>& vNamePlayers)
{
	std::vector<std::string>::iterator it;
	for (it = vNamePlayers.begin(); it != vNamePlayers.end(); it++)
	{
		std::cout << "Enter player name : ";
		vGamePlayers.push_back(Player(*it));
	}
	gameDeck.Populate();
	gameDeck.Shuffle();
}

void Game::Play()
{
	std::vector<Player>::iterator it;
	for (size_t i = 0; i < 2; i++)
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); it++)
		{
			gameDeck.Deal(*it);
		}
		gameDeck.Deal(gameHandHouse);
	}
	gameHandHouse.FlipFirstCard();

	if (gameHandHouse.isHitting())
		gameDeck.Deal(gameHandHouse);

	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << gameHandHouse;
	if (!gameHandHouse.isBoosted())
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); it++)
		{
			it->isBoosted() ? it->Lose() : it->Win();
		}
	}
	else
	{
		for (it = vGamePlayers.begin(); it != vGamePlayers.end(); it++)
		{
			!(it->isBoosted()) ? ((it->getValue() > gameHandHouse.getValue()) ? it->Win() : ((it->getValue() == gameHandHouse.getValue()) ? it->Push() : it->Lose())) : it->Lose();
		}
	}

	for (it = vGamePlayers.begin(); it != vGamePlayers.end(); it++)
	{
		it -> Clear();
	}
	gameHandHouse.Clear();
}