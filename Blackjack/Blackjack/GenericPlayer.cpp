#include "GenericPlayer.h"

GenericPlayer::GenericPlayer(const std::string& name)
	: playerName(name)
{

}

bool GenericPlayer::isBoosted() const
{
	return getTotal() > 21 ? true : false;
}


GenericPlayer::~GenericPlayer()
{

}