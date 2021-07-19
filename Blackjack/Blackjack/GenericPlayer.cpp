#include "GenericPlayer.h"

#include <iostream>
#include <string>

GenericPlayer::GenericPlayer(const std::string& pName)
	: playerName(pName)
{

}

bool GenericPlayer::isBoosted()
{
	return getValue() > 21 ? true : false;
}

void GenericPlayer::Bust() const
{
	std::cout << playerName << " busts with " << getValue() << " points!\n";
}

GenericPlayer::~GenericPlayer()
{

}