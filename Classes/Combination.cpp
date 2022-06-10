//
// Created by retretor on 29.05.2022.
//

#include "Combination.h"



std::deque<Card *> Combination::ParseCombination(std::deque<Card *> deck) {


    if(ParseRoyalFlush(deck, 14) != 0)
    {
        comboType = 10;
        return combination;
    }
    if(ParseStraightFlush(deck, 14) != 0)
    {
        comboType = 9;
        return combination;
    }
    if(ParseFourOfAKind(deck) != 0)
    {
        comboType = 8;
        return combination;
    }
    if(ParseFullHouse(deck) != 0)
    {
        comboType = 7;
        return combination;
    }
    if(ParseFlush(deck) != 0)
    {
        comboType = 6;
        return combination;
    }
    if(ParseStraight(deck) != 0)
    {
        comboType = 5;
        return combination;
    }
    if(ParseThreeOfAKind(deck) != 0)
    {
        comboType = 4;
        return combination;
    }
    if(ParseTwoPair(deck) != 0)
    {
        comboType = 3;
        return combination;
    }
    if(ParseOnePair(deck) != 0)
    {
        comboType = 2;
        return combination;
    }
    if(ParseHighCard(deck) != 0)
    {
        comboType = 1;
        return combination;
    }

}

int Combination::ParseRoyalFlush(std::deque<Card *> deck, int rank) {
    std::deque<Card *> deck_tmp = deck;

    std::deque<std::deque<Card *>> cards;


    for (int i = 0; i < deck_tmp.size(); i++)
    {
        for (int j = i + 1; j < deck_tmp.size(); j++)
        {
            if (deck_tmp[i]->GetRank() == deck_tmp[j]->GetRank())
            {
                cards.resize(cards.size() + 1);
                cards[cards.size() - 1].push_back(deck_tmp[i]);
                cards[cards.size() - 1].push_back(deck_tmp[j]);


                for(int f = j + 1; f < deck_tmp.size(); f++)
                {
                    if(deck_tmp[i]->GetRank() == deck_tmp[f]->GetRank())
                    {
                        cards[cards.size() - 1].push_back(deck_tmp[f]);
                        break;
                    }
                }
                i++;
                break;
            }
        }
    }
    int itter = 0;
    for (int i = 0; i < deck_tmp.size(); i++)
    {
        if (deck_tmp[i]->GetRank() == rank)
        {
            //erase i card from deck_tmp
            combination.push_back(deck_tmp[i]);
            deck_tmp.erase(deck_tmp.begin() + i);
            if(rank == 10 && cards.empty())
            {
                if(ParseFlush(combination) != 0)
                {
                    return 1;
                }
                break;
            }
            else if(rank == 10 && cards.size() <= 2)
            {
                if(cards.size() == 1) {


                    if (ParseFlush(combination, cards[itter][0]->GetSuit()) != 0) {
                        return 1;
                    }

                    std::deque<Card*> combination_tmp = combination;
                    for (int j = 0; j < combination_tmp.size(); j++) {
                        if (combination_tmp[j]->GetRank() == cards[itter][1]->GetRank()) {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter][1]->GetSuit()) != 0) {
                        combination = combination_tmp;
                        return 1;
                    }

                    combination_tmp = combination;
                    for (int j = 0; j < combination_tmp.size(); j++) {
                        if (combination_tmp[j]->GetRank() == cards[itter][2]->GetRank()) {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter][2]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter][2]->GetSuit()) != 0) {
                        combination = combination_tmp;
                        return 1;
                    }


                }
                else
                {
                    if (ParseFlush(combination, cards[itter][0]->GetSuit()) != 0) {

                        //00
                        if(ParseFlush(combination, cards[itter + 1][0]->GetSuit()) != 0)
                        {
                                return 1;
                        }

                        //01
                        std::deque<Card*> combination_tmp = combination;
                        for (int j = 0; j < combination.size(); j++) {
                            if (combination[j]->GetRank() == cards[itter + 1][1]->GetRank())
                            {
                                combination_tmp.erase(combination_tmp.begin() + j);
                                combination_tmp.insert(combination_tmp.begin() + j, cards[itter + 1][1]);
                                break;
                            }
                        }
                        if (ParseFlush(combination_tmp, cards[itter + 1][1]->GetSuit()) != 0)
                        {
                            combination = combination_tmp;
                            return 1;
                        }
                    }
                    //10
                    for (int j = 0; j < combination.size(); j++) {
                        if (combination[j]->GetRank() == cards[itter][1]->GetRank()) {
                            combination.erase(combination.begin() + j);
                            combination.insert(combination.begin() + j, cards[itter][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination, cards[itter][1]->GetSuit()) != 0) {
                        return 1;
                    }
                    if(ParseFlush(combination, cards[itter + 1][0]->GetSuit()) != 0)
                    {
                        return 1;
                    }
                    //11


                    std::deque<Card*> combination_tmp = combination;
                    for (int j = 0; j < combination.size(); j++) {
                        if (combination[j]->GetRank() == cards[itter + 1][1]->GetRank())
                        {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter + 1][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter + 1][1]->GetSuit()) != 0)
                    {
                        combination = combination_tmp;
                        return 1;
                    }


                }
            }
            else
            {
                return ParseRoyalFlush(deck_tmp, rank - 1);
            }
        }
    }

    return 0;
}

int Combination::ParseStraightFlush(std::deque<Card *> deck, int rank) {
    if(!switcher)
    {
        start_rank = rank - 4;
        switcher = true;
    }
    std::deque<Card *> deck_tmp = deck;

    std::deque<std::deque<Card *>> cards;


    for (int i = 0; i < deck_tmp.size(); i++)
    {
        for (int j = i + 1; j < deck_tmp.size(); j++)
        {
            if (deck_tmp[i]->GetRank() == deck_tmp[j]->GetRank())
            {
                cards.resize(cards.size() + 1);
                cards[cards.size() - 1].push_back(deck_tmp[i]);
                cards[cards.size() - 1].push_back(deck_tmp[j]);


                for(int f = j + 1; f < deck_tmp.size(); f++)
                {
                    if(deck_tmp[i]->GetRank() == deck_tmp[f]->GetRank())
                    {
                        cards[cards.size() - 1].push_back(deck_tmp[f]);
                        break;
                    }
                }
                i++;
                break;
            }
        }
    }
    int itter = 0;
    for (int i = 0; i < deck_tmp.size(); i++)
    {
        if (deck_tmp[i]->GetRank() == rank)
        {
            //erase i card from deck_tmp
            combination.push_back(deck_tmp[i]);
            deck_tmp.erase(deck_tmp.begin() + i);
            if(rank == start_rank && cards.empty())
            {
                if(ParseFlush(combination) != 0)
                {
                    return 1;
                }
                break;
            }
            else if(rank == start_rank && cards.size() <= 2)
            {
                if(cards.size() == 1) {


                    if (ParseFlush(combination, cards[itter][0]->GetSuit()) != 0) {
                        return 1;
                    }

                    std::deque<Card*> combination_tmp = combination;
                    for (int j = 0; j < combination_tmp.size(); j++) {
                        if (combination_tmp[j]->GetRank() == cards[itter][1]->GetRank()) {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter][1]->GetSuit()) != 0) {
                        combination = combination_tmp;
                        return 1;
                    }

                    combination_tmp = combination;
                    for (int j = 0; j < combination_tmp.size(); j++) {
                        if (combination_tmp[j]->GetRank() == cards[itter][2]->GetRank()) {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter][2]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter][2]->GetSuit()) != 0) {
                        combination = combination_tmp;
                        return 1;
                    }


                }
                else
                {
                    if (ParseFlush(combination, cards[itter][0]->GetSuit()) != 0) {

                        //00
                        if(ParseFlush(combination, cards[itter + 1][0]->GetSuit()) != 0)
                        {
                            return 1;
                        }

                        //01
                        std::deque<Card*> combination_tmp = combination;
                        for (int j = 0; j < combination.size(); j++) {
                            if (combination[j]->GetRank() == cards[itter + 1][1]->GetRank())
                            {
                                combination_tmp.erase(combination_tmp.begin() + j);
                                combination_tmp.insert(combination_tmp.begin() + j, cards[itter + 1][1]);
                                break;
                            }
                        }
                        if (ParseFlush(combination_tmp, cards[itter + 1][1]->GetSuit()) != 0)
                        {
                            combination = combination_tmp;
                            return 1;
                        }
                    }
                    //10
                    for (int j = 0; j < combination.size(); j++) {
                        if (combination[j]->GetRank() == cards[itter][1]->GetRank()) {
                            combination.erase(combination.begin() + j);
                            combination.insert(combination.begin() + j, cards[itter][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination, cards[itter][1]->GetSuit()) != 0) {
                        return 1;
                    }
                    if(ParseFlush(combination, cards[itter + 1][0]->GetSuit()) != 0)
                    {
                        return 1;
                    }
                    //11


                    std::deque<Card*> combination_tmp = combination;
                    for (int j = 0; j < combination.size(); j++) {
                        if (combination[j]->GetRank() == cards[itter + 1][1]->GetRank())
                        {
                            combination_tmp.erase(combination_tmp.begin() + j);
                            combination_tmp.insert(combination_tmp.begin() + j, cards[itter + 1][1]);
                            break;
                        }
                    }
                    if (ParseFlush(combination_tmp, cards[itter + 1][1]->GetSuit()) != 0)
                    {
                        combination = combination_tmp;
                        return 1;
                    }


                }
            }
            else
            {
                return ParseStraightFlush(deck_tmp, rank - 1);
            }
        }
    }
    if(rank >= 6)
    {
        combination.clear();
        switcher = false;
        return ParseStraightFlush(deck, rank - 1);
    }

    return 0;
}

int Combination::ParseFourOfAKind(std::deque<Card *> deck) {
    for (int i = 0; i < deck.size(); i++)
    {
        int count = 0;
        for (int j = i; j < deck.size(); j++)
        {
            if (deck[i]->GetRank() == deck[j]->GetRank())
            {
                count++;
                combination.push_back(deck[j]);
            }
        }
        if (count == 4)
        {
            return 1;
        }
        else
        {
            combination.clear();
        }
    }
    combination.clear();
    return 0;
}

int Combination::ParseFullHouse(std::deque<Card *> deck) {
    //check for three of a kind and two of a kind in the deck
    std::deque<Card *> deck_tmp = deck;
    std::deque<Card *> deck_tmp2 = deck;
    int rank, rank2;
    for (int i = 0; i < deck.size(); i++)
    {
        int count = 0;
        for (int j = i; j < deck.size(); j++)
        {
            if (deck[i]->GetRank() == deck[j]->GetRank())
            {
                rank = deck[i]->GetRank();
                combination.push_back(deck[j]);
                deck_tmp.erase(deck_tmp.begin() + j - count);
                count++;
            }
        }
        if (count == 3)
        {
            for (int f = 0; f < deck.size(); f++)
            {
                int count2 = 0;
                for (int j = f; j < deck.size(); j++)
                {
                    if (deck[f]->GetRank() == deck[j]->GetRank() && deck[j]->GetRank() != rank)
                    {
                        rank2 = deck[f]->GetRank();
                        combination.push_back(deck[j]);
                        deck_tmp2.erase(deck_tmp2.begin() + j - count2);
                        count2++;
                    }
                }
                if (count2 == 3)
                {
                    if(rank > rank2)
                    {
                        combination.erase(combination.begin() + combination.size() - 1);
                        return 1;
                    }
                    else
                    {
                        combination.erase(combination.begin());
                        return 1;
                    }
                }
                else if(count2 == 2)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
        }
        else
        {
            combination.clear();
        }
    }
    return 0;
}

int Combination::ParseFlush(std::deque<Card *> deck) {
    if(deck.size() == 5)
    {
        for(int i = 0; i < 5; i++)
        {
            if(deck[i]->GetSuit() != deck[0]->GetSuit())
            {
                return 0;
            }
        }
        return 1;
    }
    else
    {
        for (int i = 0; i < deck.size(); i++)
        {
            int count = 0;
            for (int j = i; j < deck.size(); j++)
            {
                if (deck[i]->GetSuit() == deck[j]->GetSuit())
                {
                    count++;
                    combination.push_back(deck[j]);
                }
            }
            if (count == 5)
            {
                return 1;
            }
            else if(count > 5)
            {
                int min = 14, pos_min;
                for(int j = 0; j < combination.size(); j++)
                {
                    if(combination[j]->GetRank() < min)
                    {
                        min = combination[j]->GetRank();
                        pos_min = j;
                    }
                }
                combination.erase(combination.begin() + pos_min);
                if(count > 5)
                {
                    for(int j = 0; j < combination.size(); j++)
                    {
                        if(combination[j]->GetRank() < min)
                        {
                            min = combination[j]->GetRank();
                            pos_min = j;
                        }
                    }
                    combination.erase(combination.begin() + pos_min);
                }
                return 1;
            }
            else
            {
                combination.clear();
            }
        }
        combination.clear();
        return 0;
    }

}

int Combination::ParseFlush(std::deque<Card *> deck, int suit) {

    for(int i = 0; i < deck.size(); i++)
    {
        if(deck[i]->GetSuit() != suit)
        {
            return 0;
        }
    }
    return 1;
}

int Combination::ParseStraight(std::deque<Card *> deck) {
    return 0;
}

int Combination::ParseThreeOfAKind(std::deque<Card *> deck) {
    std::deque<Card *> deck_tmp = deck;
    std::deque<Card *> deck_tmp2 = deck;
    int rank, rank2;
    for (int i = 0; i < deck.size(); i++)
    {
        int count = 0;
        for (int j = i; j < deck.size(); j++)
        {
            if (deck[i]->GetRank() == deck[j]->GetRank())
            {
                rank = deck[i]->GetRank();
                combination.push_back(deck[j]);
                deck_tmp.erase(deck_tmp.begin() + j - count);
                count++;
            }
        }
        if (count == 3)
        {
            for (int f = 0; f < deck.size(); f++)
            {
                int count2 = 0;
                for (int j = f; j < deck.size(); j++)
                {
                    if (deck[f]->GetRank() == deck[j]->GetRank() && deck[j]->GetRank() != rank)
                    {
                        rank2 = deck[f]->GetRank();
                        combination.push_back(deck[j]);
                        deck_tmp2.erase(deck_tmp2.begin() + j - count2);
                        count2++;
                    }
                }
                if (count2 == 3)
                {
                    if(rank > rank2)
                    {
                        combination.erase(combination.begin() + combination.size() - 1);
                        combination.erase(combination.begin() + combination.size() - 1);
                        combination.erase(combination.begin() + combination.size() - 1);
                        return 1;
                    }
                    else
                    {
                        combination.erase(combination.begin());
                        combination.erase(combination.begin());
                        combination.erase(combination.begin());
                        return 1;
                    }
                }
                else
                {
                    if(count2 == 2)
                    {
                        combination.erase(combination.begin() + combination.size() - 1);
                        combination.erase(combination.begin() + combination.size() - 1);
                    }
                    else if(count2 == 1)
                    {
                        combination.erase(combination.begin() + combination.size() - 1);
                    }
                    return 1;
                }
            }
        }
        else
        {
            combination.clear();
        }
    }
    return 0;
}

int Combination::ParseTwoPair(std::deque<Card *> deck) {
    for(int i = 0; i < deck.size(); i++)
    {
        int count = 0;
        for(int j = i; j < deck.size(); j++)
        {
            if(deck[i]->GetRank() == deck[j]->GetRank())
            {
                count++;
                combination.push_back(deck[j]);
            }
            if(count == 2)
            {
                deck.erase(deck.begin() + j);
                deck.erase(deck.begin() + i);
                i = 0;
            }
        }
        if(count < 2)
        {
            deck.erase(deck.begin() + i);
            combination.clear();
        }
    }
    if(combination.size() >= 4)
    {
        if(combination.size() == 4)
        {
            return 1;
        }
        if(combination.size() == 6)
        {
            if(combination[0]->GetRank() < combination[4]->GetRank()
                && combination[0]->GetRank() < combination[6]->GetRank())
            {
                combination.erase(combination.begin());
                combination.erase(combination.begin());
                return 1;
            }
            if(combination[4]->GetRank() < combination[0]->GetRank()
                && combination[4]->GetRank() < combination[6]->GetRank())
            {
                combination.erase(combination.begin() + 4);
                combination.erase(combination.begin() + 3);
                return 1;
            }
            combination.erase(combination.begin() + combination.size() - 1);
            combination.erase(combination.begin() + combination.size() - 1);
            return 1;
        }
    }
    else
    {
        combination.clear();
        return 0;
    }
}

int Combination::ParseOnePair(std::deque<Card *> deck) {

    for(int i = 0; i < deck.size(); i++)
    {
        int count = 0;
        for(int j = i; j < deck.size(); j++)
        {
            if(deck[i]->GetRank() == deck[j]->GetRank())
            {
                count++;
                combination.push_back(deck[j]);
                combination[combination.size() - 1]->Print();//delete later
            }
            if(count == 2)
            {
                deck.erase(deck.begin() + j);
                deck.erase(deck.begin() + i);
                i = 0;
            }
        }

        if(count < 2)
        {
            deck.erase(deck.begin() + i);
            combination.clear();
        }
    }
    for(int i = 0; i < combination.size(); i++)
    {
        std::cout << "Combination deque: " << combination[i] << std::endl;
    }
    if(combination.size() == 2)
    {
        return 1;
    }
    combination.clear();
    return 0;
}

int Combination::ParseHighCard(std::deque<Card *> deck) {
    //find max card in the deck
    int max = 0;
    for(int i = 0; i < deck.size(); i++)
    {
        if(deck[i]->GetRank() > max)
        {
            max = deck[i]->GetRank();
        }
    }

    //find card with the max rank
    for(int i = 0; i < deck.size(); i++)
    {
        if(deck[i]->GetRank() == max)
        {
            combination.push_back(deck[i]);
            break;
        }
    }
    return 1;
}


int Combination::GetComboType() {
    return comboType;
}


