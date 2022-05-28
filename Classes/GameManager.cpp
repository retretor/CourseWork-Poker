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
        player->SetABet(c, table[0]);
        i++;
    }
}


void GameManager::Play() {

}


void GameManager::Result() {

}

//---------------------------------------------------------


int GameManager::GetCountOfPlayers() const{
    return countOfPlayers;
}