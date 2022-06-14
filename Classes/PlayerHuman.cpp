//
// Created by retretor on 26.05.2022.
//

#include "PlayerHuman.h"


int PlayerHuman::SetABet(Table *table, int min_bet) {
    if(min_bet == -1)
    {
        std::cout << "Previous player is FOLD\n";
    }
    else if(min_bet == 0)
    {
        std::cout << "Previous player is CHECK\n";
    }
    else
    {
        std::cout << "Previous player is RAISE " << min_bet << "\n";
    }

    std::cout << "Your cards are ";
    Print();

    int bet = -1;
    START_BET:

    if(min_bet >= chip)
    {
        std::cout << "\n";
        std::cout << "You can only go ALL IN. Enter -1 to FOLD, and another for ALL IN: "
                  << std::endl;
        std::cin >> bet;
        if(bet < -1 || bet > chip)
        {
            std::cout << "Invalid bet. Try again." << std::endl;
            goto START_BET;
        }


        if(bet == -1)
        {
            playStatus = FOLD;
            return 0;
        }
        else Raise(table, chip); // ALL IN
    }
    else if(min_bet == 0){
        std::cout << "\n";
        std::cout << "If you want to FOLD, enter -1. If you want to CHECK, enter 0. If you want to RAISE, enter bet: "
                  << std::endl;
        std::cin >> bet;
        if(bet < -1 || bet > chip)
        {
            std::cout << "Invalid bet. Try again." << std::endl;
            goto START_BET;
        }

        if(bet == -1)
        {
            playStatus = FOLD;
            return 0;
        }
        else if(bet == 0)
        {
            playStatus = CHECK;
            return 0;
        }
        else
        {
            Raise(table, bet);
            return bet;
        }
    }
    else
    {
        std::cout << "\n";
        std::cout << "If you want to FOLD, enter -1. If you want to RAISE, enter bet: "
                  << std::endl;
        std::cin >> bet;
        if(bet < -1 || bet > chip)
        {
            std::cout << "Invalid bet. Try again." << std::endl;
            goto START_BET;
        }

        if(bet == -1)
        {
            playStatus = FOLD;
            return 0;
        }
        else Raise(table, bet);
        return bet;
    }
}
void PlayerHuman::Raise(Table *table, int chip) {
    playStatus = RAISE;
    table->AddChip(chip);
    AddChip(-chip);
}