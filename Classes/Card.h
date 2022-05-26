//
// Created by retretor on 26.05.2022.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H

class Card
{
public:
    enum Suits
    {
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES
    };
    enum Ranks
    {
        TWO = 2,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };
    Card(Suits suit, Ranks rank);
    Suits GetSuit() const;
    Ranks GetRank() const;
    void Print() const;
private:
    Suits suit;
    Ranks rank;
};

#endif //POKER_CARD_H
