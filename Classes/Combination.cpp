//
// Created by retretor on 29.05.2022.
//

#include "Combination.h"



int Combination::ParseCombination(std::vector<std::vector<bool>> deck) {

    if(ParseRoyalFlush(deck) != 0)
    {
        comboType = 10;
        return max_card_in_combo;
    }
    if(ParseStraightFlush(deck) != 0)
    {
        comboType = 9;
        return max_card_in_combo;
    }
    if(ParseFourOfAKind(deck) != 0)
    {
        comboType = 8;
        return max_card_in_combo;
    }
    if(ParseFullHouse(deck) != 0)
    {
        comboType = 7;
        return max_card_in_combo;
    }
    if(ParseFlush(deck) != 0)
    {
        comboType = 6;
        return max_card_in_combo;
    }
    if(ParseStraight(deck) != 0)
    {
        comboType = 5;
        return max_card_in_combo;
    }
    if(ParseThreeOfAKind(deck) != 0)
    {
        comboType = 4;
        return max_card_in_combo;
    }
    if(ParseTwoPair(deck) != 0)
    {
        comboType = 3;
        return max_card_in_combo;
    }
    if(ParseOnePair(deck) != 0)
    {
        comboType = 2;
        return max_card_in_combo;
    }
    if(ParseHighCard(deck) != 0)
    {
        comboType = 1;
        return max_card_in_combo;
    }
}

int Combination::ParseRoyalFlush(std::vector<std::vector<bool>> deck) {
    int c = 0;
    for(int i = 0; i < 4; i++) {
        for (int j = 12; j >= 8; j--)
        {
            if(deck[i][j] != true)
            {
                break;
            }
            else c++;
        }
        if(c == 5)
        {
            max_card_in_combo = 14;
            return 1;
        }
        else c = 0;
    }
    return 0;
}

int Combination::ParseStraightFlush(std::vector<std::vector<bool>> deck) {
    int c = 0;
    for(int i = 0; i < 4; i++) {
        for (int j = 12; j >= 0; j--)
        {
            if(deck[i][j] == true && c == 5)
            {
                max_card_in_combo = j + 2;
                return 1;
            }
            else if(deck[i][j] == true && c != 5)
            {
                c++;
            }
            else c = 0;
        }
    }
    return 0;
}

int Combination::ParseFourOfAKind(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j >= 0; j--)
    {
        if(deck[0][j] == true && deck[1][j] == true &&
            deck[2][j] == true && deck[3][j] == true)
        {
            max_card_in_combo = j + 2;
            return 1;
        }
    }
    return 0;
}

int Combination::ParseFullHouse(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j >= 0; j--)
    {
        int c = 0;
        for(int i = 0; i < 4; i++)
        {
            if(deck[i][j] == true)
            {
                c++;
            }
        }
        //find three of a kind
        if(c == 3)
        {
            int c_2 = 0;
            //find pair
            for (int k = 12; k >= 0; k--)
            {
                for(int i = 0; i < 4; i++)
                {
                    if(deck[i][k] == true && k != j)
                    {
                        c_2++;
                    }
                }
                if(c_2 >= 2)
                {
                    max_card_in_combo = j + 2;
                    return 1;
                }
                else c_2 = 0;
            }
        }
    }
    return 0;
}

int Combination::ParseFlush(std::vector<std::vector<bool>> deck) {
    for(int i = 0; i < 4; i++)
    {
        int c = 0, k = 0;
        for(int j = 12; j >= 0; j--)
        {
            if(deck[i][j] == true)
            {
                c++;
                if(k == 0)
                {
                    k = j + 2;
                }
            }
        }
        if(c >= 5)
        {
            max_card_in_combo = k;
            return 1;
        }
    }
    return 0;
}

int Combination::ParseStraight(std::vector<std::vector<bool>> deck) {
    std::vector<bool> deck_tmp = {
            false, false, false, false, false,
            false, false, false, false, false,
            false, false, false
    };
    for(int i = 0; i < 13; i++)
    {
        if(deck[0][i] == true || deck[1][i] == true ||
           deck[2][i] == true || deck[3][i] == true)
        {
            deck_tmp[i] = true;
        }
    }

    int c = 0;
    for (int j = 12; j >= 0; j--)
    {
        if(deck_tmp[j] == true && c == 4)
        {
            max_card_in_combo = j + 2;
            deck_tmp.clear();
            return 1;
        }
        else if(deck_tmp[j] == true)
        {
            c++;
        }
        else c = 0;
    }
    deck_tmp.clear();
    return 0;
}


int Combination::ParseThreeOfAKind(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j >= 0; j--)
    {
        int c = 0;
        for(int i = 0; i < 4; i++)
        {
            if(deck[i][j] == true)
            {
                c++;
            }
        }
        if(c == 3)
        {
            max_card_in_combo = j + 2;
            return 1;
        }
    }
    return 0;
}

int Combination::ParseTwoPair(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j > 0; j--)
    {
        int c = 0;
        for(int i = 0; i < 4; i++)
        {
            if(deck[i][j] == true)
            {
                c++;
            }
        }

        if(c == 2)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                int c_2 = 0;
                for(int i = 0; i < 4; i++)
                {
                    if(deck[i][k] == true)
                    {
                        c_2++;
                    }
                }

                if(c_2 == 2)
                {
                    max_card_in_combo = j + 2;
                    return 1;
                }
            }
        }
    }
    return 0;

}

int Combination::ParseOnePair(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j >= 0; j--)
    {
        int c = 0;
        for(int i = 0; i < 4; i++)
        {
            if(deck[i][j] == true)
            {
                c++;
            }
        }
        if(c == 2)
        {
            max_card_in_combo = j + 2;
            return 1;
        }
    }
    return 0;
}

int Combination::ParseHighCard(std::vector<std::vector<bool>> deck) {
    for(int j = 12; j >= 0; j--)
    {
        for(int i = 0; i < 4; i++)
        {
            if(deck[i][j] == true)
            {
                max_card_in_combo = j + 2;
                return 1;
            }
        }
    }
    return 0;
}


int Combination::GetComboType() {
    return comboType;
}
