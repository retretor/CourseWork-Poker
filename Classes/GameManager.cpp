//
// Created by retretor on 26.05.2022.
//

#include "GameManager.h"


//---------------------------------------------------------


GameManager::GameManager() : countOfPlayersBots(1), countOfPlayersHuman(1) {

}

GameManager::~GameManager() {
    delete table;
}


//---------------------------------------------------------


void GameManager::CreatePlayers(Deck* deck) {
    //get count players
    SetCountOfPlayers();
    //create players
    for(int i = 0; i < countOfPlayersBots; i++)
    {
        players.push_front(new PlayerComputer);
    }
    for(int i = 0; i < countOfPlayersHuman; i++)
    {
        players.push_front(new PlayerHuman);
    }

    //give players cards
    for(Player* player : players) {
        for(int i = 0; i < 2; i++)
        {
            player->SetCard(deck->TopCard());
            deck->PopCard();
        }
    }
}

void GameManager::PrintPlayers() const{
    int i = 1;
    //Print "Player 1: 2C 3S"
    for(Player* player : players) {
        std::cout << "Player " << i << ": ";
        player->Print();
        std::cout << std::endl;
        i++;
    }
}


void GameManager::CreateTable(Deck *deck) {
    //give table cards
    this->table = new Table();
    for(int i = 0; i < 5; i++)
    {
        table->SetCard(deck->TopCard());
        deck->PopCard();
    }
}

void GameManager::PrintTable(int n) const {
    std::cout << "Table: ";
    table->Print(n);
    std::cout << std::endl;
}

void GameManager::CreateHand() {
    for(int i = 0; i < GetCountOfPlayers(); i++)
    {
        hand.push_front(new Hand);
    }

    int n = 0;
    for(Player* player : players)
    {
        for(int i = 0; i < 2; i++)
        {
            hand[n]->SetCard(player->GetDeck()[i]);
        }
        n++;
    }
    for(int i = 0; i < GetCountOfPlayers(); i++)
    {
        for(int j = 0; j < 5; j++)
        {
            hand[i]->SetCard(table->GetDeck()[j]);
        }
    }
}

//---------------------------------------------------------


void GameManager::SetCountOfPlayers(){
    int n = -1;
    while(n < minBots || n > maxPlayers)
    {
        std::cout << "Enter count of bots: ";
        std::cin >> n;
        if(n < minBots || n > maxPlayers)
        {
            std::cout << "Invalid count of bots, try again" << std::endl;
        }
    }
    countOfPlayersBots = n;
    std::cout << "\n";
    n = -1;
    while((n < 2 && countOfPlayersBots == 0)
            || (n < 1 && countOfPlayersBots != 0)
            || n > maxPlayers - countOfPlayersBots)
    {
        std::cout << "Enter count of human: ";
        std::cin >> n;
        if((countOfPlayersBots < 1 && n < 2)
            || (countOfPlayersBots >= 1 && n < 1)
            || n > maxPlayers - countOfPlayersBots)
        {
            std::cout << "Invalid count of players, try again" << std::endl;
        }
    }
    countOfPlayersHuman = n;
    std::cout << "\n";
}


int GameManager::SetABet() {
    int i = 1;
    int min_bet = 0;
    for(Player* player : players){
        if(player->GetPlayStatus() != Player::PlayStatus::FOLD)
        {
            std::cout << "Player " << i << ": ";
            min_bet = player->SetABet(table, min_bet);
            if(min_bet == -1)
            {
                std::cout << "Player " << i << " fold" << std::endl;
                player->SetWin(false);
                int c = 0;
                for(Player* player_ : players)
                {
                    if(player_->GetWin() != true)
                    {
                        c++;
                    }
                }
                if(c == GetCountOfPlayers() - 1)
                {
                    return 1;
                }
            }
            i++;
            for(int j = 0; j < 100; j++)
            {
                std::cout << std::endl;
            }
        }
    }
    return 0;
}



void GameManager::PlayerHasCombo() {
    int c_3 = 0;
    for(int i = 0; i < hand.size(); i++)
    {
        if(players[c_3]->GetPlayStatus() == Player::PlayStatus::FOLD)
        {
            delete hand[i];
            hand.erase(hand.begin() + i);
            i--;
            c_3++;
        }
    }

    if(hand.size() == 1)
    {
        for(Player* player : players)
        {
            if(player->GetWin() != true)
            {
                player->SetWin(false);
            }
        }
        return;
    }
   for(Hand* hand_ : hand)
   {
       Combination combination{};
       hand_->FillCards();
       hand_->SetMaxCardCombo(combination.ParseCombination(hand_->GetCards()));
       hand_->SetComboType(combination.GetComboType());
   }


   int max_combo = 0;
   for(int i = 0; i < hand.size(); i++)
   {
         if(hand[i]->GetComboType() > max_combo)
         {
              max_combo = hand[i]->GetComboType();
         }
   }

   int c = 0;
   for(int i = 0; i < hand.size(); i++)
   {
       if(hand[i]->GetComboType() == max_combo)
       {
           c++;
           players[i]->SetWin(true);
       }
       else
       {
           players[i]->SetWin(false);
       }
   }


   if(c > 1)
   {
       for(int i = 0; i < hand.size() - 1; i++)
       {
           for(int j = i + 1; j < hand.size(); j++) {
               if(players[i]->GetWin() == true && players[j]->GetWin() == true)
               {
                   if(hand[i]->GetMaxCardCombo() > hand[j]->GetMaxCardCombo())
                   {
                       players[i]->SetWin(true);
                       players[j]->SetWin(false);
                   }
                   else if(hand[i]->GetMaxCardCombo() < hand[j]->GetMaxCardCombo())
                   {
                       players[i]->SetWin(false);
                       players[j]->SetWin(true);
                   }
                   else
                   {
                       if(players[i]->GetWeight() > players[j]->GetWeight())
                       {
                           players[i]->SetWin(true);
                           players[j]->SetWin(false);
                       }
                       else if(players[i]->GetWeight() < players[j]->GetWeight())
                       {
                           players[i]->SetWin(false);
                           players[j]->SetWin(true);
                       }
                       else
                       {
                           players[i]->SetWin(true);
                           players[j]->SetWin(true);
                       }
                       for(int p = 0; p < i; p++)
                       {
                           players[p]->SetWin(false);
                       }
                   }
               }
           }
       }
   }
}





void GameManager::Result() {

    int c = 0;

    for(int i = 0; i < GetCountOfPlayers(); i++)
    {
        if(players[i]->GetWin() == true)
        {
            c++;
        }
    }
    int winChip = table->GetChip() / c;
    table->AddChip(-table->GetChip());

    for(int i = 0; i < players.size(); i++)
    {
        if(players[i]->GetWin() == true)
        {
            players[i]->AddChip(winChip);
            std::cout << "Player " << (i + 1) << " win!\n";;
        }
    }

    table->Print(10);

}

//---------------------------------------------------------


int GameManager::GetCountOfPlayers() const{
    return countOfPlayersBots + countOfPlayersHuman;
}