#include "House.h"

House::House(const std::string& pName)
	: GenericPlayer("House")
{

}

bool House::isHitting() const
{
	return getValue() < 17 ? true : false;
}

void House::FlipFirstCard()
{
	if (vCardsOnHand.empty())
		vCardsOnHand[0]->FlipCard();
}