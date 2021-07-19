#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
	vCardsOnHand.reserve(MAX_N_CARD);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (int cFace = Card::Ace; cFace <= Card::King; cFace++)
	{
		for (int cSuit = Card::Clubs; cSuit <= Card::Spades; cSuit++)
		{
			Add(new Card(static_cast<Card::CardFace>(cFace), static_cast<Card::CardSuit>(cSuit)));
		}
	}
}

void Deck::Shuffle()
{
	for (size_t i = 0; i <= MAX_N_CARD; i++)
	{
		int ratioShuffle = (rand() + time(0)) % MAX_N_CARD;
		std::shuffle(vCardsOnHand.begin(), vCardsOnHand.end(), ratioShuffle);
	}
}

void Deck::Deal(Hand& aHand)
{
	if (!vCardsOnHand.empty())
	{
		aHand.Add(vCardsOnHand.back());
		vCardsOnHand.pop_back();
	}
	else
	{
		std::cout << "Deck is empty!\n";
	}
}

void Deck::AdditionalCards(GenericPlayer& aGenerlcPlayer)
{
	while (aGenerlcPlayer.isHitting() && !aGenerlcPlayer.isBoosted())
	{
		Deal(aGenerlcPlayer);
		std::cout << aGenerlcPlayer;
		if (aGenerlcPlayer.isBoosted())
		{
			aGenerlcPlayer.Bust();
		}
	}
}
