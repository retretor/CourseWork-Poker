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
        HEARTS = 0,
        DIAMONDS = 1,
        CLUBS = 2,
        SPADES = 3,
        NONE = -1
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
    void SetSuit(Suits suit);
    void SetRank(Ranks rank);
    void Print() const;
    void SetIsOnCombination(bool value);
    bool GetIsOnCombination();
private:
    Suits suit;
    Ranks rank;
    bool IsOnCombination;
};

#endif //POKER_CARD_H
