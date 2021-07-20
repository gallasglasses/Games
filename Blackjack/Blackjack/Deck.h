#pragma once
#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
public:
	const int MAX_CARD_DECK = 52;

	Deck();

	void Populate();
	void Shuffle();
	void Deal(Hand& aHand);
	void AdditionalCards(GenericPlayer& aGenericPlayer);

	virtual ~Deck();
};

