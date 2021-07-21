#include "Hand.h"

Hand::Hand()
{
	vCardsOnHand.reserve(MAX_N_CARD);
}

int Hand::getTotal() const
{
	if (vCardsOnHand.empty())
		return 0;
	int total = 0;
	std::vector<Card*>::const_iterator it;
	for (it = vCardsOnHand.begin(); it != vCardsOnHand.end(); ++it)
	{
		total += (*it)->getValue();
		if ((*it)->getValue() == Card::ACE && total <= 11)
		{
			total += 10;
		}
	}
	return total;
}

void Hand::Add(Card* card)
{
	vCardsOnHand.push_back(card);
}

void Hand::Clear()
{
	std::vector<Card*>::iterator it;
	for (it = vCardsOnHand.begin(); it != vCardsOnHand.end(); ++it)
	{
		delete* it;
		*it = nullptr;
	}
	vCardsOnHand.clear();
}

Hand::~Hand()
{
	Clear();
}