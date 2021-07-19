#include "Card.h"

Card::Card(CardFace cFace, CardSuit cSuit, bool cardOpen)
    : cardFace(cFace),
    cardSuit(cSuit),
    isCardOpen(cardOpen)
{

};

void Card::FlipCard()
{
    isCardOpen = !(isCardOpen);
}

size_t Card::getValue() const
{
    size_t valueCard = 0;
    if (isCardOpen)
    {
        return cardFace > 10 ? 10 : cardFace;
    }
    return 0;
}