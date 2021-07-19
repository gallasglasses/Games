#pragma once
#include <iostream>
#include <vector>

#include "Card.h"

class Hand
{
public:

	const size_t MAX_N_CARD = 7; // 2 * 4, 3 * 4 + 1

	Hand();

	size_t getValue() const;
	void Add(Card* card);
	void Clear();

	~Hand();

protected:
	std::vector<Card*> vCardsOnHand;
};