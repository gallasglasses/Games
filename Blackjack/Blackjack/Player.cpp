#include "Player.h"

Player::Player(const std::string& pName)
	: GenericPlayer(pName)
{

}

bool Player::isHitting() const
{
	char answer;
	std::cout << playerName << ", do you need another card?\nEnter 'Y' - Yes or 'N' - No : ";
	std::cin >> answer;
	return (tolower(answer) == 'y') ? true : false;
}

void Player::Win() const
{
	std::cout << playerName << " wins! Congrats!\n";
}

void Player::Lose() const
{
	std::cout << playerName << " loses.\n";
}

void Player::Push() const
{
	std::cout << playerName << " pushs.\n";
}