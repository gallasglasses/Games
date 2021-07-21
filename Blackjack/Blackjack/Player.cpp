
#include "Player.h"

Player::Player(const std::string& name)
	: GenericPlayer(name)
{
	
}

bool Player::isHitting() const
{
	char answer;
	std::cout << "Player " << playerName << ", do you need another card?\nEnter 'Y' - Yes or 'N' - No : ";
	std::cin >> answer;
	std::cout << "\n";
	return (tolower(answer) == 'y') ? true : false;
}

void Player::Win() const
{
	std::cout << "Player " << playerName << "! Winner winner chicken dinner! Congrats!\n";
}

void Player::Lose() const
{
	std::cout << "Player " << playerName << " loses.\n";
}

void Player::Push() const
{
	std::cout << "Player " << playerName << " pushs.\n";
}

Player::~Player()
{

}