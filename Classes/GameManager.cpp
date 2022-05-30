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
    /*std::deque<Card::Ranks> ranks(7);
    std::deque<Card::Suits> suits(7);



    for(int i = 0; i < countOfPlayers; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            ranks[j] = hand[i]->GetDeck()[j]->GetRank();
            suits[j] = hand[i]->GetDeck()[j]->GetSuit();
        }
        std::sort(ranks.begin(), ranks.end());
        std::sort(suits.begin(), suits.end());


        //Is flush
        bool flush_ = false;
        bool pair_ = false;
        int straight = 0;
        std::string flush = "0000000";

        for(int p = 0; p < 4, !flush_; p++)
        {
            int c = 0;
            for(int j = 0; j < 7; j++)
            {
                if(suits[j] == p)
                {
                    c++;
                    flush[j] = 1;
                }
            }
            if(flush.find_last_of('1') < 4) flush_ = false;
        }

        //Is STRAIGHT
        for(int p = 0; p < 7; p++)
        {
            if(suits[p] == (suits[p + 1] + 1) && suits[p + 1] == (suits[p + 2] + 1) &&
               suits[p + 2] == (suits[p + 3] + 1) && suits[p + 3] == (suits[p + 4] + 1))
                straight = 1;
        }



        //Is Pair
        for(int p = 6; p > 0; p--)
        {
            if(suits[p] == suits[p - 1]) pair_ = true;
        }
    }





    ranks.clear();
    suits.clear();*/
    std::vector<std::string> combination(5);
    combination.resize(5);
    for(int i = 0; i < 5; i++)
    {
        combination[i].push_back('0');
        combination[i].push_back('R');
    }
    std::deque<Card::Ranks> ranks(7);
    std::deque<Card::Suits> suits(7);

    for(int i = 0; i < countOfPlayers; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            ranks[j] = hand[i]->GetDeck()[j]->GetRank();
            suits[j] = hand[i]->GetDeck()[j]->GetSuit();
        }

        //std::sort(ranks.begin(), ranks.end()); //-
        std::sort(suits.begin(), suits.end()); //-


        //Flush
        int pos_flush = -1;
        for(int j = 0; j < 3; j++)
        {
            if((suits[j] == (suits[j + 1]) && suits[j + 1] == (suits[j + 2]) &&
                suits[j + 2] == (suits[j + 3]) && suits[j + 3] == (suits[j + 4])))
            {
                for(int p = 0; p < 5; p++)
                {
                    combination[p][1] = 'A';
                }
                pos_flush++;
            }
        }
        int pos_straight = -1, pos_two_pair = -1,
        pos_pair = -1, pos_three = -1,
        pos_four = -1, pos_straight_flush = -1;
        if(pos_flush == -1)
        {
            for(int j = 0; j < 7; j++)
            {
                ranks[j] = hand[i]->GetDeck()[j]->GetRank();
                suits[j] = hand[i]->GetDeck()[j]->GetSuit();
            }
            std::sort(ranks.begin(), ranks.end()); //-
            //Straight
            for(int j = 0; j < 3; j++)
            {
                if(ranks[j] == (ranks[j + 1] + 1) && ranks[j + 1] == (ranks[j + 2] + 1) &&
                   ranks[j + 2] == (ranks[j + 3] + 1) && ranks[j + 3] == (ranks[j + 4] + 1))
                {
                    for(int p = 0; p < 5; p++)
                    {
                        combination[p][0] = static_cast<char>((p + 1));
                    }
                    pos_straight = j;
                }
            }
            //FOUR
            for(int j = 0; j < 4; j++)
            {
                if(ranks[j] == (ranks[j + 1]) && ranks[j + 1] == (ranks[j + 2]) &&
                   ranks[j + 2] == (ranks[j + 3]))
                {
                    for(int p = 0; p < 4; p++)
                    {
                        combination[p][0] = '1';
                    }
                    pos_four = j;
                    break;
                }
            }
            //THREE
            for(int j = 0; j < 5; j++)
            {
                if(ranks[j] == (ranks[j + 1]) && ranks[j + 1] == (ranks[j + 2]))
                {
                    pos_three += j;
                }
            }
            if(pos_three != -1)
                for(int p = 0; p < 3; p++)
                {
                    combination[p][0] = '1';
                }
            //PAIR

            for(int j = 0; j < 6; j++)
            {
                if(ranks[j] == ranks[j + 1])
                {
                    pos_pair += j;
                }
            }
            if(pos_pair != -1)
                for(int p = 0; p < 2; p++)
                {
                    combination[p][0] = '1';
                }
            //TWO PAIR
            for(int j = 0; j < 6; j++)
            {
                if(ranks[j] == ranks[j + 1] && pos_pair != j && pos_pair != j + 1 && pos_pair != j - 1)
                {
                    pos_two_pair += j;
                }
            }
            if(pos_two_pair != -1)
            {
                for(int p = 0; p < 2; p++)
                {
                    combination[p][0] = '1';
                }
                for(int p = 2; p < 4; p++)
                {
                    combination[p][0] = '2';
                }
            }
            //FullHouse
            if(pos_three != -1)
            {
                int pos_pair_in_house = -1;
                for(int j = 0; j < 6; j++)
                {
                    if(ranks[j] == ranks[j + 1] && ranks[j] != ranks[pos_three])
                    {
                        pos_pair_in_house++;
                    }
                }
                if(pos_pair_in_house != -1)
                {
                    for(int p = 0; p < 2; p++)
                    {
                        combination[p][0] = '1';
                    }
                    for(int p = 2; p < 5; p++)
                    {
                        combination[p][0] = '2';
                    }
                }
            }

            //HIGH
            int max = 0;
            if(pos_pair == -1 && pos_three == -1 && pos_two_pair == -1 && pos_straight == -1 &&
               pos_flush == -1 && pos_four == -1 && pos_straight_flush == -1)
            {
                for(int j = 0; j < 6; j++)
                {
                    if(ranks[j] > ranks[j + 1])
                    {
                        max = j;
                    }
                }
                combination[0][0] = '1';
            }
        }
        else
        {
            for(int j = pos_flush; j < 7; j++)
            {
                ranks[j] = hand[i]->GetCardRank(j);
            }

                std::sort(ranks.at(pos_flush), ranks.end()); //-

        }

/*

        //Straight
        int pos_straight = -1;
        for(int j = 0; j < 3; j++)
        {
            if(ranks[j] == (ranks[j + 1] + 1) && ranks[j + 1] == (ranks[j + 2] + 1) &&
                    ranks[j + 2] == (ranks[j + 3] + 1) && ranks[j + 3] == (ranks[j + 4] + 1))
            {
                for(int p = 0; p < 5; p++)
                {
                    combination[p][0] = static_cast<char>((p + 1));
                }
                pos_straight = j;
            }
        }
        //Straight flush
        int pos_straight_flush = -1;
        if(pos_flush != -1 && pos_straight == pos_flush)
        {
            pos_straight_flush = pos_flush;
        }
        //ROYAL_FLUSH
        if(pos_flush != -1 && pos_straight != -1 && combination[4][0] == '5' &&
           ranks[pos_straight + 4] == 14)
        {
            for(int p = 0; p < 5; p++)
            {
                combination[p][0] = static_cast<char>((p + 6));
            }
        }
        //FOUR
        int pos_four = -1;
        for(int j = 0; j < 4; j++)
        {
            if(ranks[j] == (ranks[j + 1]) && ranks[j + 1] == (ranks[j + 2]) &&
               ranks[j + 2] == (ranks[j + 3]))
            {
                for(int p = 0; p < 4; p++)
                {
                    combination[p][0] = '1';
                }
                pos_four = j;
                break;
            }
        }
        //THREE
        int pos_three = -1;
        for(int j = 0; j < 5; j++)
        {
            if(ranks[j] == (ranks[j + 1]) && ranks[j + 1] == (ranks[j + 2]))
            {
                pos_three += j;
            }
        }
        if(pos_three != -1)
            for(int p = 0; p < 3; p++)
            {
                combination[p][0] = '1';
            }
        //PAIR
        int pos_pair = -1;
        for(int j = 0; j < 6; j++)
        {
            if(ranks[j] == ranks[j + 1])
            {
                pos_pair += j;
            }
        }
        if(pos_pair != -1)
            for(int p = 0; p < 2; p++)
            {
                combination[p][0] = '1';
            }
        //TWO PAIR
        int pos_two_pair = -1;
        for(int j = 0; j < 6; j++)
        {
            if(ranks[j] == ranks[j + 1] && pos_pair != j && pos_pair != j + 1 && pos_pair != j - 1)
            {
                pos_two_pair += j;
            }
        }
        if(pos_two_pair != -1)
        {
            for(int p = 0; p < 2; p++)
            {
                combination[p][0] = '1';
            }
            for(int p = 2; p < 4; p++)
            {
                combination[p][0] = '2';
            }
        }
        //FullHouse
        if(pos_three != -1)
        {
            int pos_pair_in_house = -1;
            for(int j = 0; j < 6; j++)
            {
                if(ranks[j] == ranks[j + 1] && ranks[j] != ranks[pos_three])
                {
                    pos_pair_in_house++;
                }
            }
            if(pos_pair_in_house != -1)
            {
                for(int p = 0; p < 2; p++)
                {
                    combination[p][0] = '1';
                }
                for(int p = 2; p < 5; p++)
                {
                    combination[p][0] = '2';
                }
            }
        }

        //HIGH
        int max = 0;
        if(pos_pair == -1 && pos_three == -1 && pos_two_pair == -1 && pos_straight == -1 &&
           pos_flush == -1 && pos_four == -1 && pos_straight_flush == -1)
        {
            for(int j = 0; j < 6; j++)
            {
                if(ranks[j] > ranks[j + 1])
                {
                    max = j;
                }
            }
            combination[0][0] = '1';
        }

*/

        for(int p = 9; p >= 0; p--)
        {
            for(int k = 0; k < 5; k++)
            {
                if(combination[k] != Combinations_vector[p][k])
                {
                    break;
                }
                if(k == 4)
                {
                    players[i]->SetCombination(p);
                }
            }
        }


    }


    int m_combo_player = 0;
    std::deque<int> same_players_combo;
    for(int i = 1; i < countOfPlayers; i++)
    {
        if(players[i]->GetCombination() > players[i - 1]->GetCombination())
        {
            m_combo_player = i;
            same_players_combo.clear();
        }
        else if(players[i]->GetCombination() == players[i - 1]->GetCombination())
        {
            if(players[i]->GetWeight() > players[i - 1]->GetWeight())
            {
                m_combo_player = i;
                same_players_combo.clear();
            }
            else if(players[i]->GetWeight() < players[i - 1]->GetWeight())
            {
                m_combo_player = i - 1;
                same_players_combo.clear();
            }
            else
            {
                if(same_players_combo.empty())
                {
                    same_players_combo.push_back(i);
                    same_players_combo.push_back(i - 1);
                }
                else
                    same_players_combo.push_back(i);
            }
        }
    }
    if(same_players_combo.empty())
    {
        players[m_combo_player]->SetWin(true);
    }
    else
    {
        for(int i : same_players_combo)
        {
            players[i]->SetWin(true);
        }
    }
    same_players_combo.clear();
    ranks.clear();
    suits.clear();

}

void GameManager::Play() {

}


void GameManager::Result() {

    int c = 0;
    std::deque<Player*> same_players_combo;

    for(int i = 0; i < countOfPlayers; i++)
    {
        if(players[i]->GetWin() == true)
        {
            c++;
            same_players_combo.push_back(players[i]);
        }
    }
    int winChip = table[0]->GetChip() / c;
    table[0]->AddChip(-table[0]->GetChip());
    for(Player* player : same_players_combo)
    {
        player->AddChip(winChip);
        player->Print();
        std::cout << " win ";
    }


    same_players_combo.clear();
}

//---------------------------------------------------------


int GameManager::GetCountOfPlayers() const{
    return countOfPlayers;
}