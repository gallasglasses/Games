#pragma once
#include <iostream>
#include <string>

class Card
{
public:
    enum CardFace
    {
        Ace = 1,
        Two,
        Three,
        Four,
        Five,
        Six,
        Seven,
        Eight,
        Nine,
        Ten,
        Jack,
        Queen,
        King,
    }; //rank: Ace, King, Queen, Jack, 10, 9, 8, 7, 6, 5, 4, 3, 2

    enum CardSuit
    {
        Clubs,
        Diamonds,
        Hearts,
        Spades
    }; //suit: clubs, diamonds, hearts, and spades

    Card(CardFace cFace = Two, CardSuit cSuit = Clubs, bool cOpen = true);

    void FlipCard();
    size_t getValue() const;

private:
    bool isCardOpen;

    CardFace cardFace;
    CardSuit cardSuit;

    friend std::ostream& operator<<(std::ostream& out, const Card& card)
    {
        const std::string CardRank[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
        const std::string CardSuit[] = { "\005", "\004", "\003", "\006" };
        return (card.isCardOpen) ? (out << CardRank[card.cardFace] << " " << CardSuit[card.cardSuit]) : (out << "XX");
    }
};