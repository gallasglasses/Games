#pragma once
#include "House.h"
#include "Deck.h"
#include "Player.h"

class Game
{
private:
	
	Deck gameDeck;
	House gameHandHouse;
	std::vector<Player> vGamePlayers;
public:
	Game(std::vector<std::string>& vNamePlayers);
	void Play();
	~Game();
};

