#include "Deck.h"


Deck::Deck()
{
	vCardsOnHand.reserve(MAX_N_CARD);
	Populate();
}

void Deck::Populate()
{
	Clear();
	for (int cSuit = Card::CLUBS; cSuit <= Card::SPADES; ++cSuit)
	{
		for (int cFace = Card::ACE; cFace <= Card::KING; ++cFace)
		{
			Add(new Card(static_cast<Card::CardFace>(cFace), static_cast<Card::CardSuit>(cSuit)));
		}
	}
}

void Deck::Shuffle()
{
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(std::begin(vCardsOnHand), std::end(vCardsOnHand), g);

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

void Deck::AdditionalCards(GenericPlayer& aGenericPlayer)
{
	while (aGenericPlayer.isHitting() && !(aGenericPlayer.isBoosted()))
	{
		Deal(aGenericPlayer);
		std::cout << "\x1B[2J\x1B[H";
		std::cout << aGenericPlayer;
		if (aGenericPlayer.isBoosted())
		{
			break;
		}
	}
}

Deck::~Deck()
{

}