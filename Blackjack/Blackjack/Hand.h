#pragma once
#include <iostream>
#include <vector>

#include "Card.h"

class Hand
{
public:

	const int MAX_N_CARD = 7; // 2 * 4, 3 * 4 + 1

	Hand();

	int getTotal() const;
	void Add(Card* card);
	void Clear();

	virtual ~Hand();

protected:
	std::vector<Card*> vCardsOnHand;
};