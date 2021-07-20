#pragma once
#include <iostream>
#include <string>

class Card
{
public:
    enum CardFace
    {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING}; //rank: Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2

    enum CardSuit
    {CLUBS, DIAMONDS, HEARTS, SPADES}; //suit: clubs, diamonds, hearts, and spades

    Card(CardFace cFace = ACE, CardSuit cSuit = CLUBS, bool cOpen = true);

    int getValue() const;
    void FlipCard();
    ~Card();

private:
    bool isCardOpen;

    CardFace cardFace;
    CardSuit cardSuit;

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        const std::string sCardRank[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        const std::string sCardSuit[] = { "\005", "\004", "\003", "\006" };
        return (card.isCardOpen) ? out << sCardRank[card.cardFace] << " " << sCardSuit[card.cardSuit] : out << "XX";
    }
};