//
// Created by retretor on 26.05.2022.
//

#include "GameManager.h"


//---------------------------------------------------------


GameManager::GameManager() : countOfPlayers(1) {
    SayHello();
}
GameManager::~GameManager() {
    for(Player* player : players)
    {
        delete player;
    }
    players.clear();
    for(Table* _table : table)
    {
        delete _table;
    }
    table.clear();
    for(Hand* _hand : hand)
    {
        delete _hand;
    }
    hand.clear();
}


//---------------------------------------------------------


void GameManager::CreatePlayers(int countOfPlayers, Deck* deck) {
    //create players
    if(countOfPlayers > maxPlayers || countOfPlayers < 2)
        throw std::invalid_argument("Invalid countOfPlayers");


    for(int i = 0; i < countOfPlayers; i++)
    {
        players.push_front(new Player);
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
    table.push_front(new Table);
    for(int i = 0; i < 5; i++)
    {
        table[0]->SetCard(deck->TopCard());
        deck->PopCard();
    }
}

void GameManager::PrintTable() const {
    std::cout << "Table " << ": ";
    table[0]->Print();
    std::cout << std::endl;
}

void GameManager::CreateHand() {
    for(int i = 0; i < countOfPlayers; i++)
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
    for(int i = 0; i < countOfPlayers; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            hand[i]->SetCard(table[0]->GetDeck()[j]);
        }
    }
}

void GameManager::PrintHand() {
    int i = 1;
    //Print "Player 1: 2C 3S 2D 5C 10C"
    for(Hand* _hand : hand) {
        std::cout << "Player " << i << ": ";
        _hand->Print();
        std::cout << std::endl;
        i++;
    }
}

//---------------------------------------------------------


void GameManager::SayHello(){
    int n;
    std::cout << "Hello, how many people will play poker?(Max players - 23): ";
    std::cin >> n;
    countOfPlayers = n;
}

void GameManager::SetABet() {
    int i = 1;
    for(Player* player : players){
        std::cout << "Player " << i << "How many chips you will bet?:";
        int c;
        std::cin >> c;
        if(c < 0) throw std::invalid_argument("Invalid bet");
        player->SetABet(c, table[0]);
        i++;
    }
}



void GameManager::PlayerHasCombo() {
   for(Hand* hand_ : hand)
   {
       Combination combination;
       hand_->SetPlayHand(combination.ParseCombination(hand_->GetDeck()));
       hand_->SetComboType(combination.GetComboType());
   }
   //find max hand_.GetComboType()
    int max_combo = 0;
    int k = 0;
    for(Hand* hand_ : hand)
    {
        std::cout << k << " " << hand_->GetComboType() << "\n";
        k++;
    }
    for(Hand* hand_ : hand)
    {
        if(hand_->GetComboType() > max_combo)
        {
            max_combo = hand_->GetComboType();
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
        for(int i = 0; i < hand.size(); i++)
        {
            players[i]->SetWin(false);
        }

        Card* max_card = new Card(Card::Suits::NONE, Card::Ranks::TWO);

        for(Hand* hand_ : hand)
        {
            Hand* hand_tmp = new Hand;
            hand_tmp->SetDeck(hand_->GetDeck());

            std::deque<Card*> hand_tmp_deque = hand_tmp->GetDeck();


            for(int i = 0; i < hand_tmp->GetDeck().size(); i++)
            {
                for(int j = 0; j < hand_->GetPlayHand().size(); j++)
                {
                    if(hand_tmp->GetDeck()[i] == hand_->GetPlayHand()[j])
                    {
                        /*
                        hand_tmp_deque.erase(hand_tmp_deque.begin() + i);
                        hand_tmp->SetDeck(hand_tmp_deque);
                         */
                        hand_tmp->GetDeck()[i]->SetIsOnCombination(true);
                        break;
                    }
                }
            }
            //find max card in hand_tmp
            max_card = hand_tmp->GetDeck()[0];
            for(int i = 0, j = 0; i < hand_tmp->GetDeck().size(); i++)
            {
                if(j == 0 && hand_tmp->GetDeck()[i]->GetIsOnCombination() == false)
                {
                    max_card = hand_tmp->GetDeck()[i];
                    j++;
                }
                else if(hand_tmp->GetDeck()[i]->GetIsOnCombination() == false)
                {
                    if(hand_tmp->GetDeck()[i]->GetRank() > max_card->GetRank())
                    {
                        max_card = hand_tmp->GetDeck()[i];
                    }
                }

            }
            hand_->SetMaxCard(max_card);


            hand_tmp_deque.clear();
            delete hand_tmp;
        }


        for(int i = 0; i < hand.size(); i++)
        {
            if(hand[i]->GetMaxCard()->GetRank() == max_card->GetRank()
                && hand[i]->GetComboType() == max_combo)
            {
                players[i]->SetWin(true);
            }
            else
            {
                players[i]->SetWin(false);
            }
        }
    }
}




void GameManager::Play() {

}


void GameManager::Result() {

    int c = 0;

    for(int i = 0; i < countOfPlayers; i++)
    {
        if(players[i]->GetWin() == true)
        {
            c++;
        }
    }
    int winChip = table[0]->GetChip() / c;
    table[0]->AddChip(-table[0]->GetChip());
    int i = 0;
    for(Player* player : players)
    {
        if(player->GetWin() == true)
        {
            player->SetWin(false);
            player->AddChip(winChip);
            player->Print();
            std::cout << " win with combo: " << hand[i]->GetComboType() << "\n";
            i++;
        }
    }

}

//---------------------------------------------------------


int GameManager::GetCountOfPlayers() const{
    return countOfPlayers;
}