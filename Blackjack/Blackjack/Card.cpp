#include "Card.h"

Card::Card(CardFace cFace, CardSuit cSuit, bool cOpen)
    : cardFace(cFace),
    cardSuit(cSuit),
    isCardOpen(cOpen)
{
    
}

int Card::getValue() const
{
    int valueCard = 0;
    if (isCardOpen)
    {
        valueCard = (cardFace > 10) ? 10 : cardFace;
    }
    return valueCard;
}

void Card::FlipCard()
{
    isCardOpen = !(isCardOpen);
}

Card::~Card()
{

}