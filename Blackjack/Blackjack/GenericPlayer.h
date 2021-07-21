#pragma once
#include <iostream>
#include <string>

#include "Card.h"
#include "Hand.h"

class GenericPlayer : public Hand
{
protected:
	std::string playerName;

	friend std::ostream& operator<<(std::ostream& out, const GenericPlayer& player)
	{
		out << "Name : " << player.playerName << "\n";
		if (!player.vCardsOnHand.empty())
		{
			out << "Hand : ";
			for (std::vector<Card*>::const_iterator it = player.vCardsOnHand.begin(); it != player.vCardsOnHand.end(); ++it)
			{
				out << *(*it) << "   ";
			}
			out << "\nPoints : " << player.getTotal() << "\n";
			if (player.isBoosted())
				std::cout << player.playerName << " busts with " << player.getTotal() << " points!\n";
		}
		else
		{
			out << "No cards on hand.\n";
		}
		return out;
	}

public:
	GenericPlayer(const std::string& name = "");

	virtual bool isHitting() const = 0;
	bool isBoosted() const;

	virtual ~GenericPlayer();

};