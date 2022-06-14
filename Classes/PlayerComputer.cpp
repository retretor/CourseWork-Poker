//
// Created by retretor on 13.06.2022.
//

#include "PlayerComputer.h"

int PlayerComputer::SetABet(Table *table, int min_bet) {
    if(min_bet >= chip)
    {
        if(playerDeck[0]->GetRank() == playerDeck[1]->GetRank()
        || playerDeck[0]->GetSuit() == playerDeck[1]->GetSuit())
        {
            Raise(table, chip);
            return chip;
        }
        else
        {
            playStatus = FOLD;
            return 0;
        }
    }
    else if(min_bet == 0){
        playStatus = CHECK;
        return 0;
    }
    else
    {
        if(playerDeck[0]->GetRank() == playerDeck[1]->GetRank()
           || playerDeck[0]->GetSuit() == playerDeck[1]->GetSuit())
        {
            Raise(table, min_bet);
            return min_bet;
        }
        else
        {
            playStatus = FOLD;
            return 0;
        }
    }
}

void PlayerComputer::Raise(Table *table, int chip) {
    playStatus = RAISE;
    table->AddChip(chip);
    AddChip(-chip);
}
