#include "House.h"

House::House(const std::string& name)
	: GenericPlayer(name)
{

}

bool House::isHitting() const
{
	return getTotal() < 17 ? true : false;
}

void House::FlipFirstCard()
{
	if (!vCardsOnHand.empty())
		vCardsOnHand[0]->FlipCard();
}

House::~House()
{

}